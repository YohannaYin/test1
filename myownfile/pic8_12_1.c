/*************************************************************************
    > File Name: pic8_12_1.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月08日 星期三 10时52分10秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<apue.h>

#include<stdio.h>


static void charatatime(char *);
int main(void)
{
	pid_t pid;
	TELL_WAIT();
	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid==0)
	{
		WAIT_PARENT();
		charatatime("output from child\n");
	}
	else
	{
		charatatime("output from parent\n");
		TELL_CHILD(pid);
	}
	exit(0);
}

static void charatatime(char *str)
{
	char *ptr;
	int c;
	setbuf(stdout,NULL);
	for(ptr = str;(c=*ptr++)!=0;)
		putc(c,stdout);
}
