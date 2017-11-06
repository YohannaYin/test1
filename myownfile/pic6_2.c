/*************************************************************************
    > File Name: pic6_2.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月06日 星期一 15时52分09秒
	>getpwnam 函数的实现，此程序需要main函数才能运行，此处只是定义一个函数而已。
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<stddef.h>

#include<string.h>

#include<pwd.h>

#include<sys/types.h>

struct passwd *getpwnam(const char *name)
{
	struct passwd *ptr;
	setpwent();
	while((ptr = getpwent())!=NULL)
	{
		if(strcmp(name,ptr->pw_name)==0)
			break;
	}
	endpwent();
	return(ptr);
}
