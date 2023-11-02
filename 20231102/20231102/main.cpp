#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double reference;

int compare(const void* a, const void* b)
{
    double num1 = *(double*)a;
    double num2 = *(double*)b;

    double diff1 = fabs(num1 - reference);
    double diff2 = fabs(num2 - reference);
 
    if (diff1 < diff2)
        return -1;
    if (diff1 > diff2)
        return 1;
    return 0;
}

int main()
{
    printf("���� ���� �Է��ϼ���: ");
    scanf("%lf", &reference);

    double numbers[15];
    FILE* inputFile;
    FILE* outputFile;

    inputFile = fopen("input_numbers.txt", "r");
    if (inputFile == NULL)
    {
        printf("�Է� ������ �� �� �����ϴ�.\n");
        return 1;
    }

    for (int i = 0; i < 15; i++)
    {
        if (fscanf(inputFile, "%lf", &numbers[i]) != 1)
        {
            printf("�Է� ���Ͽ� ������ �����Ͱ� �ֽ��ϴ�.\n");
            fclose(inputFile);
            return 1;
        }
    }

    fclose(inputFile);
    qsort(numbers, 15, sizeof(double), compare);
    outputFile = fopen("sorted_numbers.txt", "w");

    if (outputFile == NULL)
    {
        printf("��� ������ �� �� �����ϴ�.\n");
        return 1;
    }

    printf("���� ����� ���ڵ���:\n");

    for (int i = 0; i < 15; i++)
    {
        printf("%.0lf ", numbers[i]);
    }

    printf("\n");
    fclose(outputFile);
    printf("�����͸� �����ϰ� sorted_numbers.txt ���Ͽ� �����߽��ϴ�.\n");



    return 0;
}