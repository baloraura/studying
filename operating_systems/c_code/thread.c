#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_message(void* arg) {
	char* message = (char*) arg;
	printf("%s\n", message);
	return NULL;
}


int main() {

	pthread_t thread1, thread2;
	char* message1 = "Hello from Thread 1";
	char* message2 = "Hello from Thread 2";

	if (pthread_create(&thread1, NULL, print_message, (void*)message1) != 0) {
		perror("Failed to create thread1");
		return 1;
	}

	if (pthread_create(&thread2, NULL, print_message, (void*)message2) != 0) {
		perror("Failed to create thread2");
		return 1;
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Main thread exiting.\n");

	return 0;
}
