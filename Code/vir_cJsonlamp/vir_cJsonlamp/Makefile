#指定我们的编译器为gcc编译器
CC=gcc
#指定编译的时候加的参数，-c是让我们的文件编译生成.o文件
#-g是让我们在编译的时候生成调试信息，方便于进行GDB调试
#-m32是让我们在64位的计算机中编译生成32位机器中的可执行文件
AFLAGS= -c -g -m32
#最后一步编译过程中加的参数
#-lpthread是让我们编译的时候链接线程库进代码
#-lpaho-mqtt3c -lrt -lm 的作用是让我们编译的时候链接mqtt库进程序
LDFLAGS= -lpthread -m32 -lpaho-mqtt3c -lrt -lm

#编译生成可执行文件的时候依赖的文件
OBJS=main.o  mqtt.o parse_config.o cJSON.o

#生成可执行文件的编译步骤，$@就是我们的目标，$^是我们的依赖,smart_home就是我们生成的可执行文件，此时是可以手动修改名字
smart_home:$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

#通过我们项目工程中的.c文件生成我们需要的依赖文件
$(OBJS):%.o:%.c
	$(CC) $(AFLAGS) $< -o $@

#伪目标
.PHONY:clean lib
#删除所有的.o文件和可执行文件
clean:
	rm *.o smart_home

#最下面3行不用管
lib:
	ar crs libmylib.a 
#gcc main.c -o server -L.. -lmylib -lpthread
