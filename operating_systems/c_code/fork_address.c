#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>


int main() {

	int a, b;
	pid_t p = fork();

	if (p < 0) {
		perror("Fork Fail");
		exit(1);
	}

	if (p == 0) {
		//child
		printf("In the child process! My PID is %d\n", getpid());
		a = 23;
		b = 25;
		printf("Setting a to be %d\n", a);
		printf("Setting b to be %d\n", b);
		printf("Here is the address of a: %p\n", &a);
		printf("Here is the adress of b: %p\n", &b);
	} else {

		// if p > 0, in the parent
		wait(NULL);
		printf("In the parent process! My PID is %d\n", getpid());
		printf("Old value of a: %d\n", a);
		a = 26;
		printf("New value of a: %d\n", a);
		printf("Old value of b: %d\n", b);
		b = a * 2;
		printf("new value of b: %d\n", b);
		
		printf("Here is the address of a: %p\n", &a);
		printf("Here is the address of b: %p\n", &b);
	}
	return 0;
}
