#include <stdio.h>
#include <stdlib.h>
#include <float.h>

void swapMinMax(float *arr, int size) {
    float min = FLT_MAX;
    float max = -FLT_MAX;
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }

    float temp = arr[0];
    arr[0] = min;
    arr[minIndex] = temp;

    temp = arr[size - 1];
    arr[size - 1] = max;
    arr[maxIndex] = temp;
}

int main() {
    FILE *inputFile, *outputFile;
    int rows, cols;

    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Ошибка открытия файла");
        return 1;
    }

    fscanf(inputFile, "%d %d", &rows, &cols);
    fprintf(outputFile, "%d %d\n", rows, cols);

    for (int i = 0; i < rows; i++) {
        float *row = (float *)malloc(cols * sizeof(float));

        for (int j = 0; j < cols; j++) {
            fscanf(inputFile, "%f", &row[j]);
        }

        swapMinMax(row, cols);

        for (int j = 0; j < cols; j++) {
            fprintf(outputFile, "%.2f ", row[j]);
        }
        fprintf(outputFile, "\n");

        free(row);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Преобразование завершено. Результат записан в файл output.txt\n");

    return 0;
}
