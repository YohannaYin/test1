/*************************************************************************
    > File Name: pic4_12.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月05日 星期日 13时59分38秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

int main(void)
{
	struct stat statbuf;
	if(stat("foo",&statbuf)<0)
		err_sys("stat error for foo");
	if(chmod("foo",(statbuf.st_mode&~S_IXGRP)|S_ISGID)<0)
		err_sys("chmod error for foo");
	if(chmod("bar",S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)<0)
		err_sys("chmod error for foo");
	exit(0);
}
