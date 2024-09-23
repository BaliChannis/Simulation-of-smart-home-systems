#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MQTTClient.h"
#include <pthread.h>
#include "mqtt.h"
#include "parse_config.h"
#include "cJSON.h"
#define ADDRESS "tcp://192.168.177.250:1883" //根据 MQTT 实际主机地址调整
#define CLIENTID_PUB "ExampleClientPub"
#define CLIENTID_SUB "ExampleClientSub"
#define QOS 1
#define TIMEOUT 10000L
//#define PUB_TOPIC "ScratchToSoftWare" //可根据虚拟仿真软件网关的设置对应调整
#define MQTT_SUB_TOPIC "1662600472837/SoftWareToScratch" //可根据虚拟仿真软件网关的设置对应调整
#define NUM_THREADS 2
#define FAN_OFF "{'fan':false}"
#define FAN_ON "{'fan':true}"
#define ILL "light"
#define TEM "tem"


MQTTClient client;
int fan_state = 0;
volatile MQTTClient_deliveryToken deliveredtoken;
//定义一个数组用于接受订阅到的消息
char virtual_data[1024] = {0};
char *pend;
float ill = 0;
float transfor_virtual_data()
{
//	printf("器件的状态数值为：:%s\n", virtual_data);
	//这里根据虚拟仿真软件定的协议解析出具体哪个寄存器的变化，然后上报给QT客户端
	cJSON *root = NULL;
	cJSON *item = NULL;//cjson对象
	//把订阅到的消息进行解析，并且让指针root指向存放解析后的空间的首地址
	root = cJSON_Parse(virtual_data);
	if (!root)
	{
		printf("parse err\n");
		return -1;
	}
	item = cJSON_GetObjectItem(root, ILL);
	if(NULL != item)  //代表是光照传感器
	{
		//把获取到的光照强度由字符串类型转换成浮点型并且赋值给ill变量
		ill = item->valuedouble;
	}
}
float get_virtual_env()
{
	return ill;
}
void delivered(void *context, MQTTClient_deliveryToken dt)
{
	printf("Message with token value %d delivery confirmed\n", dt);
	deliveredtoken = dt;
}
int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
	//对接收消息的数组进行清空操作
	memset(virtual_data,0,sizeof(virtual_data));
	//把订阅到的消息存放在数组中
	memcpy(virtual_data,message->payload,message->payloadlen);
	//对接收到的消息同过cJSON库中的函数进行解析，把解析后的数据传回main函数
	transfor_virtual_data();
	//对最开始存放订阅的消息的容器进行释放资源
	MQTTClient_freeMessage(&message);
	MQTTClient_free(topicName);
	return 1;
}
void connlost(void *context, char *cause)
{
	printf("\nConnection lost\n");
	printf(" cause: %s\n", cause);
}

int mqtt_publish(const char *topic, char *msg)
{
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
	MQTTClient_deliveryToken token;
    pubmsg.payload = msg;
    pubmsg.payloadlen = (int)strlen(msg);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;
    return MQTTClient_publishMessage(client, topic, &pubmsg, &token);
}

void exit_mqtt()
{
	int rc;
	if ((rc = MQTTClient_disconnect(client, 10000)) != MQTTCLIENT_SUCCESS)
		printf("Failed to disconnect, return code %d\n", rc);

	MQTTClient_destroy(&client);
}
int mqtt_subscribe(const char *topic)
{
    return MQTTClient_subscribe(client, topic, QOS);
}

//mqtt的初始化函数
int mqtt_init()
{
	//定义了一个数组存放我们的配置信息
	char uri[128] = {0};
	//对smartHome.conf中的配置进行解析
    GetProfileString(DEF_CONF_FILE,"mqtt","uri",uri);	
	//定义了一个结构体变量用于客户端和服务器进行连接
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    int rc;
	//创建一个客户端对象client用于和服务器进行连接
    //MQTTClient_create(&client, ADDRESS, CLIENTID_PUB, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    MQTTClient_create(&client, uri, CLIENTID_PUB, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
//定义回调函数，用于断开连接时、数据到达时、数据未到达时做不同的逻辑处理
//函数的参数都是函数指针，指向其他的函数
    MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);
	//建立与服务器的连接

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        return -1;
    }
    printf("mqtt connect success\n");

    return 0;
}
