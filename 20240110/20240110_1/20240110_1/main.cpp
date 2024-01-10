#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define QUEUE_SIZE 5

void enqueue(int*);
void dequeue(int*);

void enqueue(int* rear) 
{
    int data;

    printf("data : ");
    scanf("%d", &data);

    *rear = data;
}

void dequeue(int* front) 
{
    printf("data : %d\n", *front);
}

int main(int argc, const char* argv[]) 
{
    int queue[QUEUE_SIZE] = { 0 }; //queue ũ��� int �迭 5
    int front = 0; //front,rear�� queue�� 0��° �ε����� ����
    int rear = 0;
    int num;

    do {
        printf("1. enqueue 2. dequeue 3. print 4. end\n");
        scanf("%d", &num);

        //inqueue
        if (num == 1) {
            if (rear > QUEUE_SIZE - 1) 
            {
                printf("queue�� �� ���η��粲~!!\n");
            }
            else {
                enqueue(&queue[rear++]);
            }

            //dequeue
        }
        else if (num == 2) 
        {
            if (rear == front) 
            {
                printf("queue �� �����ο�����~\n");
            }
            else {
                dequeue(&queue[front++]);
            }

            //print
        }
        else if (num == 3) 
        {
            printf("data : ");
            for (int i = 0; i < QUEUE_SIZE; i++) 
            {
                printf("%d ", queue[i]);
            }
            printf("\n");
        }

    } while (num != 4);

    return 0;
}
