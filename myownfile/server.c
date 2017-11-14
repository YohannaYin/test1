#include "apue.h"
#include "myerr.h"
#include <netdb.h>
#include <errno.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define QLEN 10

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 256
#endif


int
set_cloexec(int fd)
{
	int		val;

	if ((val = fcntl(fd, F_GETFD, 0)) < 0)
		return(-1);

	val |= FD_CLOEXEC;		/* enable close-on-exec */

	return(fcntl(fd, F_SETFD, val));
}


int
initserver(int type, const struct sockaddr *addr, socklen_t alen,
  int qlen)
{
    printf("initserver\n");
	int fd;
	int err = 0;

	if ((fd = socket(addr->sa_family, type, 0)) < 0)
		return(-1);
	if (bind(fd, addr, alen) < 0)
		goto errout;
	if (type == SOCK_STREAM || type == SOCK_SEQPACKET) {
		if (listen(fd, qlen) < 0)
			goto errout;
	}
    printf("initserver finished\n");
	return(fd);

errout:
	err = errno;
	close(fd);
	errno = err;
	return(-1);
}

void
serve(int sockfd)
{
	int		clfd, status;
	pid_t	pid;

	set_cloexec(sockfd);
	for (;;) {
		if ((clfd = accept(sockfd, NULL, NULL)) < 0) {
			syslog(LOG_ERR, "ruptimed: accept error: %s",
			  strerror(errno));
			exit(1);
		}
        printf("get a connect\n");
		if ((pid = fork()) < 0) {
			syslog(LOG_ERR, "ruptimed: fork error: %s",
			  strerror(errno));
			exit(1);
		} else if (pid == 0) {	/* child */
			/*
			 * The parent called daemonize ({Prog daemoninit}), so
			 * STDIN_FILENO, STDOUT_FILENO, and STDERR_FILENO
			 * are already open to /dev/null.  Thus, the call to
			 * close doesn't need to be protected by checks that
			 * clfd isn't already equal to one of these values.
			 */
			if ((pid = fork()) < 0) {
				err_sys("fork error");
			} else if (pid == 0) {
                sleep(2);
				if (dup2(clfd, STDOUT_FILENO) != STDOUT_FILENO ||
			  		dup2(clfd, STDERR_FILENO) != STDERR_FILENO) {
					syslog(LOG_ERR, "ruptimed: unexpected error");
					exit(1);
				}
				close(clfd);
                printf("second child, parent pid = %ld\n", (long)getppid());
				execlp("echo", "echo", "hello word", (char *)0);
				//syslog(LOG_ERR, "ruptimed: unexpected return from exec: %s",
			  	//strerror(errno));
			}
			exit(0);
		} else {		/* parent */
			close(clfd);
			waitpid(pid, &status, 0);
		}
	}
}

int
main(int argc, char *argv[])
{
	struct addrinfo	*ailist, *aip;
	struct addrinfo	hint;
	int				sockfd, err, n;
	char			*host;

	if (argc != 1)
		err_quit("usage: ruptimed");
	if ((n = sysconf(_SC_HOST_NAME_MAX)) < 0)
		n = HOST_NAME_MAX;	/* best guess */
	if ((host = malloc(n)) == NULL)
		err_sys("malloc error");
	if (gethostname(host, n) < 0)
		err_sys("gethostname error");
//	daemonize("ruptimed");
    printf("hostname = %s\n", host);
	memset(&hint, 0, sizeof(hint));
	hint.ai_flags = AI_CANONNAME;
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_canonname = NULL;
	hint.ai_addr = NULL;
	hint.ai_next = NULL;
	if ((err = getaddrinfo(host, "8888", &hint, &ailist)) != 0) {
		syslog(LOG_ERR, "ruptimed: getaddrinfo error: %s",
		  gai_strerror(err));
		exit(1);
	}
	for (aip = ailist; aip != NULL; aip = aip->ai_next) {
		if ((sockfd = initserver(SOCK_STREAM, aip->ai_addr,
		  aip->ai_addrlen, QLEN)) >= 0) {
			serve(sockfd);
			exit(0);
		}
	}
	exit(1);
}
