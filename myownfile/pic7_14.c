/*************************************************************************
    > File Name: pic7_14.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月07日 星期二 17时03分44秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>
#define
DATAFILE
"datafile"
FILE *
open_data(void)
{

	FILE *fp;
	char databuf[BUFSIZ];
	/* setvbuf makes this the stdio buffer */
	local automatic
		variable!
		if ( (fp = fopen(DATAFILE, "r")) == NULL)
			return(NULL);
	if (setvbuf(fp, databuf, BUFSIZ, _IOLBF) != 0)/*此处因为可能还有其他进程在使用databuf，所以会造成冲突和混乱*/
		return(NULL);
	return(fp);
	/* error */
}
