#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#define SIZE 5

// Функция для быстрой сортировки (Quick Sort)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
// Функция для сортировки масива от большего к меньшему методом быстрой сортировки (Quick Sort)
void quickSortDescending(int arr[], int low, int high) {
   if (low < high) {
       int pivot = arr[low];
       int i = high + 1;

       for (int j = low + 1; j <= high; j++) {
           if (arr[j] > pivot) {
               i--;
               int temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
           }
       }
       int temp = arr[i - 1];
       arr[i - 1] = arr[low];
       arr[low] = temp;

       int pi = i - 1;

       quickSortDescending(arr, low, pi - 1);
       quickSortDescending(arr, pi + 1, high);
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

    // Сортировка методом быстрой сортировки
    quickSort(values, 0, SIZE - 1);

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
