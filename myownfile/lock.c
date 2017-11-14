/*************************************************************************
    > File Name: lock.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月14日 星期二 13时05分36秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>
volatile sig_atomic_t quitflag;
 static void sig_int(int signo)
{
	if(signo==SIGINT)
		printf("\ninterrupt\n");
}

int main(void)
{
	if(signal(SIGINT,sig_int)==SIG_ERR)
		err_sys("signal (SIGINT) error");
	char c[1024];
	sigset_t newmask,oldmask;
	while(scanf("%s",c)==1)
	{
		if(strcmp(c,"pw1234")==0)
		{
			printf("login success!");
		}
		else
		{
		if(signal(SIGINT,sig_int)==SIG_ERR)
			err_sys("signal (SIGINT) error");
		sigemptyset(&newmask);
		sigaddset(&newmask,SIGINT);
		if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)<0)
			err_sys("SIG_BLOCK error");
		sleep(5);
		}
	exit(0);
}
}
