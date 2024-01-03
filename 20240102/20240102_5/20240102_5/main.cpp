#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int j = 0;
    int i = 0;
    int test[] = {};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            test[i][0] = i;
            test[0][j] = j;
        }
        if (i == j)
        {
            test[i][j] = j;
        }

    }

    return 0;
}