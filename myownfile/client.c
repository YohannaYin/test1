/*************************************************************************
    > File Name: client.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月14日 星期二 20时29分37秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

int main(int argc,char *argv[])
{
	if(argc!=3)
		err_sys("command error;");
	}struct msgbuf {


			long mtype;
				char mtext[MSGSZ];
	};
int main() 
{
		int msgid;
		key_t key;
		struct msgbuf sbuf,rbuf;
		key=4587;
		if ((msgid=msgget(key,0666))<0) {
			printf("msgget");
			exit(1);									}
			sbuf.mtype=1;

								sprintf(sbuf.mtext,"Did you get the Message ?");
									if(msgsnd(msgid,&sbuf,strlen(sbuf.mtext)+1,0)) {

													printf("msgsnd");
																exit(1);
																			}
												if (msgrcv(msgid,&rbuf,MSGSZ,2,0)<0) {

																printf("msgrcv");
																			exit(1);
																						}
															printf("%s\n",rbuf.mtext);
																		exit(0);
}"")"")
												}"")
									}"")"")
						}
}
	
