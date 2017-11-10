/*************************************************************************
    > File Name: pic15_7.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月10日 星期五 20时23分32秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

static int pfd1[2], pfd2[2];
void
TELL_WAIT() {

	if (pipe(pfd1) < 0 || pipe(pfd2) < 0)
		err_sys("pipe error");
}
Void TELL_PARENT(pid_t pid) {

	if (write(pfd2[1], "c", 1) != 1)
		err_sys("write error");
}
void WAIT_PARENT(void) {

	char
		c;
	if (read(pfd1[0], &c, 1) != 1) err_sys("read error");
	if (c != 'p') err_quit("WAIT_PARENT: incorrect data");
}
void TELL_CHILD(pid_t pid) {

	if (write(pfd1[1], "p", 1) != 1) err_sys("write error");
}
void WAIT_CHILD(void) {

	char
		c;
	if (read(pfd2[0], &c, 1) != 1) err_sys("read error");
	if (c != 'c')
		err_quit("WAIT_CHILD: incorrect data");
}
