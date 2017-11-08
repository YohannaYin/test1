/*************************************************************************
    > File Name: pic8_30.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月08日 星期三 15时33分00秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<sys/times.h>

#include<sys/wait.h>

#include<sys/types.h>
static void pr_times(clock_t,struct tms*,struct tms*);
static void do_cmd(char *);

void pr_exit (int status) {

	if (WIFEXITED(status))
		printf("normal termination, exit status = %d\n",
				WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal termination, signal number = %d%s\n",
				WTERMSIG(status),
#ifdef	WCOREDUMP
				WCOREDUMP(status) ? " (core file generated)" : "");
#else
	"");
#endif
	else if (WIFSTOPPED(status))
		printf("child stopped, signal number = %d\n",
				WSTOPSIG(status));
}


int main(int argc,char *argv[])
{
	int i;
	for(i=1;i<argc;i++)
		do_cmd(argv[i]);
	exit(0);
}
static void do_cmd(char *cmd)
{
	struct tms tmsstart,tmsend;
	clock_t start,end;
	int status;
	fprintf(stderr,"\ncommand:%s\n",cmd);
	if((start=times(&tmsstart))==-1)
		err_sys("time error");
	if((status = system(cmd))<0)
		err_sys("system() error");
	if((end=times(&tmsend))==-1)
		err_sys("time error");
	pr_times(end-start,&tmsstart,&tmsend);
	pr_exit(status);
}

static void pr_times(clock_t real, struct tms *tmsstart, struct tms *tmsend)
{

	static long	clktck = 0;
	if (clktck == 0) /* fetch clock ticks per second first time */
		if ( (clktck = sysconf(_SC_CLK_TCK)) < 0)
			err_sys("sysconf error");
	fprintf(stderr, " real: %7.2f\n", real / (double) clktck);
	fprintf(stderr, " user: %7.2f\n",
			(tmsend->tms_utime - tmsstart->tms_utime) / (double) clktck);
	fprintf(stderr, " sys: %7.2f\n",
			(tmsend->tms_stime - tmsstart->tms_stime) / (double) clktck);
	fprintf(stderr, " child user: %7.2f\n",
			(tmsend->tms_cutime - tmsstart->tms_cutime) / (double) clktck);
	fprintf(stderr, " child sys: %7.2f\n",
			(tmsend->tms_cstime - tmsstart->tms_cstime) / (double) clktck);
}

