/*************************************************************************
    > File Name: pic10_14.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月08日 星期三 20时26分39秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<errno.h>

void pr_mask(const char *str)
{
sigset_t
	sigset;
int
	errno_save;
errno_save = errno;
/* we can be called by signal handlers */
if (sigprocmask(0, NULL, &sigset) < 0)
	err_sys("sigprocmask error");
printf("%s", str);
if (sigismember(&sigset, SIGINT))
	printf("SIGINT ");
if (sigismember(&sigset, SIGQUIT))
	printf("SIGQUIT ");
if (sigismember(&sigset, SIGUSR1))
	printf("SIGUSR1 ");
if (sigismember(&sigset, SIGALRM))
	printf("SIGALRM ");
/* remaining signals can go here */
printf("\n");
errno = errno_save;
}
