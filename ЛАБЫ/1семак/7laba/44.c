#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ZONES 10
typedef struct {
    char name[50];
    char zone[50];
    float food_cost;
} Animal;


void deleteAnimal(Animal* animals, int* n, const char* name) {
    bool found = false;
    for (int i = *n - 1; i >= 0; i--) {
        if (strcmp(animals[i].name, name) == 0) {
            found = true;
            if (i == *n - 1) {
                (*n)--;
            } else {
                animals[i] = animals[*n - 1];
                (*n)--;
            }
            break;
        }
    }
    if (!found) {
        printf("Animal not found.\n");
    }
}


int main() {
    Animal animals[1000];
    int n = 0;

    FILE* file = fopen("zoo.bin", "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    strcpy(animals[n].name, "Lion");
    strcpy(animals[n].zone, "Savannah");
    animals[n].food_cost = 10.0;
    fwrite(&animals[n], sizeof(Animal), 1, file);
    n++;

    strcpy(animals[n].name, "Tiger");
    strcpy(animals[n].zone, "Savannah");
    animals[n].food_cost = 8.0;
    fwrite(&animals[n], sizeof(Animal), 1, file);
    n++;

    strcpy(animals[n].name, "Bear");
    strcpy(animals[n].zone, "Forest");
    animals[n].food_cost = 6.0;
    fwrite(&animals[n], sizeof(Animal), 1, file);
    n++;

    strcpy(animals[n].name, "Monkey");
    strcpy(animals[n].zone, "Jungle");
    animals[n].food_cost = 4.0;
    fwrite(&animals[n], sizeof(Animal), 1, file);
    n++;

    fclose(file);

    printf("Initial data has been written to the file.\n");

   int choice;
   char animalName[50];

   printf("Do you want to delete an animal? (1 - Yes, 0 - No): ");
   scanf("%d", &choice);

   if (choice == 1) {
        printf("Enter the name of the animal you want to delete: ");
        scanf("%s", animalName);
        deleteAnimal(animals, &n, animalName);
   }

   return 0;
}
