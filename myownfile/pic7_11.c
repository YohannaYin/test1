/*************************************************************************
    > File Name: pic7_9.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月07日 星期二 16时29分15秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#define	TOK_ADD 5

#include<setjmp.h>

void do_line(char *);
void cmd_add(void);
int get_token(void);

jmp_buf jmpbuffer;
int main(void)
{
	char line[MAXLINE];
	if(setjmp(jmpbuffer)!=0)
		printf("error");
	while(fgets(line,MAXLINE,stdin)!=NULL)
		do_line(line);
	exit(0);

}
char *tok_ptr;
void do_line(char *ptr)
{
	int cmd;
	tok_ptr = ptr;
	while((cmd = get_token())>0)
	{
		switch(cmd)
		{
			case TOK_ADD:
				cmd_add();
				break;
		}
	}
}
void cmd_add(void)
{
	int token;
	token = get_token();
	if(token<0)
		longjmp(jmpbuffer,1);
}
int get_token(void)
{
	
}
