#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "apue.h"
int total = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *tfn(void *arg) {
	int num = *((int *)arg);
	pthread_detach(pthread_self());
	//sleep(3);
	pthread_mutex_lock(&lock);
	total += num;
	printf("num = %d total = %d\n", num, total);
	pthread_mutex_unlock(&lock);

}
int main(int argc, char *argv[]) {
	pthread_t tid;
	int num;
	while (scanf("%d", &num) != EOF) {
		pthread_create(&tid, NULL, tfn, (void *) &num);
	}
	//sleep(5);
	printf("total = %d\n", total);
//	pthread_mutex_destory(&lock);
	return 0;
}
