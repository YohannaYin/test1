#include <sys/ipc.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MSGSZ 512

struct mymesg {
	long mtype;
	char mtext[MSGSZ];
};


int main (int argc, char *argv[]) {
	
	key_t key = 4587;

	int q_index;
	int num;
	int msgid;

	sscanf(argv[1] , "%x" , &q_index);
	sscanf(argv[2], "%d", &num);

	printf("q_index = %d, num = %d\n", q_index % 16, num);

	if ((msgid = msgget(key+(q_index % 16), 0666)) < 0) {
		printf("msgget");
		exit(1);
	}

	struct mymesg sbuf, rbuf;

	sbuf.mtype = 1;
	sprintf(sbuf.mtext, "%d", num);
	if (msgsnd(msgid, &sbuf, strlen(sbuf.mtext)+1, 0) < 0) {
			printf("send message");
			exit(1);
	} 
	printf("send message : %s, to queue %d\n", sbuf.mtext, msgid);
	if (msgrcv(msgid, &rbuf, MSGSZ, 2, 0) < 0) {
		printf("msgrcv\n");
		exit(1);
	}

	printf("%s\n", rbuf.mtext);

	return 0;
}
