#include<stdio.h>
#include"apue.h"
#include"myerr.h"
int main(void)
{
	char *ptr;
	size_t size;
	if(chdir("/usr/spool/uucppublic")<0)
		err_sys("chdir failed");
	ptr = path_alloc(&size);//自己的函数，需要自己编写，故此程序不能直接运行
	if(getcwd(ptr,size)==NULL)
		err_sys("getcwd failed");
	printf("cwd = %s\n",ptr);
	exit(0);
}
