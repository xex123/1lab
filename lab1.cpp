#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");
    
    int rows, cols;

    printf("Введите количество строк: ");
    scanf_s("%d", &rows);
    printf("Введите количество столбцов: ");
    scanf_s("%d", &cols);

    int** array = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("Массив:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = rand() % 150 - 75;
            printf("%5d", array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += array[i][j];
        }
        printf("Сумма строки: %d\n", rowSum);
    }

    for (int j = 0; j < cols; j++) {
        int columnSum = 0;
        for (int i = 0; i < rows; i++) {
            columnSum += array[i][j];
        }
        printf("Сумма столбца: %d\n", columnSum);
    }

    for (int i = 0; i < rows; ++i) {
        free(array[i]);
    }
    free(array);
    return 0;
}