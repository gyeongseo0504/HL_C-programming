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
    printf("기준 수를 입력하세요: ");
    scanf("%lf", &reference);

    double numbers[15];
    FILE* inputFile;
    FILE* outputFile;

    inputFile = fopen("input_numbers.txt", "r");
    if (inputFile == NULL)
    {
        printf("입력 파일을 열 수 없습니다.\n");
        return 1;
    }

    for (int i = 0; i < 15; i++)
    {
        if (fscanf(inputFile, "%lf", &numbers[i]) != 1)
        {
            printf("입력 파일에 부족한 데이터가 있습니다.\n");
            fclose(inputFile);
            return 1;
        }
    }

    fclose(inputFile);
    qsort(numbers, 15, sizeof(double), compare);
    outputFile = fopen("sorted_numbers.txt", "w");

    if (outputFile == NULL)
    {
        printf("출력 파일을 열 수 없습니다.\n");
        return 1;
    }

    printf("가장 가까운 숫자들은:\n");

    for (int i = 0; i < 15; i++)
    {
        printf("%.0lf ", numbers[i]);
    }

    printf("\n");
    fclose(outputFile);
    printf("데이터를 정렬하고 sorted_numbers.txt 파일에 저장했습니다.\n");



    return 0;
}