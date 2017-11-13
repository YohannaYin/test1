/*************************************************************************
    > File Name: homework2.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月12日 星期日 21时31分21秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<string.h>
#include<unistd.h>

int file_size=4096;

int main(int argc,char *argv[])
{
	int opt;
	int i;
	while((opt=getopt(argc,argv,"s:"))!=-1)
	{
		switch(opt){
			case 's':file_size=atoi(optarg);
					 break;
			default:
					 err_quit("usage: createFile [-s filesize]filename.\n");
					 break;
		}
	}
		FILE *fp=fopen(argv[optind],"w");
		if(fp==NULL)
			err_quit("createFile %s failed\n",argv[optind]);
		for(i=0;i<file_size;i++)
			fputc('c',fp);
		return 0;
}
