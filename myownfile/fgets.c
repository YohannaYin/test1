/*************************************************************************
    > File Name: fgets.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月14日 星期二 12时56分35秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>
#include "apue.h"
int main(void)
{

	/*
	 * * puts与fputs：puts每次输出的时候带有换行符
	 * * gets与fgets：gets不安全，没有指定输入长度，会发生内存溢出问题
	 * ；fgets每次
	 * *只读取n-1个字符，本道题n=2，每次只读取一个字符
	 * */
		char buf[2];
			while(fgets(buf,2,stdin)!=NULL){
					if(puts(buf)==EOF)
								printf("%s","error");
			}		
				if(ferror(stdin))
							printf("%s","error");

	exit(0);
}
