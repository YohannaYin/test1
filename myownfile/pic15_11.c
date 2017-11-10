/*************************************************************************
    > File Name: pic15_11.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月10日 星期五 20时54分31秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<sys/wait.h>
#define PAGER "${PAGER:-more}" /* environment variable, or default */
int main(int argc, char *argv[]) {

	char	line[MAXLINE];
	FILE	*fpin, *fpout;
	if (argc != 2)
		err_quit("usage: a.out <pathname>");
	if ( (fpin = fopen(argv[1], "r")) == NULL)
		err_sys("can't open %s", argv[1]);
	if ( (fpout = popen(PAGER, "w")) == NULL)
		err_sys("popen error");
	/* copy argv[1] to pager */
	while (fgets(line, MAXLINE, fpin) != NULL) {

		if (fputs(line, fpout) == EOF)
			err_sys("fputs error to pipe");
	}
	if (ferror(fpin))
		err_sys("fgets error");
	if (pclose(fpout) == -1)
		err_sys("pclose error");
	exit(0);
}
