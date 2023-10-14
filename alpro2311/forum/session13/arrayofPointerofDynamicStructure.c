#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Student {
    char ID[12];
    char name[20];
    char prodi[20];
    float GPA;
};

int isFloatValid(float value) {
    return (value >= 0.0 && value <= 4.0);
}

int isIDValid(const char *ID) {
    int length = strlen(ID);

    if (length == 10 && ID[0] == '2') {
        for (int i = 1; i < length; i++) {
            if (!isdigit((unsigned char)ID[i])) {
                return 0;
            }
        }
        return 1;
    }

    return 0;
}

int isStringValid(const char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (!isalpha((unsigned char)str[i]) && !isspace((unsigned char)str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int numStudents;
    printf("Selamat datang ke Program Input Data Mahasiswa\n");

    while (1) {
        printf("Masukkan jumlah mahasiswa: ");
        scanf("%d", &numStudents);

        struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));

        if (students == NULL) {
            fprintf(stderr, "Gagal mengalokasikan memori.\n");
            return 1;
        }

        for (int i = 0; i < numStudents; i++) {
            printf("Masukkan data untuk Mahasiswa %d:\n", i + 1);

            do {
                printf("ID: ");
                scanf("%s", students[i].ID);
                if (!isIDValid(students[i].ID)) {
                    printf("ID harus terdiri dari 10 angka dan dimulai dengan 2. Silakan coba lagi.\n");
                }
            } while (!isIDValid(students[i].ID));

            do {
                printf("Name: ");
                scanf(" %19[^\n]", students[i].name);
                if (!isStringValid(students[i].name)) {
                    printf("Name harus berupa karakter atau spasi. Silakan coba lagi.\n");
                }
            } while (!isStringValid(students[i].name));

            do {
                printf("Prodi: ");
                scanf(" %19[^\n]", students[i].prodi);
                if (!isStringValid(students[i].prodi)) {
                    printf("Prodi harus berupa karakter atau spasi. Silakan coba lagi.\n");
                }
            } while (!isStringValid(students[i].prodi));

            do {
                printf("GPA: ");
                scanf("%f", &students[i].GPA);
                if (!isFloatValid(students[i].GPA)) {
                    printf("GPA harus dalam rentang 0 hingga 4. Silakan coba lagi.\n");
                }
            } while (!isFloatValid(students[i].GPA));
        }

        printf("Data Mahasiswa:\n");
        for (int i = 0; i < numStudents; i++) {
            printf("Mahasiswa %d\n", i + 1);
            printf("ID: %s\n", students[i].ID);
            printf("Name: %s\n", students[i].name);
            printf("Prodi: %s\n", students[i].prodi);
            printf("GPA: %.2f\n\n", students[i].GPA);
        }

        free(students);

        char response;
        do {
            printf("Apakah Anda ingin melanjutkan program (y/n)? ");
            scanf(" %c", &response);
            if (response != 'y' && response != 'Y' && response != 'n' && response != 'N') {
                printf("Pilihan tidak valid. Silakan masukkan 'y' atau 'n'.\n");
            }
        } while (response != 'y' && response != 'Y' && response != 'n' && response != 'N');

        if (response != 'y' && response != 'Y') {
            break;
        }
    }

    return 0;
}
