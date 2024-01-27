#include <stdio.h>
#include <windows.h>

int main() 
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);   
    int A[27] = {27, 12, 5, 19, 8, 2, 17, 7, 21, 9, 14, 3, 23, 10, 4, 25, 16, 11, 6, 20, 15, 1, 18, 13, 24, 22, 26};
    int n = 27;

    //Сортируем массив A в порядке возрастания
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    //Переставляем элементы массива в соответствии с задачей
    for (int i = 0; i < n / 2; i++) {
        int temp = A[i];
        A[i] = A[n - i - 1];
        A[n - i - 1] = temp;
    }

    //Выводим результат
    printf("Массив после перестановки:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
