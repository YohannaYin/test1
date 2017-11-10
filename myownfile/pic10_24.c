/*************************************************************************
    > File Name: pic10_24.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月10日 星期五 19时25分10秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

static volatile sig_atomic_t sigflag;
static sigset_t newmask,oldmask,zeromask;
static void sig_usr(int signo)
{
	sigflag =1;
}
void TELL_WAIT(void)
{
	if(signal(SIGUSR1,sig_usr)==SIG_ERR)
		err_sys("signal(SIGUSR1) error");
	if(signal(SIGUSR2,sig_usr)==SIG_ERR)
		err_sys("")
}
