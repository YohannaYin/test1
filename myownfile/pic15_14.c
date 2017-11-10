/*************************************************************************
    > File Name: pic15_14.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月10日 星期五 21时17分38秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<ctype.h>
int main(void) {

	int	c;
	while ( (c = getchar()) != EOF) {

		if (isupper(c))
			c = tolower(c);
		if (putchar(c) == EOF)
			err_sys("output error");
		if (c == '\n')
			fflush(stdout);
	}
	exit(0);
	}
