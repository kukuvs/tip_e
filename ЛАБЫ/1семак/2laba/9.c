#include <stdio.h>
#include <windows.h>

// Функция для определения первой цифры числа
int firstDigit(int num) 
{
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

int main() 
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int n, i, num, sum = 0;

    printf("Введите количество чисел (n <= 10): ");
    scanf("%d", &n);

    printf("Введите %d натуральных чисел: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);

        if (firstDigit(num) == num % 10) {
            sum += num;
        }
    }

    printf("Сумма чисел, у которых первая цифра равна последней: %d\n", sum);

    return 0;
}
