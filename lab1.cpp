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
            printf("������� ������:\n");
            printf("�������: %s\n", students[i].lastName);
            printf("���: %s\n", students[i].firstName);
            printf("�������: %d\n", students[i].age);
            printf("����� �������� ������: %d\n", students[i].studentID);
            found = 1;
        }
    }
    if (!found) {
        printf("������� �� ������\n");
    }
}

int main() {

    setlocale(LC_ALL, "Rus");

    Student students[] = {
        {"�������", "����", 20, 1001},
        {"�������", "������", 22, 1002},
        {"�������", "�����", 21, 1003}
    };
    int size = sizeof(students) / sizeof(students[0]);

    char lastName[50];
    char firstName[50];

    printf("������� ������� ��������: ");
    fgets(lastName, sizeof(lastName), stdin);
    lastName[strcspn(lastName, "\n")] = 0;

    printf("������� ��� ��������: ");
    fgets(firstName, sizeof(firstName), stdin);
    firstName[strlen(firstName) - 1] = 0;

    findStudent(students, size, lastName, firstName);

    return 0;
}