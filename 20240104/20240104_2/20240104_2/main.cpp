#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int main(void)
{
    int evenArray[MAX_SIZE];
    int oddArray[MAX_SIZE];

    int evenCount = 0;
    int oddCount = 0;

    srand(time(NULL));

    while (evenCount < MAX_SIZE && oddCount < MAX_SIZE)
    {
        int randomNumber = rand() % 101;

        if (randomNumber % 2 == 0)
        {
            evenArray[evenCount] = randomNumber;
            evenCount++;
        }
        else
        {
            oddArray[oddCount] = randomNumber;
            oddCount++;
        }
    }


    printf("짝수 배열의 데이터     : ");
    for (int i = 0; i < evenCount; i++)
    {
        printf(" %d ", evenArray[i]);
    }
    printf("\n");
    printf("짝수 배열의 데이터 개수: %d\n", evenCount);
    printf("홀수 배열의 데이터     : ");
    for (int i = 0; i < oddCount; i++)
    {
        printf(" %d ", oddArray[i]);
    }
    printf("\n");
    printf("홀수 배열의 데이터 개수: %d\n", oddCount);

    return 0;
}


