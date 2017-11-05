/*************************************************************************
    > File Name: pic4_23.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月05日 星期日 17时13分06秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

int main(void)
{
	if(chdir("/tmp")<0)
		err_sys("chdir failed");
	printf("chdir to /tmp succeeded\n");
	exit(0);
}
