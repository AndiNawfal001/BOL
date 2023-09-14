#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

char* formatInteger(int number) {
    char buffer[20];  // Menyimpan string hasil format
    char formatted[20];  // Menyimpan string dengan titik

    // Mengkonversi integer ke string
    sprintf(buffer, "%d", number);

    int len = strlen(buffer);
    int commaCount = (len - 1) / 3;  // Menghitung berapa titik (,) yang diperlukan
    int formattedLen = len + commaCount;  // Panjang string yang sudah diformat

    int idx = 0;  // Indeks untuk string `formatted`

    for (int i = 0; i < len; i++) {
        formatted[idx++] = buffer[i];

        if ((len - i - 1) % 3 == 0 && i < len - 1) {
            formatted[idx++] = '.';
        }
    }

    formatted[idx] = '\0';  // Menambahkan null-terminator

    // Mengalokasikan memori baru untuk string hasil format
    char* result = (char*)malloc(formattedLen + 1);
    strcpy(result, formatted);

    return result;
}

int main() {
    float hargaPerJam = 10000;
    int jamMain;
    int totalHarga; 

    printf("=======================================\n");
    printf("PROGRAM HITUNG HARGA JAM PEMAKAIAN\n");
    printf("=======================================\n\n");

    // Meminta input jamMain hingga valid
    do {
        printf("Berapa lama jam Bermain ? ");
        
        // Memeriksa apakah input adalah angka bulat positif (ERROR CHECK)
        if (scanf("%d", &jamMain) != 1 || jamMain <= 0) {
            printf("\033[0;31mMasukkan jumlah jam yang valid (bilangan bulat positif).\033[0m\n");
            while (getchar() != '\n'); // Membersihkan input buffer
        } else {
            break; // Keluar dari loop jika input valid
        }
    } while (1);

    float hargaSebelumDiskon = jamMain * hargaPerJam;
    float diskon = 0.0;
    float potonganHarga = 0.0;

    if (jamMain > 8) {
        diskon = 0.25;  // Diskon 25% untuk lebih dari 8 jam
    } else if (jamMain > 6) {
        diskon = 0.20;  // Diskon 20% untuk lebih dari 6 jam
    } else if (jamMain > 4) {
        diskon = 0.15;  // Diskon 15% untuk lebih dari 4 jam
    }

    potonganHarga = hargaSebelumDiskon * diskon;
    totalHarga = hargaSebelumDiskon - potonganHarga;

    printf("\nHarga sebelum diskon : Rp %s\n", formatInteger((int)hargaSebelumDiskon));
    printf("Diskon yang diperoleh : %.0f%%\n", diskon * 100);
    printf("Potongan harga yang diperoleh : Rp %s\n", formatInteger((int)potonganHarga));
    printf("Harga yang harus dibayar : Rp %s\n", formatInteger(totalHarga));

    // Membebaskan memori yang dialokasikan
    free(formatInteger(totalHarga));

    return 0;
}
