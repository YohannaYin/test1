/*************************************************************************
    > File Name: pic8_8.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月07日 星期二 21时53分19秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<sys/wait.h>

int main(void) {

	pid_t
		pid;
	if ( (pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0) {

		/* first child */
		if ( (pid = fork()) < 0)
			err_sys("fork error");
		else if (pid > 0) /* parent from second fork */
			exit(0);
		/* == first child
		 * */
		/* second child; parent becomes init */
		sleep(2);
		printf("second child, parent pid = %d\n", getppid());
		exit(0);
	}
	if (waitpid(pid, NULL, 0) != pid)/* wait for first child */
		err_sys("waitpid error");
	/* We're the parent (the original process) */
		exit(0);
}
