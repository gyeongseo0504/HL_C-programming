#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int dec = 17;
    int bimy[20] = { 0, };
    int p = 0;

    for (; ; )
    {
        bimy[p] = dec % 2;
        dec = dec / 2;
        p++;
        if (dec == 0)
            break;
    }

    for (int i = p - 1; i >= 0; i--)
    {
        printf("%d", bimy[i]);
    }

    return 0;
}