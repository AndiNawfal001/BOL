#include <stdio.h>
#include <stdlib.h>

// Struktur data untuk entitas desain
typedef struct {
    char name[50];
    int id;
} DesignEntity;

// Deklarasi fungsi-fungsi
void mainMenu();
void getEntity(DesignEntity entities[], int *entityCount);
void produceDesign(DesignEntity entities[], int entityCount);
void generateReport(DesignEntity entities[], int entityCount);

int main() {
    DesignEntity entities[100]; // Array untuk menyimpan entitas desain
    int entityCount = 0; // Jumlah entitas saat ini

    int choice;

    while (1) {
        mainMenu();
        printf("Enter Number (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            getEntity(entities, &entityCount);
            break;
        case 2:
            produceDesign(entities, entityCount);
            break;
        case 3:
            generateReport(entities, entityCount);
            break;
        case 4:
            printf("Exiting program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid Input. Please enter a number between 1 and 4.\n");
        }

        // Membersihkan input buffer
        while (getchar() != '\n');

        // Menunggu sampai pengguna menekan Enter
        printf("Press Enter to continue...");
        getchar();

        // Membersihkan layar terminal berdasarkan sistem operasi
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }

    return 0;
}

void mainMenu() {
    printf("Main Menu:\n");
    printf("1. Get Design Entity\n");
    printf("2. Produce Design Reports\n");
    printf("3. Generate Report\n");
    printf("4. Exit\n");
}

void getEntity(DesignEntity entities[], int *entityCount) {
    if (*entityCount < 100) {
        printf("Enter the name of the design entity: ");
        scanf("%s", entities[*entityCount].name);
        entities[*entityCount].id = *entityCount + 1;
        (*entityCount)++;
        printf("Design Entity added successfully!\n");
    } else {
        printf("The maximum number of entities has been reached.\n");
    }
}

void produceDesign(DesignEntity entities[], int entityCount) {
    printf("Producing Design...\n"); 
    // Melakukan pengolahan desain dengan menggunakan informasi entitas yang telah diterima 
}

void generateReport(DesignEntity entities[], int entityCount) {
    printf("Generating Report:\n");

    for (int i = 0; i < entityCount; i++) {
        printf("Entity %d: %s\n", entities[i].id, entities[i].name);
    }
}
