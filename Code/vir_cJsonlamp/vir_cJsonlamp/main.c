#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mqtt.h"
#include "parse_config.h"
//宏定义，光照的阈值
#define ILL_OVER_THROUGH      30001
#define ILL_UNDER_THROUGH     30000
//宏定义，消息的订阅和发布主题
#define CTRL_PUB_TOPIC "1662600472837/ScratchToSoftWare"
#define SUB_TOPIC "1662600472837/SoftWareToScratch"
//灯的打开和关闭的状态
#define LAMP_ON    "{\"lamp\":true}"
#define LAMP_OFF   "{\"lamp\":false}"
#define ALARM_ON    "{\"alarm\":true}"
#define ALARM_OFF   "{\"alarm\":false}"
//光照数据的Json格式
#define LIGHT   "{\"light\":%f}"

int main(int argc, char *argv[])
{
	int ret;
	char data[1024] = {0};
	//定义一个浮点型数据去接收订阅到的光照强度的数值
	float light = 0;
	//mqtt的初始化
	 if (0 != mqtt_init())
    {
        puts("init_mqtt err");
        return -1;
    }
	//订阅消息
    if(mqtt_subscribe(SUB_TOPIC) < 0)
    {
        printf("sub err");
        return -1;
    }

	while(1)
	{
		//3秒进行一次逻辑的处理
		sleep(3);
		//把解析后的数据传到main函数
		light = get_virtual_env();
		//逻辑处理
		if(light >= ILL_OVER_THROUGH)
		{
			//发布关灯消息
			mqtt_publish(CTRL_PUB_TOPIC, LAMP_OFF);
			mqtt_publish(CTRL_PUB_TOPIC, ALARM_ON);
			printf("光照强度过大，关灯，打开报警器\n");
		}
		else if(light <= ILL_UNDER_THROUGH)
		{
			//发布开灯消息
			mqtt_publish(CTRL_PUB_TOPIC, LAMP_ON);
			mqtt_publish(CTRL_PUB_TOPIC, ALARM_OFF);
			printf("光照强度过低，开灯,关闭报警器\n");
		}
		else
		{	
		}
		printf("光照强度的数值为:%f \n", light);
	}

	exit_mqtt();

	return 0;
}
