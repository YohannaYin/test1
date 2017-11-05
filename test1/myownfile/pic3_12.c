/*************************************************************************
    > File Name: pic3_12.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月04日 星期六 16时48分32秒
	>对于一个文件描述符设置一个或多个文件状态标志函数
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>
#include<fcntl.h>
void set_fl(int fd, int flags) /* flags are file status flags to turn on */
{

	int
		val;
	if ( (val = fcntl(fd, F_GETFL, 0)) < 0)
		err_sys("fcntl F_GETFL error");
	val |= flags;
	/* turn on flags */
	if (fcntl(fd, F_SETFL, val) < 0)
		err_sys("fcntl F_SETFL error");
}
