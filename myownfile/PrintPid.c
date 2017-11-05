/*************************************************************************
    > File Name: PrintPid.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月04日 星期六 11时14分01秒
 ************************************************************************/

#include<stdio.h>
#include"apue.h"
int main(void)
{
	printf("hello world from process ID %ld\n",(long)getpid());
	exit(0);
}
