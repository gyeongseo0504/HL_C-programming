#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

int main()
{
    int key, i;
    int list[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    printf("Ž���� ���� �Է��Ͻÿ�: ");
    scanf("%d", &key);

    for (i = 0; i < SIZE; i++)
    {
        if (list[i] == key)
            printf("Ž�� ���� �ε���= %d\n", i);

    }
    printf("Ž�� ����\n");
    return 0;
}