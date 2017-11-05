/*************************************************************************
    > File Name: mycp.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2017年11月03日 星期五 21时48分58秒
 ************************************************************************/

#include<stdio.h>
#include"apue.h"
#include<myerr.h>
#define BUFFSIZE 4096
int main()
{
	int n;
	char buf[BUFFSIZE];
	while((n=read(STDIN_FILENO,buf,BUFFSIZE))>0)
	{
		if(write(STDOUT_FILENO,buf,n)!=n)
			err_sys("write error");
		if(n<0)
			err_sys("read error");
	}
	exit(0);
}
