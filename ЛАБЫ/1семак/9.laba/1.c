#include <stdio.h>
#include <stdlib.h>

// Функция для вычисления факториала числа
int factorial(int n) {
 if (n == 0 || n == 1) {
   return 1;
 }
 else {
   return n * factorial(n - 1);
 }
}

// Функция для вычисления знака перестановки
int sign(int *p, int n) {
 int inversions = 0; // количество инверсий в перестановке
 for (int i = 0; i < n - 1; i++) {
   for (int j = i + 1; j < n; j++) {
     if (p[i] > p[j]) {
       inversions++;
     }
   }
 }
 if (inversions % 2 == 0) {
   return 1; // четная перестановка
 }
 else {
   return -1; // нечетная перестановка
 }
}

// Функция для вычисления определителя матрицы
int det(int **A, int n) {
 if (n == 1) {
   return A[0][0]; // определитель матрицы 1 x 1
 }
 else {
   int sum = 0; // сумма по формуле
   int *p = (int *)malloc(n * sizeof(int)); // массив для хранения перестановки
   for (int i = 0; i < n; i++) {
     p[i] = i + 1; // инициализация перестановки
   }
   int count = 0; // счетчик перестановок
   int max = factorial(n); // максимальное количество перестановок
   while (count < max) {
     int product = 1; // произведение по формуле
     for (int i = 0; i < n; i++) {
       product *= A[i][p[i] - 1]; // умножение элементов матрицы
     }
     sum += sign(p, n) * product; // добавление слагаемого с учетом знака
     // Генерация следующей перестановки в лексикографическом порядке
     int k = n - 2;
     while (k >= 0 && p[k] > p[k + 1]) {
       k--;
     }
     if (k >= 0) {
       int l = n - 1;
       while (l > k && p[l] < p[k]) {
         l--;
       }
       int temp = p[k];
       p[k] = p[l];
       p[l] = temp;
       for (int i = k + 1, j = n - 1; i < j; i++, j--) {
         temp = p[i];
         p[i] = p[j];
         p[j] = temp;
       }
     }
     count++;
   }
   free(p); // освобождение памяти
   return sum; // возврат определителя
 }
}

// Главная функция для тестирования
int main() {
    int n = 3; // размер матрицы
    int **A = (int **)malloc(n * sizeof(int *)); // выделение памяти для матрицы
    for (int i = 0; i < n; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
    }

    // Заполнение матрицы
    A[0][0] = 8;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 4;
    A[1][1] = 5;
    A[1][2] = 6;
    A[2][0] = 7;
    A[2][1] = 8;
    A[2][2] = 9;
    // Вывод матрицы
    printf("Матрица A:\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    // Вычисление и вывод определителя
    int d = det(A, n);
    printf("Определитель A: %d\n", d);
    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    return 0;

}