#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3
#define ARRAY_SIZE 100

int sum1 = 0, sum2 = 0, sum3 = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* calculateSum(void* arg) {
    int* start = (int*)arg;
    int localSum = 0;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        localSum += *start + i;
    }

    pthread_mutex_lock(&mutex);
    if (*start == 1) {
        sum1 = localSum;
    }
    else if (*start == 101) {
        sum2 = localSum;
    }
    else if (*start == 201) {
        sum3 = localSum;
    }
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];

    int startValues[NUM_THREADS] = { 1, 101, 201 };

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, calculateSum, (void*)&startValues[i]) != 0) {
            fprintf(stderr, "pthread create error\n");
            exit(1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "pthread join error\n");
            exit(1);
        }
    }

    int totalSum = sum1 + sum2 + sum3;
    printf("Total Sum: %d\n", totalSum);

    pthread_mutex_destroy(&mutex);

    return 0;
}
