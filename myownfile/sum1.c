/*************************************************************************
    > File Name: sum1.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月13日 星期一 20时26分55秒
	>用户不断从标准输入输入一个数N
	>主线程得到之后，创建一个新线程计算total=total+N
	>其中total是一个全局变量
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>
#include<pthread.h>
int total = 0;
pthread_mutex_t *lock;
void *tfn(void *arg)
{
	int num = *((int *)arg);
	long d2num = 2*num;
	//printf("In thread %lu arg:%d.\n",(unsigned long)pthread_self(),num);
	pthread_mutex_lock(lock);
	total+=num;
	pthread_mutex_unlock(lock);
	//sleep(1);
	printf("num=%d  total=%d\n",num,total);
	return (void*)(d2num);
}
int main(int argc,char *argv[])
{
	pthread_t tid;
	int num;
//	void *tret;
	lock=(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(lock,NULL);
	while(scanf("%d",&num)==1)
	{
		pthread_create(&tid,NULL,tfn,(void*)&num);
		printf("total = %d\n",total);
	//	pthread_join(tid,&tret);
	//	printf("Thread exit code: %ld\n",(long)tret);
	}
	pthread_mutex_destroy(lock);
	free(lock);
	return 0;
	//printf("Main thread %lu is over.\n",(unsigned long)pthread_self());
}
