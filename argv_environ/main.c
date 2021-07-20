#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char *argv[])
{
	printf("The number of parameters passed to the program: %d\n", argc);
	for (int i = 0; i < argc; ++i) {
		printf("argv[%d] = %s \n", i, argv[i]);
	}
	for (int i = 0; environ[i] != NULL; ++i) {
		printf("environ[%s]\n", environ[i]);
	}
	return 0;
}
