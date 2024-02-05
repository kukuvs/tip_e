#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25 // Количество студентов
#define M 7  // Количество лабораторных работ
#define L 8  // Количество групп

int main() {
    int journal[L][N][M]; // Журнал преподавателя

    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Заполнение журнала случайными оценками
    for (int l = 0; l < L; l++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                journal[l][n][m] = rand() % 5; // Генерация случайных оценок от 0 до 4
            }
        }
    }

    int studentsAllowed[L] = {0};   // Количество студентов, допущенных к экзамену в каждой группе
    int studentsAutomated[L] = {0}; // Количество студентов, получивших экзамен "автоматом" в каждой группе

    // Подсчет студентов, допущенных к экзамену и получивших "автоматом" в каждой группе
    for (int l = 0; l < L; l++) {
        for (int n = 0; n < N; n++) {
            int reportCount = 0; // Счетчик отчетов для каждого студента

            for (int m = 0; m < M; m++) {
                if (journal[l][n][m] >= 3) {
                    reportCount++;
                } else {
                    break; // Если хотя бы одна работа не выполнена, прекращаем проверку для данного студента
                }
            }

            if (reportCount == M) {
                studentsAllowed[l]++; // Студент допущен к экзамену
                if (journal[l][n][M - 1] == 4) {
                    studentsAutomated[l]++; // Получил "автоматом"
                }
            }
        }
    }

    // Вывод результатов
    printf("Студенты, допущенные к экзамену и получившие 'автоматом' в каждой группе:\n");
    for (int l = 0; l < L; l++) {
        printf("Группа %d: Допущено к экзамену: %d, 'Автоматом': %d\n", l + 1, studentsAllowed[l], studentsAutomated[l]);
    }

    return 0;
}
