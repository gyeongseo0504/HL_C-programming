#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 301

int totalSum = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* calculateSum(void* arg) {
    int start = *(int*)arg;
    int localSum = 0;

    for (int i = start; i < ARRAY_SIZE; i += 1) {
        localSum += i;
    }

    pthread_mutex_lock(&mutex);
    totalSum += localSum;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    int startValue = 0;

    if (pthread_create(&thread, NULL, calculateSum, (void*)&startValue) != 0) {
        fprintf(stderr, "pthread create error\n");
        exit(1);
    }

    if (pthread_join(thread, NULL) != 0) {
        fprintf(stderr, "pthread join error\n");
        exit(1);
    }

    printf("Total Sum: %d\n", totalSum);

    pthread_mutex_destroy(&mutex);

    return 0;
}
