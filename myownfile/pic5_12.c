/*************************************************************************
    > File Name: pic5_12.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月06日 星期一 15时30分36秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

int main(void)
{
	char name[L_tmpnam],line[MAXLINE];
	FILE *fp;
	printf("%s\n",tmpnam(NULL));
	tmpnam(name);
	printf("%s\n",name);
	if((fp=tmpfile())==NULL)
		err_sys("tmpfile error");
	fputs("one line of output\n",fp);
	rewind(fp);
	if(fgets(line,sizeof(line),fp)==NULL)
		err_sys("fgets error");
	fputs(line,stdout);
	exit(0);
}
