/*************************************************************************
    > File Name: sendnum.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月14日 星期二 21时31分08秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#define MSGSZ 128
struct msgbuf {
	long mtype;
	char mtext;
};
int main (int argc,char *argv[]) {
	int msgid;
	key_t key;
	struct msgbuf sbuf,rbuf;
	key=4587;
if ((msgid=msgget(key,0666))<0) {
	printf("msgget");
	exit(1);
}
sbuf.mtype=1;
sbuf.mtext=&argv[2];
if (msgsnd(msgid,&sbuf,strlen(sbuf.mtext)+1,0))//发送求和的值
{
		printf("msgsnd");
		exit(1);
		}
		if (msgrcv(msgid,&rbuf,MSGSZ,2,0)<0) {
		printf("msgrcv");
		exit(1);
		}
		printf("%s\n",rbuf.mtext);
		exit(0);
}
