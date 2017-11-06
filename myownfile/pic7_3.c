/*************************************************************************
    > File Name: pic7_3.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月06日 星期一 17时10分22秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

static void my_exit1(void);
static void my_exit2(void);
int main(void)
{
	if(atexit(my_exit2)!=0)
		err_sys("can't register my_exit2'");
	if(atexit(my_exit1)!=0)
		err_sys("can't register my_exit1");
	if(atexit(my_exit1)!=0)
		err_sys("can't register my_exit1");
	printf("main is done\n");
	return(0);

}
static  void my_exit1(void)
{
	printf("first exit handler\n");
}
static void my_exit2(void)
{
	printf("second exit handler\n");
}
