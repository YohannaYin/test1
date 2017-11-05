/*************************************************************************
    > File Name: mycp_getc.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月04日 星期六 10时59分03秒
 ************************************************************************/

#include<stdio.h>
#include"apue.h"
#include"myerr.h"
int main()
{
	int c;
	while((c=getc(stdin))!=EOF)
		if(putc(c,stdout)==EOF)
			err_sys("output error");
		if(ferror(stdin))
			err_sys("input error");
		exit(0);
}
