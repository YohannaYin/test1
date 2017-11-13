
/*************************************************************************
    > File Name: pic8_1.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月07日 星期二 20时22分08秒
	>将exit(0)改为_exit
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

int globvar = 6;
char buf[] = "a write to stdout\n";
int main(void)
{
	int var;
	pid_t pid;
	var = 88;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
		err_sys("write error");
	printf("before fork\n");
	if((pid = fork())<0)
	{
		err_sys("fork error");

	}
	else
		if(pid == 0)

		{
			globvar++;
			var++;
		}
		else 
		{
			sleep(2);
		}
	printf("pid = %ld,glob = %d,var = %d\n",(long)getpid(),globvar,var);
	_exit(0);
}
