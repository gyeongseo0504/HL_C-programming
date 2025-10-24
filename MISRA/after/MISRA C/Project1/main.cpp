/* main.cpp
 * Student Manager (C++, ASCII-only, ~340 lines)
 * - PC-lint Plus / MISRA-friendly baseline for C++ compilation
 * - Use <cX> headers and std:: namespace
 * - No POSIX-only calls; no non-ASCII string literals
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

 /* =========================
  * Configuration
  * ========================= */
#define MAX_STUDENTS 100
#define NAME_LEN     50
#define FILE_NAME    "students.txt"

  /* =========================
   * Typedef-like aliases (Directive 4.6 awareness)
   * ========================= */
using s32 = int;
using f64 = double;

/* =========================
 * Data Types
 * ========================= */
struct Student {
    s32  id;
    char name[NAME_LEN];
    s32  age;
    f64  score;
};

/* =========================
 * Function Prototypes (internal linkage via static)
 * ========================= */
static void app_banner(void);
static void print_menu(void);
static void pause_enter(void);

/* Core features */
static void add_student(Student* list, s32* count);
static void list_students(const Student* list, s32 count);
static void search_student(const Student* list, s32 count);
static void update_student(Student* list, s32 count);
static void delete_student(Student* list, s32* count);

/* File I/O */
static void save_students(const Student* list, s32 count);
static s32  load_students(Student* list);

/* Utilities */
static s32  get_int_input(const char* msg);
static f64  get_double_input(const char* msg);

/* safer helpers */
static void trim_newline(char* s, std::size_t cap);
static s32  safe_read_line(char* buf, s32 buf_sz);
static s32  is_valid_name(const char* s);

/* Case-insensitive compare (portable, C++ headers) */
static s32  ci_strcmp(const char* a, const char* b);

/* Extras: statistics and sorting */
static void stats_students(const Student* list, s32 count);
static void sort_by_name(Student* list, s32 count);
static void sort_by_score_desc(Student* list, s32 count);

/* =========================
 * Main
 * ========================= */
int main(void)
{
    Student students[MAX_STUDENTS];
    s32 count = 0;
    s32 choice = -1;

    /* Initialize array */
    for (s32 i = 0; i < MAX_STUDENTS; i++) {
        students[i].id = 0;
        students[i].name[0] = '\0';
        students[i].age = 0;
        students[i].score = 0.0;
    }

    count = load_students(students);

    app_banner();

    do {
        print_menu();
        choice = get_int_input("Select menu: ");

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
            std::printf("Saved.\n");
            break;
        case 7:
            stats_students(students, count);
            break;
        case 8:
            sort_by_name(students, count);
            std::printf("Sorted by name (A-Z).\n");
            break;
        case 9:
            sort_by_score_desc(students, count);
            std::printf("Sorted by score (high to low).\n");
            break;
        case 0:
            std::printf("Bye.\n");
            break;
        default:
            std::printf("Invalid menu.\n");
            break;
        }

        if (choice != 0) {
            pause_enter();
        }
    } while (choice != 0);

    return 0;
}

/* =========================
 * UI Helpers
 * ========================= */
static void app_banner(void)
{
    std::printf("=============================================\n");
    std::printf("  Student Manager (C++ / ASCII / Lint-friendly)\n");
    std::printf("=============================================\n");
}

static void print_menu(void)
{
    std::printf("\n--------------- MENU ---------------\n");
    std::printf("1. Add student\n");
    std::printf("2. List students\n");
    std::printf("3. Search student\n");
    std::printf("4. Update student\n");
    std::printf("5. Delete student\n");
    std::printf("6. Save to file\n");
    std::printf("7. Show statistics\n");
    std::printf("8. Sort by name (A-Z)\n");
    std::printf("9. Sort by score (high to low)\n");
    std::printf("0. Exit\n");
    std::printf("------------------------------------\n");
}

static void pause_enter(void)
{
    char line[8];
    std::printf("Press ENTER to continue...");
    (void)std::fgets(line, (int)sizeof(line), stdin);
}

/* =========================
 * Add
 * ========================= */
static void add_student(Student* list, s32* count)
{
    Student s;
    char name_buf[NAME_LEN];

    if (*count >= MAX_STUDENTS) {
        std::printf("List full.\n");
        return;
    }

    s.id = (*count) + 1;
    s.name[0] = '\0';
    s.age = 0;
    s.score = 0.0;

    std::printf("Name: ");
    if (safe_read_line(name_buf, (s32)NAME_LEN) == 0) {
        std::printf("Input failed.\n");
        return;
    }
    trim_newline(name_buf, NAME_LEN);

    if (is_valid_name(name_buf) == 0) {
        std::printf("Invalid name.\n");
        return;
    }
    (void)std::strncpy(s.name, name_buf, (std::size_t)NAME_LEN - 1U);
    s.name[NAME_LEN - 1] = '\0';

    s.age = get_int_input("Age: ");
    s.score = get_double_input("Score: ");

    list[*count] = s;
    (*count)++;

    std::printf("Added (ID: %d)\n", s.id);
}

/* =========================
 * List
 * ========================= */
static void list_students(const Student* list, s32 count)
{
    if (count <= 0) {
        std::printf("Empty.\n");
        return;
    }

    std::printf("\n---------- Students (%d) ----------\n", count);
    for (s32 i = 0; i < count; i++) {
        std::printf("[%d] Name: %-12s | Age: %2d | Score: %6.2f\n",
            list[i].id, list[i].name, list[i].age, list[i].score);
    }
}

/* =========================
 * Search
 * ========================= */
static void search_student(const Student* list, s32 count)
{
    char target[NAME_LEN];
    s32 found = 0;

    if (count <= 0) {
        std::printf("Nothing to search.\n");
        return;
    }

    std::printf("Name to search: ");
    if (safe_read_line(target, (s32)NAME_LEN) == 0) {
        std::printf("Input failed.\n");
        return;
    }
    trim_newline(target, NAME_LEN);

    for (s32 i = 0; i < count; i++) {
        if (ci_strcmp(list[i].name, target) == 0) {
            std::printf("ID:%d | Name:%s | Age:%d | Score:%.2f\n",
                list[i].id, list[i].name, list[i].age, list[i].score);
            found = 1;
        }
    }

    if (found == 0) {
        std::printf("No match for '%s'.\n", target);
    }
}

/* =========================
 * Update
 * ========================= */
static void update_student(Student* list, s32 count)
{
    if (count <= 0) {
        std::printf("Nothing to update.\n");
        return;
    }

    s32 id = get_int_input("ID to update: ");
    if ((id <= 0) || (id > count)) {
        std::printf("Invalid ID.\n");
        return;
    }

    Student* s = &list[id - 1];

    std::printf("Current name: %s\n", s->name);
    std::printf("New name: ");
    char buf[NAME_LEN];
    if (safe_read_line(buf, (s32)NAME_LEN) == 0) {
        std::printf("Input failed.\n");
        return;
    }
    trim_newline(buf, NAME_LEN);
    if (is_valid_name(buf) == 0) {
        std::printf("Invalid name.\n");
        return;
    }
    (void)std::strncpy(s->name, buf, (std::size_t)NAME_LEN - 1U);
    s->name[NAME_LEN - 1] = '\0';

    s->age = get_int_input("New age: ");
    s->score = get_double_input("New score: ");

    std::printf("Updated.\n");
}

/* =========================
 * Delete
 * ========================= */
static void delete_student(Student* list, s32* count)
{
    if (*count <= 0) {
        std::printf("Nothing to delete.\n");
        return;
    }

    s32 id = get_int_input("ID to delete: ");
    if ((id <= 0) || (id > *count)) {
        std::printf("Invalid ID.\n");
        return;
    }

    for (s32 i = (id - 1); i < (*count - 1); i++) {
        list[i] = list[i + 1];
    }
    (*count)--;

    std::printf("Deleted ID:%d\n", id);
}

/* =========================
 * Save / Load
 * ========================= */
static void save_students(const Student* list, s32 count)
{
    std::FILE* fp = std::fopen(FILE_NAME, "w");
    if (fp == nullptr) {
        std::printf("Open failed.\n");
        return;
    }

    for (s32 i = 0; i < count; i++) {
        (void)std::fprintf(fp, "%d,%s,%d,%.2f\n",
            list[i].id, list[i].name, list[i].age, list[i].score);
    }

    (void)std::fclose(fp);
}

static s32 load_students(Student* list)
{
    std::FILE* fp = std::fopen(FILE_NAME, "r");
    if (fp == nullptr) {
        return 0;
    }

    s32 count = 0;
    while (count < MAX_STUDENTS) {
        Student tmp;
        int n = std::fscanf(fp, "%d,%49[^,],%d,%lf\n",
            &tmp.id, tmp.name, &tmp.age, &tmp.score);
        if (n != 4) {
            break;
        }
        list[count] = tmp;
        count++;
    }

    (void)std::fclose(fp);
    return count;
}

/* =========================
 * Stats and Sorting
 * ========================= */
static void stats_students(const Student* list, s32 count)
{
    if (count <= 0) {
        std::printf("No data.\n");
        return;
    }

    f64 sum = 0.0;
    f64 minv = list[0].score;
    f64 maxv = list[0].score;

    for (s32 i = 0; i < count; i++) {
        f64 v = list[i].score;
        sum += v;
        if (v < minv) { minv = v; }
        if (v > maxv) { maxv = v; }
    }
    f64 avg = sum / (f64)count;

    std::printf("Count: %d | Avg: %.2f | Min: %.2f | Max: %.2f\n",
        count, avg, minv, maxv);
}

/* Simple bubble sort by name (A-Z) */
static void sort_by_name(Student* list, s32 count)
{
    for (s32 i = 0; i < count; i++) {
        for (s32 j = 0; j < (count - 1); j++) {
            if (ci_strcmp(list[j].name, list[j + 1].name) > 0) {
                Student t = list[j];
                list[j] = list[j + 1];
                list[j + 1] = t;
            }
        }
    }
}

/* Simple bubble sort by score (descending) */
static void sort_by_score_desc(Student* list, s32 count)
{
    for (s32 i = 0; i < count; i++) {
        for (s32 j = 0; j < (count - 1); j++) {
            if (list[j].score < list[j + 1].score) {
                Student t = list[j];
                list[j] = list[j + 1];
                list[j + 1] = t;
            }
        }
    }
}

/* =========================
 * Utilities
 * ========================= */
static s32 get_int_input(const char* msg)
{
    char line[64];
    s32 value = 0;
    for (;;) {
        std::printf("%s", msg);
        if (std::fgets(line, (int)sizeof(line), stdin) == nullptr) {
            return 0;
        }
        if (std::sscanf(line, "%d", &value) == 1) {
            return value;
        }
        std::printf("Enter a valid integer.\n");
    }
}

static f64 get_double_input(const char* msg)
{
    char line[64];
    f64 value = 0.0;
    for (;;) {
        std::printf("%s", msg);
        if (std::fgets(line, (int)sizeof(line), stdin) == nullptr) {
            return 0.0;
        }
        if (std::sscanf(line, "%lf", &value) == 1) {
            return value;
        }
        std::printf("Enter a valid real number.\n");
    }
}

/* Trim first '\n' if present, with bound check */
static void trim_newline(char* s, std::size_t cap)
{
    if ((s == nullptr) || (cap == 0U)) {
        return;
    }
    for (std::size_t i = 0U; i < cap && s[i] != '\0'; i++) {
        if (s[i] == '\n') {
            s[i] = '\0';
            break;
        }
    }
}

/* Safe line read: returns 1 on success, 0 on failure */
static s32 safe_read_line(char* buf, s32 buf_sz)
{
    if ((buf == nullptr) || (buf_sz <= 1)) {
        return 0;
    }
    if (std::fgets(buf, buf_sz, stdin) == nullptr) {
        return 0;
    }
    return 1;
}

/* Name must be non-empty printable ASCII and must not include ',' */
static s32 is_valid_name(const char* s)
{
    if ((s == nullptr) || (s[0] == '\0')) {
        return 0;
    }
    for (std::size_t i = 0U; s[i] != '\0'; i++) {
        unsigned char c = (unsigned char)s[i];
        if ((c < 32U) || (c > 126U) || (c == (unsigned char)(','))) {
            return 0;
        }
    }
    return 1;
}

/* Case-insensitive strcmp using std::tolower with unsigned char cast */
static s32 ci_strcmp(const char* a, const char* b)
{
    std::size_t i = 0U;
    while ((a[i] != '\0') && (b[i] != '\0')) {
        int ca = std::tolower((unsigned char)a[i]);
        int cb = std::tolower((unsigned char)b[i]);
        if (ca != cb) {
            return (s32)(ca - cb);
        }
        i++;
    }
    return (s32)((unsigned char)a[i]) - (s32)((unsigned char)b[i]);
}