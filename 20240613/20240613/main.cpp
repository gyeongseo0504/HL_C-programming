#include <stdio.h>
#include <stdlib.h>

int main(void)
{


    /*
    int* list;
    list = (int*)malloc(3 * sizeof(int));
    if (list == NULL)
    {
        printf("���� �޸� �Ҵ� ����\n");
        exit(1);
    }
    list[0] = 10;
    list[1] = 20;
    list[2] = 30;
    free(list);
    return 0;


    int* list;
    int i, students, sum = 0;

    printf("�л��� ��: ");
    scanf("%d", &students);

    list = (int*)malloc(students * sizeof(int));
    if (list == NULL)
    {
        printf("���� �޸� �Ҵ� ����\n");
        exit(1);
    }
    for (i = 0; i < students; i++)
    {
        printf("�л� #%d ����: ", i + 1);
        scanf("%d", &list[i]);
    }
    for (i = 0; i < students; i++)
        sum += list[i];
    printf("���� ���=%.2f \n", (double)sum / students);
    free(list);
    return 0;*/


    printf("���� 2���� ������ ������ �ʿ� \n");
    int* list = (int*)malloc(sizeof(int) * 2);
    int i;
    int* list_new;

    list[0] = 10;
    list[1] = 20;
    printf("���� 3���� ������ �������� Ȯ�� \n");

    list_new = (int*)realloc(list, sizeof(int) * 3);
    list_new[2] = 30;

    for (i = 0; i < 3; i++)
        printf("%d ", list_new[i]);
    printf("\n");
    return 0;


}