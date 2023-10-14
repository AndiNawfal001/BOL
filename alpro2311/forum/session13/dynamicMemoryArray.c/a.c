#include <stdio.h>

int main() {
    const int SIZE = 9;
    int data[SIZE];

    // Memasukkan data ke dalam array
    printf("Masukkan data:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Data ke-%d: ", i + 1);
        scanf("%d", &data[i]);
    }

    // Mencari data dalam array
    int searchValue;
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &searchValue);

    int found = 0;
    for (int i = 0; i < SIZE; i++) {
        if (data[i] == searchValue) {
            found = 1;
            printf("Nilai %d ditemukan pada indeks %d.\n", searchValue, i);
        }
    }

    if (!found) {
        printf("Nilai %d tidak ditemukan dalam data.\n", searchValue);
    }

    // Menampilkan seluruh data dalam array
    printf("Data lengkap:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Data ke-%d: %d\n", i + 1, data[i]);
    }

    return 0;
}
