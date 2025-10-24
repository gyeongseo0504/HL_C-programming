#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * =========================================
 *  Basic C Language Example (~300 lines)
 *  - Structure + Function + File I/O
 *  - Simple Student Management System
 *  Author: Hong Gyeongseo
 * =========================================
 */

#define MAX_STUDENTS 100
#define NAME_LEN     50
#define FILE_NAME    "students.txt"

 /* -------------------------------
    ����ü ����
 --------------------------------*/
typedef struct {
    int id;
    char name[NAME_LEN];
    int age;
    double score;
} Student;

/* -------------------------------
   �Լ� ������Ÿ��
--------------------------------*/
void print_menu(void);
void add_student(Student* list, int* count);
void list_students(const Student* list, int count);
void search_student(const Student* list, int count);
void save_students(const Student* list, int count);
int  load_students(Student* list);
void delete_student(Student* list, int* count);
void update_student(Student* list, int count);
int  get_int_input(const char* msg);
double get_double_input(const char* msg);
void clear_input_buffer(void);

/* -------------------------------
   ���� �Լ�
--------------------------------*/
int main(void)
{
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice = 0;

    count = load_students(students);

    printf("=====================================\n");
    printf("   �л� ���� ���α׷� (�⺻ ����)\n");
    printf("=====================================\n");

    do {
        print_menu();
        choice = get_int_input("�޴� ����: ");

        switch (choice) {
        case 1:
            add_student(students, &count);
            break;
        case 2:
            list_students(students, count);
            break;
        case 3:
            search_student(students, count);
            break;
        case 4:
            update_student(students, count);
            break;
        case 5:
            delete_student(students, &count);
            break;
        case 6:
            save_students(students, count);
            printf("������ ���� �Ϸ�!\n");
            break;
        case 0:
            printf("���α׷��� �����մϴ�.\n");
            break;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �Է��ϼ���.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}

/* -------------------------------
   �޴� ���
--------------------------------*/
void print_menu(void)
{
    printf("\n----------- �޴� -----------\n");
    printf("1. �л� �߰�\n");
    printf("2. ��ü �л� ��� ����\n");
    printf("3. �л� �˻�\n");
    printf("4. �л� ���� ����\n");
    printf("5. �л� ����\n");
    printf("6. ���� ����\n");
    printf("0. ����\n");
    printf("---------------------------\n");
}

/* -------------------------------
   �л� �߰�
--------------------------------*/
void add_student(Student* list, int* count)
{
    if (*count >= MAX_STUDENTS) {
        printf("�� �̻� �л��� �߰��� �� �����ϴ�.\n");
        return;
    }

    Student s;
    s.id = (*count) + 1;

    printf("�л� �̸� �Է�: ");
    fgets(s.name, NAME_LEN, stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    s.age = get_int_input("�л� ���� �Է�: ");
    s.score = get_double_input("�л� ���� �Է�: ");

    list[*count] = s;
    (*count)++;

    printf("�л��� �߰��Ǿ����ϴ�! (ID: %d)\n", s.id);
}

/* -------------------------------
   ��ü �л� ���
--------------------------------*/
void list_students(const Student* list, int count)
{
    int i;
    if (count == 0) {
        printf("��ϵ� �л��� �����ϴ�.\n");
        return;
    }

    printf("\n------ �л� ��� (%d��) ------\n", count);
    for (i = 0; i < count; i++) {
        printf("[%d] �̸�: %-10s | ����: %2d | ����: %.2f\n",
            list[i].id, list[i].name, list[i].age, list[i].score);
    }
}

/* -------------------------------
   �л� �˻�
--------------------------------*/
void search_student(const Student* list, int count)
{
    if (count == 0) {
        printf("�˻��� �л��� �����ϴ�.\n");
        return;
    }

    char target[NAME_LEN];
    printf("�˻��� �̸��� �Է�: ");
    fgets(target, NAME_LEN, stdin);
    target[strcspn(target, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(list[i].name, target) == 0) {
            printf("ID: %d | �̸�: %s | ����: %d | ����: %.2f\n",
                list[i].id, list[i].name, list[i].age, list[i].score);
            found = 1;
        }
    }

    if (!found) {
        printf("'%s' �̸��� �л��� ã�� �� �����ϴ�.\n", target);
    }
}

/* -------------------------------
   �л� ����
--------------------------------*/
void update_student(Student* list, int count)
{
    if (count == 0) {
        printf("������ �л��� �����ϴ�.\n");
        return;
    }

    int id = get_int_input("������ �л� ID �Է�: ");
    if (id <= 0 || id > count) {
        printf("�߸��� ID�Դϴ�.\n");
        return;
    }

    Student* s = &list[id - 1];

    printf("���� �̸�: %s �� �� �̸�: ", s->name);
    fgets(s->name, NAME_LEN, stdin);
    s->name[strcspn(s->name, "\n")] = '\0';

    s->age = get_int_input("�� ���� �Է�: ");
    s->score = get_double_input("�� ���� �Է�: ");

    printf("�л� ������ �����Ǿ����ϴ�.\n");
}

/* -------------------------------
   �л� ����
--------------------------------*/
void delete_student(Student* list, int* count)
{
    if (*count == 0) {
        printf("������ �л��� �����ϴ�.\n");
        return;
    }

    int id = get_int_input("������ �л� ID �Է�: ");
    if (id <= 0 || id > *count) {
        printf("�߸��� ID�Դϴ�.\n");
        return;
    }

    for (int i = id - 1; i < (*count) - 1; i++) {
        list[i] = list[i + 1];
    }

    (*count)--;

    printf("�л�(ID: %d)�� �����Ǿ����ϴ�.\n", id);
}

/* -------------------------------
   ���� ����
--------------------------------*/
void save_students(const Student* list, int count)
{
    FILE* fp = fopen(FILE_NAME, "w");
    if (fp == NULL) {
        printf("���� ���� ����!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d,%s,%d,%.2f\n",
            list[i].id, list[i].name, list[i].age, list[i].score);
    }

    fclose(fp);
}

/* -------------------------------
   ���� �ҷ�����
--------------------------------*/
int load_students(Student* list)
{
    FILE* fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        return 0; // ���� ������ 0��
    }

    int count = 0;
    while (fscanf(fp, "%d,%49[^,],%d,%lf\n",
        &list[count].id,
        list[count].name,
        &list[count].age,
        &list[count].score) == 4)
    {
        count++;
        if (count >= MAX_STUDENTS) {
            break;
        }
    }

    fclose(fp);
    return count;
}

/* -------------------------------
   �Է� ��ƿ �Լ�
--------------------------------*/
int get_int_input(const char* msg)
{
    char line[64];
    int value;

    for (;;) {
        printf("%s", msg);
        if (fgets(line, sizeof(line), stdin) == NULL) {
            return 0;
        }

        if (sscanf(line, "%d", &value) == 1) {
            return value;
        }

        printf("��ȿ�� ������ �Է��ϼ���.\n");
    }
}

double get_double_input(const char* msg)
{
    char line[64];
    double value;

    for (;;) {
        printf("%s", msg);
        if (fgets(line, sizeof(line), stdin) == NULL) {
            return 0.0;
        }

        if (sscanf(line, "%lf", &value) == 1) {
            return value;
        }

        printf("��ȿ�� �Ǽ��� �Է��ϼ���.\n");
    }
}

void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}