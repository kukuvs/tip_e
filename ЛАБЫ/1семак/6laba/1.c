#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

bool canRepresentAsUnsignedShortInt(const char* numberString) {
    // Преобразование строки в число типа unsigned long long (64-битное беззнаковое целое число)
    unsigned long long number = strtoull(numberString, NULL, 10);

    // Проверка, может ли число быть представлено в формате unsigned short int (16-битное беззнаковое целое число)
    return number <= USHRT_MAX; // USHRT_MAX - максимальное значение типа unsigned short int
}

int main() 
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);   
    char numberString[50];

    printf("Введите натуральное десятичное число: ");
    scanf("%s", numberString);

    if (canRepresentAsUnsignedShortInt(numberString)) {
        printf("Число можно представить в формате unsigned short int.\n");
    } else {
        printf("Число нельзя представить в формате unsigned short int.\n");
    }

    return 0;
}
