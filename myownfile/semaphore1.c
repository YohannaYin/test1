/*************************************************************************
    > File Name: semaphore1.c
    > Author: YinHong
    > Mail: 15773287336@163.com 
    > Created Time: 2017年11月11日 星期六 10时14分48秒
 ************************************************************************/

#include"myerr.h"

#include"apue.h"

#include<stdio.h>

#include<sys/sem.h>

void init_a_semaphore(int,int,int);
int rm_semaphore(int);
int semaphore_V(int sem_id);
int semaphore_P(int sem_id);
int open_semaphore_set(key_t keyval,int numsems);
union semun {

	int val;
	struct semid_ds *buf;
	unsigned short *array;
};
int main(int argc,char *argv[]) {

	int sem_id,i,creat=0,pause_time;
	char *cp;
	srand((unsigned int )getpid());
	sem_id=open_semaphore_set((key_t)1234,1);
	if (argc>1&&strcmp(argv[1],"1")) {
		init_a_semaphore(sem_id,0,1);
		creat=1;
		sleep(2);
	}for(i=0;i<argc;i++) {

		cp=argv[i];
		if (!semaphore_P(sem_id)) exit(-1);
		printf("process %d:",getpid());
		fflush(stdout);
		while(*cp) {

			printf("%c",*cp); fflush(stdout);
			sleep(rand()%3);
			cp++;
		}
		printf("\n");
		if (semaphore_V(sem_id)) exit(-1);
		sleep(rand()%2);
	}
	printf("\n%d –finished\n",getpid());
	if (creat==1) {

		sleep(10);
		rm_semaphore(sem_id);
	}
	exit(0);
}
int open_semaphore_set(key_t keyval,int numsems) {

	int sid;
	if (!numsems) return(-1);
	if ((sid=semget(keyval,numsems,IPC_CREAT|0660))==-1) return (-1);
	else return(sid);
}
int semaphore_P(int sem_id) {

	struct sembuf sb;
	sb.sem_num=0;
	sb.sem_op=-1; 
	sb.sem_flg=SEM_UNDO;
	if (semop(sem_id,&sb,1)==-1) {

			fprintf(stderr,"semaphore_P failed\n"); return(0);
			}
			return(1);
			}
			int semaphore_V(int sem_id) {

			struct sembuf sb; sb.sem_num=0;
			sb.sem_op=1;
			sb.sem_flg=SEM_UNDO;
			if (semop(sem_id,&sb,1)==-1) {

					fprintf(stderr,"semaphore_V failed\n"); return(0);
					}
					return(1);
					}
void init_a_semaphore(int sid,int semnum,int initval) {

	union semun semopts;
	semopts.val=initval;
	semctl(sid,semnum,SETVAL,semopts);
}
int rm_semaphore(int sid) {

	return(semctl(sid,0,IPC_RMID,0));
}
