#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Функция для замены первого и последнего символов в словах строки
void swapFirstAndLastChars(char *str) {
    int len = strlen(str);
    int start = 0;

    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') { // Проверка на конец слова
            int end = i - 1;

            if (start < end) { // Если слово состоит более чем из одного символа
                char temp = str[start]; // Сохраняем первый символ
                str[start] = str[end]; // Заменяем первый символ последним
                str[end] = temp; // Заменяем последний символ сохраненным первым
            }

            start = i + 1; // Устанавливаем начало нового слова
        }
    }
}

int main() {
    char inputString[100];

    printf("Введите строку (до точки): ");
    fgets(inputString, sizeof(inputString), stdin);

    // Удаляем символ новой строки, если он присутствует в строке
    int len = strlen(inputString);
    if (inputString[len - 1] == '\n') {
        inputString[len - 1] = '\0';
    }

    swapFirstAndLastChars(inputString); // Вызов функции для замены символов

    printf("Результат: %s\n", inputString);

    return 0;
}
