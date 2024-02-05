#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROWS_A 5
#define COLS_A 7
#define ROWS_B 7
#define COLS_B 7

// Функция для удаления столбца из матрицы
void deleteColumn(int matrix[][COLS_A], int rows, int *cols, int colToDelete) 
{
    for (int i = 0; i < rows; i++) {
        for (int j = colToDelete; j < *cols - 1; j++) {
            matrix[i][j] = matrix[i][j + 1];
        }
    }
    (*cols)--;
}

// Функция для автоматического заполнения матриц случайными значениями от -10 до 10
void fillMatrixRandom(int matrix[][COLS_A], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 21 - 10; // Генерация случайных чисел от -10 до 10
        }
    }
}

// Функция для вывода матрицы
void printMatrix(int matrix[][COLS_A], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);   
    int matrixA[ROWS_A][COLS_A]; // Матрица A
    int matrixB[ROWS_B][COLS_B]; // Матрица B

    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Автоматическое заполнение матриц A и B случайными значениями
    fillMatrixRandom(matrixA, ROWS_A, COLS_A);
    fillMatrixRandom(matrixB, ROWS_B, COLS_B);

    // Вывод исходных матриц A и B
    printf("Исходная матрица A:\n");
    printMatrix(matrixA, ROWS_A, COLS_A);

    printf("\nИсходная матрица B:\n");
    printMatrix(matrixB, ROWS_B, COLS_B);

    int colsA = COLS_A; // Переменная для хранения размерности столбцов A
    int colsB = COLS_B; // Переменная для хранения размерности столбцов B

    // Удаление столбцов из матрицы A, содержащих не менее 2 отрицательных элементов
    for (int j = 0; j < colsA; ) {
        int negativeCount = 0;
        for (int i = 0; i < ROWS_A; i++) {
            if (matrixA[i][j] < 0) {
                negativeCount++;
            }
        }
        if (negativeCount >= 2) {
            deleteColumn(matrixA, ROWS_A, &colsA, j);
        } else {
            j++;
        }
    }

    // Удаление столбцов из матрицы B, содержащих не менее 3 отрицательных элементов
    for (int j = 0; j < colsB; ) {
        int negativeCount = 0;
        for (int i = 0; i < ROWS_B; i++) {
            if (matrixB[i][j] < 0) {
                negativeCount++;
            }
        }
        if (negativeCount >= 3) {
            deleteColumn(matrixB, ROWS_B, &colsB, j);
        } else {
            j++;
        }
    }

    // Вывод обновленных матриц A и B
    printf("\nМатрица A после удаления столбцов:\n");
    printMatrix(matrixA, ROWS_A, colsA);

    printf("\nМатрица B после удаления столбцов:\n");
    printMatrix(matrixB, ROWS_B, colsB);

    return 0;
}
