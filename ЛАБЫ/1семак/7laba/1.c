#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Функция для проверки слова на наличие двух букв 'о'
bool containsTwoOs(const char *word) {
    int count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (tolower(word[i]) == 'o') {
            count++;
        }
    }
    return count == 2;
}

int main() {
    FILE *inputFile, *outputFile;
    char line[1000];

    inputFile = fopen("input.txt", "r"); // Открытие файла для чтения
    outputFile = fopen("output.txt", "w"); // Создание/открытие файла для записи

    if (inputFile == NULL || outputFile == NULL) {
        perror("Ошибка открытия файла");
        return 1;
    }

    // Чтение файла построчно
    while (fgets(line, sizeof(line), inputFile)) {
        char *word = strtok(line, " "); // Разделение строки на слова по пробелам
        bool writeLine = true;

        while (word != NULL) {
            if (containsTwoOs(word)) {
                writeLine = false; // Если найдено слово с двумя буквами "О", не записывать строку
                break;
            }
            word = strtok(NULL, " ");
        }

        if (writeLine) {
            fputs(line, outputFile); // Запись строки в выходной файл
        }
    }

    fclose(inputFile); // Закрытие файлов
    fclose(outputFile);

    printf("Обработка завершена. Фразы с двумя буквами 'О' удалены из файла.\n");

    return 0;
}
