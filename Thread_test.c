#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* print_gugudan(void* arg) {
    int dan = *((int*)arg);

    for (int i = 1; i <= 9; ++i) {
        pthread_mutex_lock(&mutex);
        printf("%d * %d = %d\n", dan, i, dan * i);
        pthread_mutex_unlock(&mutex);
        sleep(1); // 1초 쉬기
    }

    printf("\n"); // 1단 출력 후 한 줄 띄우기
    return NULL;
}

int main() {
    pthread_t threads[3];
    int dan_values[] = {1, 2, 3};

    for (int i = 0; i < 3; ++i) {
        pthread_create(&threads[i], NULL, print_gugudan, (void*)&dan_values[i]);
        pthread_join(threads[i], NULL); // 현재 쓰레드가 다음 쓰레드가 시작되기 전까지 대기
        sleep(2); // 2초 쉬기 (다음 단으로 넘어가기 전에 잠시 대기)
    }

    return 0;
}
