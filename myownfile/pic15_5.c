/*************************************************************************
    > File Name: pic15_5.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月10日 星期五 20时04分55秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

int main(void)
{
	int n;
	int fd[2];
	pid_t pid;
	char line[MAXLINE];
	if(pipe(fd)<0)
		err_sys("pipe error");
	if((pid=fork())<0)
		err_sys("fork error");
	else
		if(pid>0)
		{
			close(fd[0]);
			write(fd[1],"hello world\n",12);
		}
		else
		{
			close(fd[1]);
			n = read(fd[0],line,MAXLINE);
			write(STDOUT_FILENO,line,n);
		}
	exit(0);
}
