/*************************************************************************
    > File Name: pic5_11.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月06日 星期一 14时56分41秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

int buffer_size(FILE *fp);
void
pr_stdio(const char *, FILE *);
int
main(void)
{

	FILE *fp;
	fputs("enter any character\n", stdout);
	if (getchar() == EOF)
		err_sys("getchar error");
	fputs("one line to standard error\n", stderr);
	pr_stdio("stdin", stdin);
	pr_stdio("stdout", stdout);
	pr_stdio("stderr", stderr);
if ( (fp = fopen("/etc/motd", "r")) == NULL)
	err_sys("fopen error");
if (getc(fp) == EOF)
	err_sys("getc error");
pr_stdio("/etc/motd", fp);
exit(0);
}
void
pr_stdio(const char *name, FILE *fp)
{

	printf("stream = %s, ", name);
	/* following is nonportable */
	if (fp->_flags & _IONBF)
		printf("unbuffered");
	else if (fp->_flags & _IOLBF)
		printf("line buffered");
	else /* if neither of above */
		printf("fully buffered");
	printf(", buffer size = %d\n", buffer_size(fp));
}
 int buffer_size(FILE *fp)
	{

	 #ifdef _LP63
		 return(fp->_base - fp->ptr);
	 #else
         return (BUFSIZ);
	 #endif
	 }
