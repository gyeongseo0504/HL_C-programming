#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread1_func (void *vargp)
{
        unsigned short cnt=0;

        printf("Thread 1 function starts...\n");

        while(1)
        {
                sleep(1);
                printf("thread1_func is running ===>(%d)\n", cnt++);
        }
}

void *thread2_func (void *vargp)
{
        unsigned short cnt=0;

        printf("Thread 2 function starts...\n");

        while(1)
        {
                sleep(3);
                printf("thread2_func is running =======> (%d)\n", cnt++);
        }
}

int main()
{

    char buf[32];

    pthread_t thread1ID, thread2ID;

    pthread_create(&thread1ID, NULL, thread1_func, (void *)&thread1ID);

    pthread_create(&thread2ID, NULL, thread2_func, (void *)&thread2ID);

    printf("\nType exit to terminate program !\n");

    while(1)
    {
            fgets(buf, sizeof(buf), stdin);
            if(strncmp(buf, "exit", 4)==0)
                break;
    }
    return 0;
}
 
