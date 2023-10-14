#include <stdio.h>
#include <stdlib.h>

int main() {
    const int SIZE = 9;
    int *dataptr = (int *)malloc(SIZE * sizeof(int));

    // Memasukkan data ke dalam array dinamis
    printf("Masukkan data:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Data ke-%d: ", i + 1);
        scanf("%d", &dataptr[i]);
    }

    // Mencari data dalam array dinamis
    int searchValue;
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &searchValue);

    int found = 0;
    for (int i = 0; i < SIZE; i++) {
        if (dataptr[i] == searchValue) {
            found = 1;
            printf("Nilai %d ditemukan pada indeks %d.\n", searchValue, i);
        }
    }

    if (!found) {
        printf("Nilai %d tidak ditemukan dalam data.\n", searchValue);
    }

    // Menampilkan seluruh data dalam array dinamis
    printf("Data lengkap:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Data ke-%d: %d\n", i + 1, dataptr[i]);
    }

    free(dataptr); // Membebaskan memori yang dialokasikan

    return 0;
}
