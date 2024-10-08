#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Функция для вставки числа 100 после второго положительного элемента массива
void second() {
    int a, tic, i, temp, *A, n; // Переменные для работы с массивом
    bool h; // Переменная для определения пользовательского ввода

    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Запрос у пользователя о вводе или автозаполнении массива
    printf("Would you want to enter the numbers?(1 - yes, 0 - no) ");
    scanf("%d", &h);

    // Запрос размера массива
    printf("Enter the size of the array: ");
    scanf("%d", &a);

    A = (int*)malloc(a * sizeof(int)); // Выделение памяти под массив

    // Заполнение массива пользователем или случайными числами
    if(h) {
        for(i = 0; i < a; i++) {
            printf("A[%d] = ", i);
            scanf("%d", &A[i]);
        }
    } else if(!h) {
        for(i = 0; i < a; i++)
            A[i] = -100 + rand() % 200;
    }

    n = 0; // Счетчик положительных элементов
    // Находим индекс второго положительного элемента
    for(i = 0; i < a; i++) {
        if(A[i] > 0)
            n++;
        if(n == 2) {
            i++;
            break;
        }
    }

    // Если в массиве меньше двух положительных элементов, выводим сообщение об ошибке
    if(n < 2)
        printf("The array is incorrect!\n\n");
    else {
        printf("\nBefore sort: \n\n");
        // Выводим исходный массив на экран
        for(int r = 0; r < a; r++)
            printf("%d\t", A[r]);

        a++; // Увеличиваем размер массива на 1
        A = realloc(A, a * sizeof(int)); // Перевыделяем память для увеличенного массива
        temp = A[i];
        A[i] = 100; // Вставляем число 100 после второго положительного элемента
        tic = A[i + 1];
        A[i + 1] = temp;

        // Сдвигаем остальные элементы к концу массива
        for(int j = a - 1; j > i + 1; j--)
            A[j] = A[j - 1];
        A[i + 2] = tic;

        printf("\n\nAfter sort: \n\n");
        // Выводим измененный массив на экран
        for(i = 0; i < a; i++)
            printf("%d\t", A[i]);

        printf("\n");
    }
    free(A); // Освобождаем выделенную память для массива
}

int main() {
    second(); // Вызываем функцию для вставки числа 100 после второго положительного элемента
    return 0;
}
