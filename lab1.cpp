#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char lastName[50];
    char firstName[50];
    int age;
    int studentID;
} Student;

void findStudent(Student students[], int size, const char* lastName, const char* firstName) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].lastName, lastName) == 0 && strcmp(students[i].firstName, firstName) == 0) {
            printf("Студент найден:\n");
            printf("Фамилия: %s\n", students[i].lastName);
            printf("Имя: %s\n", students[i].firstName);
            printf("Возраст: %d\n", students[i].age);
            printf("Номер зачетной книжки: %d\n", students[i].studentID);
            found = 1;
        }
    }
    if (!found) {
        printf("Студент не найден\n");
    }
}

int main() {

    setlocale(LC_ALL, "Rus");

    Student students[] = {
        {"Корякин", "Илья", 20, 1001},
        {"Шабанов", "Максим", 22, 1002},
        {"Давыдов", "Денис", 21, 1003}
    };
    int size = sizeof(students) / sizeof(students[0]);

    char lastName[50];
    char firstName[50];

    printf("Введите фамилию студента: ");
    fgets(lastName, sizeof(lastName), stdin);
    lastName[strcspn(lastName, "\n")] = 0;

    printf("Введите имя студента: ");
    fgets(firstName, sizeof(firstName), stdin);
    firstName[strlen(firstName) - 1] = 0;

    findStudent(students, size, lastName, firstName);

    return 0;
}