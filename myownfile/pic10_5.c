/*************************************************************************
    > File Name: pic10_5.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月08日 星期三 16时26分52秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<pwd.h>

static void my_alarm(int signo)
{
	struct passwd *rootptr;
	printf("in signal handler\n");
	if((rootptr = getpwnam("root"))==NULL)
		err_sys("getpwnam(root) error");
	alarm(1);
}
int main(void)
{
	struct passwd *ptr;
	signal(SIGALRM,my_alarm);
	alarm(1);
	for(;;)
	{
		if((ptr = getpwnam("yh"))==NULL)
			err_sys("getpwnam error");
		if(strcmp(ptr->pw_name,"yh")!=0)
			printf("return value corrupted!,pw_name=%s\n",ptr->pw_name);
	}
}
