#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

// Функция для сортировки методом центрированной вставки
void centeredInsertion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0, right = i - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (key < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }
}

// Функция для сортировки масива от большего к меньшему методом центрированной вставки
void centeredInsertionDescending(int arr[], int n) {
   for (int i = 1; i < n; i++) {
       int key = arr[i];
       int left = 0, right = i - 1;

       while (left <= right) {
           int mid = left + (right - left) / 2;
           if (key > arr[mid]) {
               right = mid - 1;
           } else {
               left = mid + 1;
           }
       }

       for (int j = i - 1; j >= left; j--) {
           arr[j + 1] = arr[j];
       }
       arr[left] = key;
   }
}


// Функция для бинарного поиска
bool binarySearch(int arr[], int target) {
    int low = 0, high = SIZE - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return true;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    int values[SIZE];

    printf("Введите 5 чисел от -100 до 100:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Значение %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    int target;
    printf("Введите значение для поиска: ");
    scanf("%d", &target);

    centeredInsertion(values, SIZE);

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
