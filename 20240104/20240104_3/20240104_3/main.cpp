#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void bubbleSort(int arr[], int size);

int main(void)
{
    int num[SIZE];

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        num[i] = rand() % 100 + 1;
        printf("숫자를 입력하세요: ");
        scanf("%d", &num[i]);
    }

    bubbleSort(num, SIZE);

    printf("정렬된 배열: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", num[i]);
    }

    return 0;
}
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


