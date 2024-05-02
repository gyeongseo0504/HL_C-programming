#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 5

int main()
{
    char stack[SIZE][20] = { "None", "None", "None", "None", "None" }; // ���� �迭
    int top = -1; // ������ top�� ��Ÿ���� ����

    char data[20]; // �Է� ���� �����͸� ������ �迭

    while (1)
    {
        int choice;
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. ����\n");
        printf("�޴��� �����ϼ���: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Push
            if (top == SIZE - 1)
            {
                printf("������ �� á��\n");
            }
            else
            {
                printf("������ �����͸� �Է��ϼ���: ");
                scanf("%s", data);
                top++;
                strcpy(stack[top], data);
            }
            break;

        case 2: // Pop
            if (top == -1)
            {
                printf("������ ��� ����\n");
            }
            else {
                printf("Pop�� ������: %s\n", stack[top]);
                top--;
            }
            break;

        case 3: // Top
            if (top == -1)
            {
                printf("������ ��� ����\n");
            }
            else {
                printf("Top ������: %s\n", stack[top]);
            }
            break;

        case 4: // ����
            return 0;

        default:
            printf("�ùٸ� �޴��� �����ϼ���.\n");
        }
    }

    return 0;
}