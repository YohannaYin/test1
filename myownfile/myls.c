/*************************************************************************
    > File Name: myls.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月04日 星期六 19时26分08秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<sys/stat.h>

#include<string.h>
int main(int argc,char *argv[])
{
	char mode[3];
	memset(mode,'-',sizeof(mode));
	if(argc != 2)
		err_quit("usag: myls.out <pathname>\n");
	struct stat buf;
	stat(argv[1],&buf);
	if(S_IRUSR&buf.st_mode)
		mode[0]='r';
	if(buf.st_mode&S_IWUSR)
		mode[1]='w';
	if(buf.st_mode&S_IXUSR)
		mode[2]='x';
	printf("%s\n",mode);
	exit(0);
}
