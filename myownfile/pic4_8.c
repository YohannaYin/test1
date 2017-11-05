/*************************************************************************
    > File Name: pic4_8.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月04日 星期六 18时32分52秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<fcntl.h>
 
int main(int argc, char *argv[])
{
	if(argc!=2)
		err_quit("usag: pic4_8.out <pathname>");
	if(access(argv[1],R_OK)<0)
		err_ret("access error for %s",argv[1]);
	else 
		printf("read access OK\n");
	if(open(argv[1],O_RDONLY)<0)
		err_ret("open error for %s",argv[1]);
	else 
		printf("open for reading OK\n");
	exit(0);
}
