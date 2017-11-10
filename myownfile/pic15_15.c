/*************************************************************************
    > File Name: pic15_15.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月10日 星期五 21时12分53秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<ctype.h>

#include <sys/wait.h>
int main(void) {

	char line[MAXLINE];
	FILE *fpin;
	if ( (fpin = popen("myuclc", "r")) == NULL)
		err_sys("popen error");
	for ( ; ; ) {

		fputs("prompt> ", stdout);
		fflush(stdout);
		if (fgets(line, MAXLINE, fpin) == NULL)
			break;
		if (fputs(line, stdout) == EOF)
			err_sys("fputs error to pipe");
	}
	if (pclose(fpin) == -1) err_sys("pclose error");
	putchar('\n');
	exit(0);
}
