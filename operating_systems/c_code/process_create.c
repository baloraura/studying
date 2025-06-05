#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

	pid_t p = fork();

	if (p < 0) {
		perror("Fork fail");
		exit(1);
	}
	printf("Hello World!, process_id(pid) = %d \n", getpid());


	return 0;
}
