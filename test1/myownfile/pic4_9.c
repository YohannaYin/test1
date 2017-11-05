/*************************************************************************
    > File Name: pic4_9.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月04日 星期六 19时02分25秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<fcntl.h>

#define	RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
int main()
	{
		umask(0);
		if(creat("foo",RWRWRW)<0)
			err_sys("create error for foo");
		umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
			if(creat("bar",RWRWRW)<0)
				err_sys("create error for bar");
		exit(0);
	}
