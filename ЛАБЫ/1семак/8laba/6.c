#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#define SIZE 5

// Функция для сортировки методом линейной вставки
void linearInsertion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Функция для сортировки масива от большего к меньшему методом линейной вставки
void linearInsertionDescending(int arr[], int n) {
   for (int i = 1; i < n; i++) {
       int key = arr[i];
       int j = i - 1;

       while (j >= 0 && arr[j] < key) {
           arr[j + 1] = arr[j];
           j = j - 1;
       }
       arr[j + 1] = key;
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

    // Сортировка методом линейной вставки
    linearInsertion(values, SIZE);

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
