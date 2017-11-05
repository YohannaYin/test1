/*************************************************************************
    > File Name: pic4_16.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月05日 星期日 14时35分24秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<fcntl.h>

int main(void) {

	if (open("tempfile", O_RDWR) < 0)
		err_sys("open error");
	if (unlink("tempfile") < 0)
		err_sys("unlink error");
	printf("file unlinked\n");
	sleep(15);
	printf("done\n");
	exit(0);
}
