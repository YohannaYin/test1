/*************************************************************************
    > File Name: pic8_3_1.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月07日 星期二 21时02分25秒
	>将_exit(0)改为exit(0);
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include <unistd.h>

#include<stdlib.h>

#include<sys/types.h>

#include <unistd.h>
int glob = 6;
int main(void)
{
	int var;
	pid_t pid;
	var =88;
	printf("before vfork\n");
	if((pid = vfork())<0)
		err_sys("vfork error");
	else if(pid == 0)
	{
		glob++;
		var++;
		exit(0);
	}
	printf("pid = %d,glob = %d,var = %d\n",getpid(),glob,var);
	exit(0);
}
