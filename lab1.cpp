#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");
    int size = 0;
    int* mass = (int*)malloc(size * sizeof(int));
    int max = INT_MIN;
    int min = INT_MAX;
    printf("Введите количество элементов: ");
    scanf_s("%d", &size);
    for (int i = 0; i < size; i++) {
        mass[i] = -1000 + rand() % 2001;
        printf("%d ", mass[i]);
        if (mass[i] < min) {
            min = mass[i];
        }
        if (mass[i] > max) {
            max = mass[i];
        }
    }

    printf("\nМаксимальное: %d\nМинимальное: %d\nИх разница = %d\n", max, min, max - min);

    free(mass);

    return 0;
}