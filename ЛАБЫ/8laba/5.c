#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#define SIZE 5

// Функция для сортировки методом стандартного обмена (Bubble Sort)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функция для сортировки масива от большего к меньшему методом стандартного обмена (Bubble Sort)
void bubbleSortDescending(int arr[], int n) {
   for (int i = 0; i < n - 1; i++) {
       for (int j = 0; j < n - i - 1; j++) {
           if (arr[j] < arr[j + 1]) {
               int temp = arr[j];
               arr[j] = arr[j + 1];
               arr[j + 1] = temp;
           }
       }
   }
}


// Функция для интерполяционного поиска
bool interpolationSearch(int arr[], int target) {
    int low = 0, high = SIZE - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) {
                return true;
            }
            return false;
        }

        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));

        if (arr[pos] == target) {
            return true;
        }

        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
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

    // Сортировка методом стандартного обмена (Bubble Sort)
    bubbleSort(values, SIZE);

    // Поиск интерполяционным методом
    bool found = interpolationSearch(values, target);

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
