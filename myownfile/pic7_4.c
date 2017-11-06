/*************************************************************************
    > File Name: pic7_4.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月06日 星期一 17时53分59秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

int main(int argc,char*argv[])
{
	int i;
	for(i = 0;i<argc;i++)
		printf("argv[%d]:%s\n",i,argv[i]);
	exit(0);
}
