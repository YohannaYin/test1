/*************************************************************************
    > File Name: forkDemo.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月13日 星期一 03时57分51秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

int globvar =88;
char buf[]="a write to stdout\n";
int main(void)
{
	int var;
	pid_t pid;
	var = 6;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
		err_sys("write error");
	printf("before fork\n");
	if((pid==fork())<0)
	{
		err_sys("fork error");
	}
	else if(pid == 0)
	{
		globvar++;
		var++;
		printf("glob=%d,var=%d\n",globvar,var);
	}
	else
		sleep(2);
	printf("pid=%ld,glob=%d,var=%d\n",(long)getpid(),globvar,var);
	_exit(0);
}
