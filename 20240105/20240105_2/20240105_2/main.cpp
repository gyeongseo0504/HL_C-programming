#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define rows 20
#define cols 5

void mando(int a[rows][cols], double averages[rows], int ranks[rows])
{
    for (int i = 0; i < rows; i++)
    {
        averages[i] = a[i][0] * 0.3 + a[i][1] * 0.4 + a[i][2] * 0.2 + a[i][3] * 0.1;
        ranks[i] = 1;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (averages[i] < averages[j])
            {
                ranks[i]++;
            }
        }
    }
}
void hoho(int a[rows][cols], double averages[rows], int ranks[rows])
{
    printf("번호\t중간\t기말\t과제\t출석\t총합\t등수\n");
    for (int i = 0; i < rows; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            i + 1, a[i][0], a[i][1], a[i][2], a[i][3], (int)averages[i], ranks[i]);
    }
}


int main(void) {
    int a[rows][cols];
    double averages[rows];
    int ranks[rows];

    srand(time(NULL));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            a[i][j] = 1 + rand() % 100;
        }
        if (a[i][3] <= 10)
        {
            a[i][3] = 10;
        }
    }

    mando(a, averages, ranks);
    hoho(a, averages, ranks);

    return 0;
}