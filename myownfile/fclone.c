/*************************************************************************
    > File Name: fclone.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月12日 星期日 20时14分49秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<fcntl.h>

#include<unistd.h>

#define BUFFSIZE 4096
int main(int argc,char *argv[])
{
	int fd1,fd2;
	int n;
	char buf[BUFFSIZE];
	struct stat statbuf;
	struct timespec times[2];
	if((fd1 = open(argv[1],O_RDWR))<0)
		err_ret("%s:open error",argv[1]);
	if((fd2 = open(argv[2],O_RDWR|O_CREAT|O_TRUNC,FILE_MODE))<0)
		err_ret("%s:creat error",argv[2]);
	while((n=read(fd1,buf,BUFFSIZE))>0)
		if(write(fd2,buf,n)!=n)
			err_sys("write error");
	if(n<0)
		err_sys("read error");
	close(fd1);
	if(stat(argv[1],&statbuf)<0)
		err_ret("%s: stat error",argv[1]);
	times[0]=statbuf.st_atim;
	times[1]=statbuf.st_mtim;
	if(futimens(fd2,times)<0)
		err_ret("%s:creat error",argv[2]);
	close(fd2);
	exit(0);
}
