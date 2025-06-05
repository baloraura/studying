#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int shared_var = 0;

void* increment(void* arg) {

	for (int i = 0; i < 10000; i++) {
		shared_var++;
	}

	return NULL;
}


void* decrement(void* arg) {

	for (int i = 0; i < 10000; i++) {
		shared_var--;
	}
	return NULL;
}


int main() {

	pthread_t t1, t2;

	pthread_create(&t1, NULL, increment, NULL);
	pthread_create(&t2, NULL, decrement, NULL);

	printf("The final shared value of shared_var: %d\n", shared_var);
	return 0;
}
