/*************************************************************************
    > File Name: pic3_1.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月04日 星期六 14时53分12秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

int main()
{

	if(lseek(STDIN_FILENO,0,SEEK_CUR)==-1)
		printf("cannot seek\n");
	else
		printf("seek ok\n");
	exit(0);
}
