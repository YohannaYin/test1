/*************************************************************************
    > File Name: pic10_23.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月10日 星期五 18时24分30秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

volatile sig_atomic_t quitflag;

static void sig_int(int signo)
{
	if(signo == SIGINT)
		printf("\ninterrupt\n");
	else 
		if(signo == SIGQUIT)
			quitflag = 1;
}
int main(void)
{
	sigset_t newmask,oldmask,zeromask;
	if(signal(SIGINT,sig_int)==SIG_ERR)
		err_sys("signal(SIGINT) error");
	if(signal(SIGQUIT,sig_int)==SIG_ERR)
		err_sys("signal(SIGQUIT) error");
	sigemptyset(&zeromask);
	sigemptyset(&newmask);
	sigaddset(&newmask,SIGQUIT);
	if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)<0)
		err_sys("SIG_BLOCK error");
	while(quitflag==0)
		sigsuspend(&zeromask);
	quitflag = 0;
	if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
		err_sys("SIG_SETMASK error");
	exit(0);
}
