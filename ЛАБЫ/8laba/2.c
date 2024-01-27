#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#define SIZE 5

// Функция для челночной сортировки
void combSort(int arr[]) {
    int gap = SIZE;
    float shrink = 1.3;
    bool sorted = false;

    while (!sorted) {
        gap = (int)(gap / shrink);
        if (gap > 1) {
            sorted = false;
        } else {
            gap = 1;
            sorted = true;
        }

        int i = 0;
        while (i + gap < SIZE) {
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                sorted = false;
            }
            i++;
        }
    }
}
// Функция для сортировки масива от большего к меньшему методом челночной сортировки
void combSortDescending(int arr[]) {
   int gap = SIZE;
   float shrink = 1.3;
   bool sorted = false;

   while (!sorted) {
       gap = (int)(gap / shrink);
       if (gap > 1) {
           sorted = false;
       } else {
           gap = 1;
           sorted = true;
       }

       int i = 0;
       while (i + gap < SIZE) {
           if (arr[i] < arr[i + gap]) {
               int temp = arr[i];
               arr[i] = arr[i + gap];
               arr[i + gap] = temp;
               sorted = false;
           }
           i++;
       }
   }
}

// Функция для бинарного поиска
bool binarySearch(int arr[], int target) {
    int left = 0, right = SIZE - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int values[SIZE];

    printf("Введите 5 чисел от -100 до 100:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Значение %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    int target;
    printf("Введите значение для поиска: ");
    scanf("%d", &target);

    // Сортировка методом челночной сортировки
    combSort(values);

    // Поиск бинарным поиском
    bool found = binarySearch(values, target);

    if (found) {
        printf("Значение %d найдено.\n", target);
    } else {
        printf("Значение %d не найдено.\n", target);
    }

    printf("Отсортированный список:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");

    return 0;
}
