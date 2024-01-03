#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int narr[10] = { 1,2,-1,-2,1,2,-1,-2,1,2 };
    int tmp = 0;
    for (int i = 0; i < sizeof(narr) / sizeof(int); i++)
    {
        tmp += narr[i];
    }
    printf("°á°ú = %d", tmp);
}