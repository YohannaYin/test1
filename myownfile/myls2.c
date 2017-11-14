/*************************************************************************
    > File Name: myls2.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月14日 星期二 19时20分32秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<dirent.h>

#include<pwd.h>

#include<fcntl.h>
int main(int argc,char *argv[])
{
	DIR *dp;
	struct dirent *dirp;
	struct stat buf;
	char mode[4];
	struct passwd *ptr;
	if(argc==1)
	{
		err_quit("usage: ls directory_name");
	}
	if((dp = opendir(argv[1]))==NULL)
		err_sys("can't open %s",argv[1]);
	int fd = open(argv[1],O_RDONLY);
	while((dirp=readdir(dp))!=NULL)
	{
		stat(dirp->d_name,&buf);
		//fstatat(fd,dirp->d_name,&buf,AT_SYMLINK_NOFOLLOW);
		if(S_ISREG(buf.st_mode))//判断其是否为普通文件
		{
			memset(mode,'-',sizeof(mode)-1);
			if(buf.st_mode&S_IRUSR)
				mode[0] = 'r';
			if(buf.st_mode&S_IWUSR)
				mode[1] = 'w';
			if(buf.st_mode&S_IXUSR)
				mode[2] = 'x';
			ptr = getpwuid(buf.st_uid);//获得用户id
			printf("%s %s %s\n",mode,ptr->pw_name,dirp->d_name);
		}
	}
	closedir(dp);
	exit(0);
}
