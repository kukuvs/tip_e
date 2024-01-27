#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define FILENAME "zoo_data.bin"
#define MAX_ANIMALS 100

// Структура для хранения данных о животных
struct Animal {
    char name[50];
    char habitat[50];
    float food_cost_per_day;
};

// Функция для подсчета количества животных в заданной природной зоне
void countAnimalsByHabitat(const char *habitat) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }

    struct Animal animal;
    int count = 0;

    while (fread(&animal, sizeof(struct Animal), 1, file)) {
        if (strcmp(animal.habitat, habitat) == 0) {
            count++;
        }
    }

    fclose(file);

    printf("Количество животных в природной зоне '%s': %d\n", habitat, count);
}

// Функция для расчета затрат на содержание животного в течение месяца
void calculateMonthlyCost(const char *animalName) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }

    struct Animal animal;
    float cost = 0;

    while (fread(&animal, sizeof(struct Animal), 1, file)) {
        if (strcmp(animal.name, animalName) == 0) {
            cost = animal.food_cost_per_day * 30; // Предполагаем, что месяц состоит из 30 дней
            break;
        }
    }

    fclose(file);

    if (cost > 0) {
        printf("Затраты на содержание животного '%s' в месяц: %.2f\n", animalName, cost);
    } else {
        printf("Животное с именем '%s' не найдено.\n", animalName);
    }
}

// Функция для создания пустого файла для хранения данных о животных
void createFile() {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("Ошибка создания файла.\n");
        return;
    }
    fclose(file);
    printf("Файл создан успешно.\n");
}

// Функция для отображения содержимого файла
void displayFileContents() {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }

    struct Animal animal;

    while (fread(&animal, sizeof(struct Animal), 1, file)) {
        printf("Животное: %s, Природная зона: %s, Затраты на корм за день: %.2f\n",
               animal.name, animal.habitat, animal.food_cost_per_day);
    }

    fclose(file);
}

// Функция для добавления новых данных о животном в файл
void addData() {
    FILE *file = fopen(FILENAME, "ab");
    if (file == NULL) {
        printf("Ошибка открытия файла для добавления данных.\n");
        return;
    }

    struct Animal newAnimal;

    printf("Введите данные нового животного:\n");
    printf("Название: ");
    scanf("%s", newAnimal.name);
    printf("Природная зона: ");
    scanf("%s", newAnimal.habitat);
    printf("Затраты на корм за день: ");
    scanf("%f", &newAnimal.food_cost_per_day);

    fwrite(&newAnimal, sizeof(struct Animal), 1, file);

    fclose(file);
    printf("Данные успешно добавлены в файл.\n");
}

// Функция для изменения данных о животном по его имени
void updateData(const char *animalName) {
    FILE *file = fopen(FILENAME, "rb+");
    if (file == NULL) {
        printf("Ошибка открытия файла для изменения данных.\n");
        return;
    }

    struct Animal animal;

    // Находим запись по названию животного
    while (fread(&animal, sizeof(struct Animal), 1, file)) {
        if (strcmp(animal.name, animalName) == 0) {
            // Пользователь вводит новые данные
            printf("Введите новые данные для животного '%s':\n", animalName);
            printf("Новая природная зона: ");
            scanf("%s", animal.habitat);
            printf("Новые затраты на корм за день: ");
            scanf("%f", &animal.food_cost_per_day);

            // Переходим на начало записи и записываем новые данные
            fseek(file, -sizeof(struct Animal), SEEK_CUR);
            fwrite(&animal, sizeof(struct Animal), 1, file);
            printf("Данные успешно обновлены.\n");

            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("Животное с именем '%s' не найдено.\n", animalName);
}

// Функция для удаления данных о животном из файла по его имени
void removeData(const char *animalName) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("Ошибка открытия файла для удаления данных.\n");
        return;
    }

    FILE *tempFile = fopen("temp.bin", "wb");
    if (tempFile == NULL) {
        printf("Ошибка создания временного файла.\n");
        fclose(file);
        return;
    }

    struct Animal animal;

    while (fread(&animal, sizeof(struct Animal), 1, file)) {
        if (strcmp(animal.name, animalName) != 0) {
            fwrite(&animal, sizeof(struct Animal), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp.bin", FILENAME);

    printf("Данные о животном '%s' успешно удалены из файла.\n", animalName);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);       
    int choice;
    char animalName[50];
    char habitat[50];

    //
    do {
        printf("\n1. Создать файл\n");
        printf("2. Просмотреть содержимое файла\n");
        printf("3. Добавить данные\n");
        printf("4. Удалить данные о животном\n");
        printf("5. Подсчитать количество животных по природной зоне\n");
        printf("6. Рассчитать затраты на содержание животного в месяц\n");
        printf("7. Для изменения данных о животном:\n");
        printf("8. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                displayFileContents();
                break;
            case 3:
                addData();
                break;
            case 4:
                printf("Введите название животного для удаления: ");
                scanf("%s", animalName);
                removeData(animalName);
                break;
            case 5:
                printf("Введите природную зону для подсчета животных: ");
                scanf("%s", habitat);
                countAnimalsByHabitat(habitat);
                break;
            case 6:
                printf("Введите название животного для расчета затрат: ");
                scanf("%s", animalName);
                calculateMonthlyCost(animalName);
                break;
            case 7:
                printf("Введите название животного для изменения данных: ");
                scanf("%s", animalName);
                updateData(animalName);
                break;
            case 8:
                printf("Программа завершена.\n");
                break;
            default:
                printf("Неверный выбор. Попробуйте еще раз.\n");
        }
    } while (choice != 8);

    return 0;
}
