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
    구조체 선언
 --------------------------------*/
typedef struct {
    int id;
    char name[NAME_LEN];
    int age;
    double score;
} Student;

/* -------------------------------
   함수 프로토타입
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
   메인 함수
--------------------------------*/
int main(void)
{
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice = 0;

    count = load_students(students);

    printf("=====================================\n");
    printf("   학생 관리 프로그램 (기본 예제)\n");
    printf("=====================================\n");

    do {
        print_menu();
        choice = get_int_input("메뉴 선택: ");

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
            printf("데이터 저장 완료!\n");
            break;
        case 0:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 선택입니다. 다시 입력하세요.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}

/* -------------------------------
   메뉴 출력
--------------------------------*/
void print_menu(void)
{
    printf("\n----------- 메뉴 -----------\n");
    printf("1. 학생 추가\n");
    printf("2. 전체 학생 목록 보기\n");
    printf("3. 학생 검색\n");
    printf("4. 학생 정보 수정\n");
    printf("5. 학생 삭제\n");
    printf("6. 파일 저장\n");
    printf("0. 종료\n");
    printf("---------------------------\n");
}

/* -------------------------------
   학생 추가
--------------------------------*/
void add_student(Student* list, int* count)
{
    if (*count >= MAX_STUDENTS) {
        printf("더 이상 학생을 추가할 수 없습니다.\n");
        return;
    }

    Student s;
    s.id = (*count) + 1;

    printf("학생 이름 입력: ");
    fgets(s.name, NAME_LEN, stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    s.age = get_int_input("학생 나이 입력: ");
    s.score = get_double_input("학생 점수 입력: ");

    list[*count] = s;
    (*count)++;

    printf("학생이 추가되었습니다! (ID: %d)\n", s.id);
}

/* -------------------------------
   전체 학생 목록
--------------------------------*/
void list_students(const Student* list, int count)
{
    int i;
    if (count == 0) {
        printf("등록된 학생이 없습니다.\n");
        return;
    }

    printf("\n------ 학생 목록 (%d명) ------\n", count);
    for (i = 0; i < count; i++) {
        printf("[%d] 이름: %-10s | 나이: %2d | 점수: %.2f\n",
            list[i].id, list[i].name, list[i].age, list[i].score);
    }
}

/* -------------------------------
   학생 검색
--------------------------------*/
void search_student(const Student* list, int count)
{
    if (count == 0) {
        printf("검색할 학생이 없습니다.\n");
        return;
    }

    char target[NAME_LEN];
    printf("검색할 이름을 입력: ");
    fgets(target, NAME_LEN, stdin);
    target[strcspn(target, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(list[i].name, target) == 0) {
            printf("ID: %d | 이름: %s | 나이: %d | 점수: %.2f\n",
                list[i].id, list[i].name, list[i].age, list[i].score);
            found = 1;
        }
    }

    if (!found) {
        printf("'%s' 이름의 학생을 찾을 수 없습니다.\n", target);
    }
}

/* -------------------------------
   학생 수정
--------------------------------*/
void update_student(Student* list, int count)
{
    if (count == 0) {
        printf("수정할 학생이 없습니다.\n");
        return;
    }

    int id = get_int_input("수정할 학생 ID 입력: ");
    if (id <= 0 || id > count) {
        printf("잘못된 ID입니다.\n");
        return;
    }

    Student* s = &list[id - 1];

    printf("현재 이름: %s → 새 이름: ", s->name);
    fgets(s->name, NAME_LEN, stdin);
    s->name[strcspn(s->name, "\n")] = '\0';

    s->age = get_int_input("새 나이 입력: ");
    s->score = get_double_input("새 점수 입력: ");

    printf("학생 정보가 수정되었습니다.\n");
}

/* -------------------------------
   학생 삭제
--------------------------------*/
void delete_student(Student* list, int* count)
{
    if (*count == 0) {
        printf("삭제할 학생이 없습니다.\n");
        return;
    }

    int id = get_int_input("삭제할 학생 ID 입력: ");
    if (id <= 0 || id > *count) {
        printf("잘못된 ID입니다.\n");
        return;
    }

    for (int i = id - 1; i < (*count) - 1; i++) {
        list[i] = list[i + 1];
    }

    (*count)--;

    printf("학생(ID: %d)이 삭제되었습니다.\n", id);
}

/* -------------------------------
   파일 저장
--------------------------------*/
void save_students(const Student* list, int count)
{
    FILE* fp = fopen(FILE_NAME, "w");
    if (fp == NULL) {
        printf("파일 열기 실패!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d,%s,%d,%.2f\n",
            list[i].id, list[i].name, list[i].age, list[i].score);
    }

    fclose(fp);
}

/* -------------------------------
   파일 불러오기
--------------------------------*/
int load_students(Student* list)
{
    FILE* fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        return 0; // 파일 없으면 0명
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
   입력 유틸 함수
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

        printf("유효한 정수를 입력하세요.\n");
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

        printf("유효한 실수를 입력하세요.\n");
    }
}

void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}