#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


#define THREADS 5

void* thread_function(void *arg) {
	int thread_id = *(int*)arg;
	printf("Thread %d: Started\n", thread_id);

	for (int i = 0; i < 5; i++) {
		printf("Thread %d: Process %d\n", thread_id, i);
	}

	printf("Thread %d: Finished\n", thread_id);
	return NULL;
}


int main() {

	pthread_t threads[THREADS];

	int thread_ids[THREADS];

	for (int i = 0; i < THREADS; i++) {
		thread_ids[i] = i + 1;
	}

	int num_threads = 2;

	for (int i = 0; i < num_threads; i++) {
		if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
			perror("Failed to create thread\n");
			return 1;
		}
	}

	for (int i = 0; i < num_threads; i++) {
		if (pthread_join(threads[i], NULL) != 0) {
			perror("Failed to join thread\n");
			return 1;
		}
	}

	printf("Main Thread: ALL threads completed\n");
	
	return 0;
}
