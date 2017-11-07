/*************************************************************************
    > File Name: pic8_12.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月07日 星期二 21时57分14秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<sys/types.h>

static void charatatime(char*);
int main(void)
{
	pid_t pid;
	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid==0)
	{
		charatatime("output from child\n");
	}
	else 
		charatatime("output from parent\n");
	exit(0);
}
static void charatatime(char *str)
{
	char *ptr;
	int c;
	setbuf(stdout,NULL);
	for(ptr = str;c=*ptr++;)
		putc(c,stdout);
}
