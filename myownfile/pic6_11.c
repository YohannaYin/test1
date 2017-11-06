/*************************************************************************
    > File Name: pic6_11.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月06日 星期一 16时25分10秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<time.h>

#include<stdlib.h>

int main(void)
{
	time_t t;
	struct tm *tmp;
	char buf1[16];
	char buf2[64];
	time(&t);
	tmp = localtime(&t);
	if(strftime(buf1,16,"time and date:%r,%a,%b,%Y",tmp)==0)
		printf("buffer length 16 is too small\n");
	else
		printf("%s\n",buf1);
	if(strftime(buf2,64,"time and date:%r,%a,%b,%d,%Y",tmp)==0)
		printf("buffer length 64 is too small\n");
	else 
		printf("%s\n",buf2);
	exit(0);
}
