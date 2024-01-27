#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void processFile(const char* inputFileName, const char* outputFileName) {
    // Открываем входной файл для чтения
    FILE* inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Ошибка открытия файла %s\n", inputFileName);
        return;
    }
    
    // Открываем выходной файл для записи
    FILE* outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Ошибка открытия файла %s\n", outputFileName);
        fclose(inputFile);
        return;
    }
    
    int number;
    
    // Читаем числа из входного файла и обрабатываем их
    while (fread(&number, sizeof(int), 1, inputFile) == 1) {
        
        // Если число положительное, добавляем его квадрат в выходной файл
        if (number > 0) {
            fwrite(&number, sizeof(int), 1, outputFile);
            int square = number * number;
            fwrite(&square, sizeof(int), 1, outputFile);
        }
    }
    
    // Закрываем файлы
    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);   
    int number;
    // Создаем и заполняем исходный файл случайными числами
    FILE* inputFile = fopen("input.bin", "wb");
    if (inputFile == NULL) {
        printf("Ошибка создания файла input.bin\n");
        return 1;
    }
    
    int i;
    for (i = 0; i < 10; i++) {
        int number = rand() % 201 - 100; // Генерируем число от -100 до 100
        fwrite(&number, sizeof(int), 1, inputFile);
    }
    
    fclose(inputFile);
    
    // Обрабатываем файл
    processFile("input.bin", "output.bin");
    
    // Выводим содержимое исходного файла
    printf("Содержимое исходного файла:\n");
    inputFile = fopen("input.bin", "rb");
    if (inputFile == NULL) {
        printf("Ошибка открытия файла input.bin\n");
        return 1;
    }
    
    while (fread(&number, sizeof(int), 1, inputFile) == 1) {
        printf("%d ", number);
    }
    
    fclose(inputFile);
    printf("\n");
    
    // Выводим содержимое выходного файла
    printf("Содержимое выходного файла:\n");
    FILE* outputFile = fopen("output.bin", "rb");
    if (outputFile == NULL) {
        printf("Ошибка открытия файла output.bin\n");
        return 1;
    }
    
    while (fread(&number, sizeof(int), 1, outputFile) == 1) {
        printf("%d ", number);
    }
    
    fclose(outputFile);
    printf("\n");
    
    return 0;
}
