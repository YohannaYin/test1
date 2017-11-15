#include <sys/ipc.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MSGSZ 512

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

long acc = 0;
int nque = 1;

struct mymesg {
	long mtype;
	char mtext[MSGSZ];
};

int thread_id[16];
int msgid[16];
pthread_t tid[16];

void *thread_fn(void *arg) {
	int n = *((int *)arg);
	struct mymesg sbuf, rbuf;
	pthread_mutex_lock(&lock);
	printf("thread %d wait %d queue\n", n, msgid[n]);
	//acc += n;
	pthread_mutex_unlock(&lock);

	while (msgrcv(msgid[n], &rbuf, MSGSZ, 1, 0) != 0) {
		pthread_mutex_lock(&lock);
		printf("%d queue thread rcv %s\n", n, rbuf.mtext);
		acc += atol(rbuf.mtext);
		sbuf.mtype = 2;
		sprintf(sbuf.mtext, "acc = %ld", acc);
		if (msgsnd(msgid[n], &sbuf, strlen(sbuf.mtext)+1, 0) < 0) {
			printf("send message");
			exit(1);
		} 
		pthread_mutex_unlock(&lock);
	}
	pthread_exit(0);
}

int main (int argc, char *argv[]) {
	int opt;
	while ((opt = getopt(argc, argv, "q:")) != -1) {
		switch(opt) {
			case 'q':
				nque = atoi(optarg);
			default:
				break;
		}
	}
	printf("queue num = %d\n", nque);
	key_t key = 4587;
	for (int i = 0; i < nque; i++) {
		if ((msgid[i] = msgget(key+i, IPC_CREAT | 0666)) < 0) {
			printf("msgget");
			exit(1);
		}
		thread_id[i] = i;
		pthread_create(&tid[i], NULL, thread_fn, &thread_id[i]);
	}
	
	for (int i = 0; i < nque; i++) {
		printf("queue %d id = %d\n", i, msgid[i]);
	}
	
	for (int i = 0; i < nque; i++) {
		pthread_join(tid[i], NULL);
	}
	printf("acc = %ld\n", acc);
	return 0;
}
