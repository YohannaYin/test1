/*************************************************************************
    > File Name: pic10_2.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月08日 星期三 16时03分24秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<signal.h>

static void sig_usr(int);

int main(void)
{
	if(signal(SIGUSR1,sig_usr)==SIG_ERR)
		err_sys("can't catch SIGUSR1");
	if(signal(SIGUSR2,sig_usr)==SIG_ERR)
		err_sys("can't catch SIGUSR2");
	for(;;)
		pause();
}
static void sig_usr(int signo)
{
	if(signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if(signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else 
		err_dump("received signal %d\n",signo);
}
