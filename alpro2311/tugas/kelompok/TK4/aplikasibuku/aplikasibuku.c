#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Buku {
    char kode[6];
    char nama[50];
    char jenis[50];
    int harga;
    int stock;
};

struct Pembelian {
    char kodePembelian[6];
    char kodeBuku[6];
    int jumlah;
};

void inputBuku(struct Buku *buku, int *count);
void viewHistoryPembelian();
void viewBuku(struct Buku *buku, int count);
void pembelian(struct Buku *buku, int count);
void deleteHistoryPembelian();
void deleteBuku(struct Buku *buku, int *count);
void saveData(struct Buku *buku, int count);

int main() {
    struct Buku buku[100];
    int bukuCount = 0;
    int choice;

    FILE *fileBuku = fopen("databuku.txt", "r");
    if (fileBuku != NULL) {
        while (fscanf(fileBuku, "%s %49s %49s %d %d", buku[bukuCount].kode, buku[bukuCount].nama, buku[bukuCount].jenis, &buku[bukuCount].harga, &buku[bukuCount].stock) != EOF) {
            bukuCount++;
        }
        fclose(fileBuku);
    }

    do {
        printf("\nMenu:\n");
        printf("a. Input Data\n");
        printf("b. View History Pembelian\n");
        printf("c. View Buku\n");
        printf("d. Pembelian\n");
        printf("e. Delete History Pembelian\n");
        printf("f. Delete Buku\n");
        printf("g. Exit\n");
        printf("Pilihan: ");
        char choiceChar;
        scanf(" %c", &choiceChar);
        choice = choiceChar - 'a' + 1;

        switch (choice) {
            case 1:
                inputBuku(buku, &bukuCount);
                break;
            case 2:
                viewHistoryPembelian();
                break;
            case 3:
                viewBuku(buku, bukuCount);
                break;
            case 4:
                pembelian(buku, bukuCount);
                break;
            case 5:
                deleteHistoryPembelian();
                break;
            case 6:
                deleteBuku(buku, &bukuCount);
                break;
            case 7:
                saveData(buku, bukuCount);
                printf("Data telah disimpan. Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (choice != 7);

    return 0;
}

void inputBuku(struct Buku *buku, int *count) {
    if (*count >= 100) {
        printf("Jumlah maksimum buku telah tercapai.\n");
        return;
    }

    printf("Input Nama Buku: ");
    scanf("%49s", buku[*count].nama);
    printf("Input Jenis Buku: ");
    scanf("%49s", buku[*count].jenis);
    printf("Input Harga: ");
    scanf("%d", &buku[*count].harga);
    printf("Input Stock: ");
    scanf("%d", &buku[*count].stock);

    snprintf(buku[*count].kode, 6, "%04d", *count + 1);

    (*count)++;
    printf("Data buku berhasil ditambahkan.\n");
}

void viewHistoryPembelian() {
    printf("View History Pembelian\n");
    // Implementasi tampilan history pembelian di sini
}

void viewBuku(struct Buku *buku, int count) {
    printf("Data Buku:\n");
    for (int i = 0; i < count; i++) {
        printf("Kode: %s, Nama: %s, Jenis: %s, Harga: %d, Stock: %d\n", buku[i].kode, buku[i].nama, buku[i].jenis, buku[i].harga, buku[i].stock);
    }
}

void pembelian(struct Buku *buku, int count) {
    printf("Pembelian\n");
    viewBuku(buku, count);
    char kodePembelian[6];
    char kodeBuku[6];
    int jumlah;

    printf("Kode Buku yang akan dibeli: ");
    scanf("%5s", kodeBuku);

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(buku[i].kode, kodeBuku) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Buku dengan kode %s tidak ditemukan.\n", kodeBuku);
        return;
    }

    printf("Jumlah yang akan dibeli: ");
    scanf("%d", &jumlah);

    if (jumlah <= 0 || jumlah > buku[index].stock) {
        printf("Jumlah pembelian tidak valid atau melebihi stock.\n");
        return;
    }

    char beliLagi;
    printf("Beli lagi? (y/n): ");
    scanf(" %c", &beliLagi);

    // Implementasi pembelian
    // ...

    printf("Pembelian berhasil.\n");
}

void deleteHistoryPembelian() {
    printf("Delete History Pembelian\n");
    // Implementasi penghapusan history pembelian
}

void deleteBuku(struct Buku *buku, int *count) {
    printf("Delete Buku\n");
    // Implementasi penghapusan buku
}

void saveData(struct Buku *buku, int count) {
    FILE *fileBuku = fopen("databuku.txt", "w");
    if (fileBuku != NULL) {
        for (int i = 0; i < count; i++) {
            fprintf(fileBuku, "%s %s %s %d %d\n", buku[i].kode, buku[i].nama, buku[i].jenis, buku[i].harga, buku[i].stock);
        }
        fclose(fileBuku);
    }

    // Implementasi penyimpanan data pembelian ke dalam file datapembelian.txt
    // ...

    // Tutup file jika sudah selesai
}

