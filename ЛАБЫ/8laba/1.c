#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define SIZE 5

// Функция для сортировки методом линейного выбора с обменом
void selectionSort(int arr[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
// Функция для сортировки методом линейного выбора с обменом
void selectionSortDescending(int arr[]) {
   for (int i = 0; i < SIZE - 1; i++) {
       int maxIndex = i;
       for (int j = i + 1; j < SIZE; j++) {
           if (arr[j] > arr[maxIndex]) {
               maxIndex = j;
           }
       }
       if (maxIndex != i) {
           int temp = arr[i];
           arr[i] = arr[maxIndex];
           arr[maxIndex] = temp;
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

int main() 
{
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

    // Сортировка методом линейного выбора с обменом
    // в случае обратной сортировки заменить на selectionSortDescending(values)
    selectionSort(values);

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
