/*************************************************************************
    > File Name: msg.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月10日 星期五 21时55分41秒
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
	char mtext[MSGSZ];
};
int main () {
	int msgid;
	key_t key;
	struct msgbuf sbuf,rbuf;
	key=4587;
if ((msgid=msgget(key,IPC_CREAT|0666))<0) {

	printf("msgget");
	exit(1);
}
if (msgrcv(msgid,&rbuf,MSGSZ,0,0)<0) {

	printf("msgrcv");
	exit(1);
}
sbuf.mtype=2;
sprintf(sbuf.mtext,"I received the message.");
if (msgsnd(msgid,&sbuf,strlen(sbuf.mtext)+1,0)<0) {

	printf("msgsnd");
	exit(1);
}
exit(0);
}
