#include <stdio.h>
#include <string.h>

void bubbleSort(char arr[][20], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char temp[20];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int main() {
    char nama[10][20] = {"Fahmi Harahap", "Icha Nurlisa", "Agus Gumilang", "Zelda Zuraida", "Felix Halim", "Deddy Corbuizer", "Hassan Makmur", "Makmun Sukur", "Bella Christie", "Chelshe Love"};

    int n = sizeof(nama) / sizeof(nama[0]);

    printf("Sebelum sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", nama[i]);
    }

    bubbleSort(nama, n);

    printf("\nSetelah sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", nama[i]);
    }

    return 0;
}

