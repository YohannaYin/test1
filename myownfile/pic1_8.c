/*************************************************************************
    > File Name: pic1_8.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月04日 星期六 13时52分47秒
 ************************************************************************/

#include<stdio.h>
#include"apue.h"
#include<errno.h>
int main(int argc,char *argv[])
{
	fprintf(stderr,"EACCES: %s\n",strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);
	exit(0);
}

