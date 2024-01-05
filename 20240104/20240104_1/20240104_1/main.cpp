#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define rows 20
#define cols 5

int main(void)
{
    int a[rows][cols];

    srand(time(NULL));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            a[i][j] = 1 + rand() % 100;
        }
    }

    for (int j = 0; j < rows; j++)
    {
        float total = a[j][0] * 0.3 + a[j][1] * 0.4 + a[j][2] * 0.2 + a[j][3] * 0.1 - a[j][4];
        printf("학생 #%i의 최종 성적 =%10.2f\n", j + 1, fmax(total, 0.0));
    }

    return 0;
}

