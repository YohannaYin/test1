#include <stdio.h>
#include "apue.h" 
#include "myerr.h" 
#include <unistd.h>

long score = 0;

uid_t uid, euid, suid;

static void sig_alrm(int signo) {
	printf("a log \n");
	seteuid(suid);
	printf("log start uid = %d, euid = %d, suid = %d\n", getuid(), geteuid(), suid);
	FILE *fp = fopen("log.txt", "a");
	fprintf(fp, "score = %ld\n", score);
	seteuid(uid);
	fflush(fp);
	printf("log end uid = %d, euid = %d, suid = %d\n", getuid(), geteuid(), suid);
	alarm(3);
}

int main () {
	uid = getuid(); 
	euid = geteuid();
	suid = euid;
	printf("first uid = %d, euid = %d, suid = %d\n", uid, euid, suid);
	seteuid(uid);
	printf("start uid = %d, euid = %d, suid = %d\n", getuid(), geteuid(), suid);
	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		err_sys("signal error");
	alarm(3);
	for (;;)
		score++;
	return 0;
}
