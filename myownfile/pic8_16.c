/*************************************************************************
    > File Name: pic8_16.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月08日 星期三 11时30分53秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<sys/types.h>

#include<sys/wait.h>

char *env_init[] = {
	"USER= unknown","PATH=/tmp",NULL};
int main(void)
{
	pid_t pid;
	if((pid = fork())<0)
		err_sys("fork error");
	else 
		if(pid == 0)
		{
			if(execle("/home/yh/bin/echoall","echoall","myarg1","MY ARG2",(char*) 0,env_init)<0)
				err_sys("execle error");
		}
	if(waitpid(pid,NULL,0)<0)
		err_sys("wait error");
	if((pid = fork())<0)
		err_sys("fork error");
	else
		if(pid==0)
		{
			if(execlp("echoall","echoall","only 1 arg",(char*) 0)<0)
				err_sys("execlp error");

		}
	exit(0);
}
