#include <stdio.h>
#include <string.h>

int main() {
    char N[100];
    printf("Enter a decimal number N: ");
    scanf("%s", N);

    // Инициализация переменной для определения наличия цифры 3
    int flag = 0;

    // Длина строки N
    int len = strlen(N);

    // Цикл for для перебора всех цифр строки
    for (int i = 0; i < len; i++) {
        // Если цифра i равна 3, то увеличить переменную flag на 1 и выйти из цикла
        if (N[i] == '3') {
            flag = 1;
            break;
        }
    }

    // Если цифра 3 была найдена, то вывести 1 иначе вывести 0
    if (flag) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
