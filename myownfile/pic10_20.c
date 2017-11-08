/*************************************************************************
    > File Name: pic10_20.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月08日 星期三 21时10分12秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<signal.h>

#include<setjmp.h>

#include<time.h>

static void sig_usr1(int),sig_alrm(int);
static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjump;

void pr_mask(const char *str) {

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

int main(void)
{
	if(signal(SIGUSR1,sig_usr1)==SIG_ERR)
		err_sys("signal(SIGUSR1) error");
	if(signal(SIGALRM,sig_alrm)==SIG_ERR)
		err_sys("signal(SIGALRM) error");
	pr_mask("starting main: ");
	if(sigsetjmp(jmpbuf,1))
	{
		pr_mask("ending main; ");
		exit(0);
	}
	canjump = 1;
	for(;;)
		pause();
}
static void sig_usr1(int signo)
{
	time_t starttime;
	if(canjump==0)
		return ;
	pr_mask("starting sigusr1: ");
	alarm(3);
	starttime = time(NULL);
	for(;;)
		if(time(NULL)>starttime + 5)
			break;
	pr_mask("finishing sig_usr1: ");
	canjump = 0;
	siglongjmp(jmpbuf,1);
}
static void sig_alrm(int signo)
{
	pr_mask("in sig_alrm: ");
	return;
}

