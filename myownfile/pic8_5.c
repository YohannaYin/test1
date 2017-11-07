/*************************************************************************
    > File Name: pic8_5.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月07日 星期二 21时33分46秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<sys/wait.h>

void pr_exit(int status)
{
	if(WIFEXITED(status))
		printf("normal termination,exit status = %d\n",WEXITSTATUS(status));
	else
		if(WIFSIGNALED(status))
			printf("abnormal termination,signal number =%d%s\n",WTERMSIG(status),
#ifdef WCOREDUMP
					WCOREDUMP(status) ? "(core file generated)":"");
#else
	"");
#endif
		else if(WIFSTOPPED(status))
			printf("child stopped,signal number = %d\n",WSTOPSIG(status));
}

int main(void) {

	pid_t
		pid;
	int
		status;
	if ( (pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		/* child */
		exit(7);
	if (wait(&status) != pid) /* wait for child */
		err_sys("wait error");
	pr_exit(status);
	/* and print its status */
	if ( (pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		abort();
	/* child */
	/* generates SIGABRT */
	if (wait(&status) != pid) /* wait for child */
		err_sys("wait error");
		pr_exit(status);
	/* and print its status */
	if ( (pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		/* child */
		status /= 0; /* divide by 0 generates SIGFPE */
	if (wait(&status) != pid)
		/* wait for child */
		err_sys("wait error");
		pr_exit(status);
	/* and print its status */
	exit(0);
}
