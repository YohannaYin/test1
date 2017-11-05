/*************************************************************************
    > File Name: pic1_9.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月04日 星期六 14时09分52秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<sys/wait.h>
int main()

{
	printf("uid = %d,gid = %d\n",getuid(),getpid());
	exit(0);
}
