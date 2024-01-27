#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#define SIZE 5

// Функция для сортировки Шелла
void shellSort(int arr[]) {
    for (int gap = SIZE / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < SIZE; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
// Функция для сортировки масива от большего к меньшему методом Шелла
void shellSortDescending(int arr[]) {
   for (int gap = SIZE / 2; gap > 0; gap /= 2) {
       for (int i = gap; i < SIZE; i++) {
           int temp = arr[i];
           int j;
           for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
               arr[j] = arr[j - gap];
           }
           arr[j] = temp;
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

    // Сортировка методом сортировки Шелла
    shellSort(values);

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
