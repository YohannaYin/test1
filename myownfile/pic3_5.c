/*************************************************************************
    > File Name: pic3_5.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月04日 星期六 15时23分02秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>
#define BUFFSIZE 4096
int main()
{
	int n;
	char buf[BUFFSIZE];
	while((n = read(STDIN_FILENO,buf,BUFFSIZE))>0)
		if(write(STDOUT_FILENO,buf,n)!=n)
			err_sys("write error");
	if(n<0)
		err_sys("read error");
	exit(0);
}
