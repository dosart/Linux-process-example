#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	printf("Hello from main process %d\n", getpid());
	int result = fork();
	if (result < 0) {
		fprintf(stderr, "fork error\n");
		exit(1);
	} else if (result == 0) {
		printf("Hello I'm child process %d\n", getpid());
		exit(0);
	} else {
		int status = 0;
		wait(&status);
		printf("Hello I'm parent %d. My pid is %d\n", result, getpid());
		if (WIFEXITED(status)) {
			printf("Normal completion. Status %d", status);
		} else if (WIFSIGNALED(status)) {
			printf("Killed by signal %d", WTERMSIG(status));
		} else if (WIFSTOPPED(status)) {
			printf("Stopped by signal %d", WSTOPSIG(status));
		}
	}
	return 0;
}
