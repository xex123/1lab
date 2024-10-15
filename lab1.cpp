#include <stdio.h>
#include <limits.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");
    int mass[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < 10; i++) {
        printf("%d ", mass[i]);
        if (mass[i] < min) {
            min = mass[i];
        }
        if (mass[i] > max) {
            max = mass[i];
        }
    }

    printf("\nМаксимальное: %d\nМинимальное: %d\nИх разница = %d\n", max, min, max - min);

    return 0;
}