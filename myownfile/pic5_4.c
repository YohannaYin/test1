/*************************************************************************
    > File Name: pic5_4.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月06日 星期一 10时32分22秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

int main()
{
	int c;
	while((c = getc(stdin))!=EOF)
		if(putc(c,stdout)==EOF)
			err_sys("output error");
	if(ferror(stdin))
		err_sys("input error");
}
