/*************************************************************************
    > File Name: pic5_5.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月06日 星期一 10时35分54秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#define MAXLINE 4096
int main(void)
{
	char buf[MAXLINE];
	while(fgets(buf,MAXLINE,stdin)!=NULL)
		if(fputs(buf,stdout)==EOF)
			err_sys("output error");
	if(ferror(stdin))
		err_sys("input error");
	exit(0);
}
