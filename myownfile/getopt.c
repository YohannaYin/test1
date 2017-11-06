/*************************************************************************
    > File Name: getopt.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月06日 星期一 18时01分32秒
	>此程序书本上没有，老师补充的
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<unistd.h>

#include<stdlib.h>

int main(int argc,char *argv[])
{
	int flags,opt;
	int nsecs,tfnd;
	nsecs = 0;
	tfnd = 0;
	flags = 0;
	while((opt = getopt(argc,argv,"nt:"))!=-1)
	{
		switch(opt)
		{
			case 'n':
				flags = 1;
				break;
			case 't':
				nsecs = atoi(optarg);
				tfnd = 1;
				break;
			default:
				fprintf(stderr,"Usage: %s [-t nsecs] [-n] name\n",argv[0]);
				exit(EXIT_FAILURE);
		}
	}
	printf("name argument = %s\n",argv[optind]);
	exit(EXIT_SUCCESS);
}
