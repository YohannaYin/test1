/*************************************************************************
    > File Name: pic5_52.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月06日 星期一 10时48分35秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#define MAXLINE1 4096
int main()
{
	char buf[MAXLINE1];
	while((gets(buf))!=NULL)
		/*此处会报错，因为gets不是以NULL和\n结尾的，故无法判断其结束*/
		if(puts(buf)==EOF)
			/*puts的结尾处会多加一个\n,也不便于判断，故puts和gets都不用*/
			err_sys("output error");
	if(ferror(stdin))
		err_sys("input error");
	exit(0);
}
