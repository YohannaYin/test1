/*************************************************************************
    > File Name: pic10_7.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月08日 星期三 16时54分00秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<signal.h>

#include<unistd.h>

static void sig_alrm(int signo)
{

}
unsigned int sleep1(unsigned int seconds)
{
	if(signal(SIGALRM,sig_alrm)==SIG_ERR)
		return(seconds);
	alarm(seconds);
	pause();
	return(alarm(0));
}
