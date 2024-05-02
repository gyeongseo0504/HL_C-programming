#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 5

int main()
{
    char stack[SIZE][20] = { "None", "None", "None", "None", "None" }; // 스택 배열
    int top = -1; // 스택의 top을 나타내는 변수

    char data[20]; // 입력 받을 데이터를 저장할 배열

    while (1)
    {
        int choice;
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Push
            if (top == SIZE - 1)
            {
                printf("스택이 꽉 찼음\n");
            }
            else
            {
                printf("저장할 데이터를 입력하세요: ");
                scanf("%s", data);
                top++;
                strcpy(stack[top], data);
            }
            break;

        case 2: // Pop
            if (top == -1)
            {
                printf("스택이 비어 있음\n");
            }
            else {
                printf("Pop된 데이터: %s\n", stack[top]);
                top--;
            }
            break;

        case 3: // Top
            if (top == -1)
            {
                printf("스택이 비어 있음\n");
            }
            else {
                printf("Top 데이터: %s\n", stack[top]);
            }
            break;

        case 4: // 종료
            return 0;

        default:
            printf("올바른 메뉴를 선택하세요.\n");
        }
    }

    return 0;
}