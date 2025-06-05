#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

	int a, b;

	pid_t p = fork();

	if (p < 0) {
		//fork failed
		perror("Fork Failed\n");
		exit(1);
	}
	else if (p == 0) {
		//child process
		printf("Hello from child process\n");
		printf("My PID is %d\n", getpid());
		a = 5;
		b = 6;
		printf("I'm making a = %d and b = %d\n", a, b);
	} else {
		//if p > 0, meaning it is the parent process
		printf("Hello from the parent process\n");
		printf("My PID is %d\n", getpid());
		printf("Here is what a and b equals in the parent process\n");
		printf("a: %d\n", a);
		printf("b: %d\n", b);
	}

	return 0;
}
