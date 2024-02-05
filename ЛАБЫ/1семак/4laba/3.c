#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

int main(void)
{
    int **A;        // Двумерный массив (матрица)
    int n, m, Sp, So;
    double F;
    int i, j;
    bool h;         // Флаг для определения выбора ввода данных

    srand(time(NULL)); // Инициализация генератора случайных чисел

    printf("Would you want to enter the numbers?(1 - yes, 0 - no) ");
    scanf("%d", &h);

    printf("Enter the number of rows and the number of columns: ");
    scanf("%d %d", &n, &m);

    A = (int**)malloc(n * sizeof(int*));  // Выделение памяти под массив указателей

    if(h)
    {
        for (i = 0; i < n; i++)
        {
            A[i] = (int*)malloc(m * sizeof(int)); // Выделение памяти под строки матрицы
            for (j = 0; j < m; j++)
            {
                printf("a[%d][%d] = ", i+1, j+1);
                scanf("%d", &A[i][j]);   // Ввод элементов матрицы
            }
        }
    }
    else if(!h)
    {
        for (i = 0; i < n; i++)
        {
            A[i] = (int*)malloc(m * sizeof(int)); // Выделение памяти под строки матрицы
            for (j = 0; j < m; j++)
                A[i][j] = -100+rand()%200;  // Заполнение матрицы случайными числами от -100 до 100
        }
    }

    // Вывод матрицы
    printf("\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf(" %4d ", A[i][j]);

        printf("\n");
    }

    printf("\n");
    Sp = 0;
    // Вычисление суммы положительных элементов в нечетных строках
    for(i = 1; i <= n; i++)
    {
        if(i%2 != 0)
        {
            for(j = 1; j <= m; j++)
            {
                    if(A[i-1][j-1]>0)
                        Sp += A[i-1][j-1];
            }
        }
    }
    So = 0;
    // Вычисление суммы отрицательных элементов в четных строках
    for(i = 1; i <= n; i++)
    {
        if(i%2 == 0)
        {
            for(j = 1; j <= m; j++)
            {
                if(A[i-1][j-1]<0)
                    So += A[i-1][j-1];
            }
        }
    }

    // Вычисление F
    printf("\n   Sp = %d, So = %d\n\n", Sp, So);
    F = ((double)Sp+(double)So)/(Sp-So); // Вычисление значения F по формуле

    printf("   F = %lf\n\n\n", F); // Вывод значения F

    // Освобождение памяти
    for (i = 0; i < n-1; i++) {
        free(A[i]);
    }
    free(A);

}
