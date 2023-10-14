#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char inputChar;
    char months[12][15] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("Masukkan huruf A - Z: ");
    scanf(" %c", &inputChar);

    if (isalpha(inputChar)) {
        inputChar = toupper(inputChar);

        // Menampilkan pilihan bulan beserta nomor urut
        printf("Pilihan Bulan yang sesuai dengan huruf awalan '%c':\n", inputChar);
        for (int i = 0; i < 12; i++) {
            if (toupper(months[i][0]) == inputChar) {
                printf("%d. %s\n", i + 1, months[i]);
            }
        }

        // Memilih nomor urut bulan
        int selectedMonth = -1;
        printf("Masukkan nomor urut bulan yang ingin Anda pilih: ");
        scanf("%d", &selectedMonth);

        if (selectedMonth >= 1 && selectedMonth <= 12) {
            char selectedMonthName[15];
            strcpy(selectedMonthName, months[selectedMonth - 1]);
            printf("Anda memilih bulan %s\n", selectedMonthName);

            // Menghitung jumlah karakter vokal dan nonvokal
            int vokalCount = 0;
            int nonVokalCount = 0;

            for (int i = 0; i < strlen(selectedMonthName); i++) {
                char currentChar = tolower(selectedMonthName[i]);
                if (currentChar == 'a' || currentChar == 'i' || currentChar == 'u' || currentChar == 'e' || currentChar == 'o') {
                    vokalCount++;
                } else if (isalpha(selectedMonthName[i])) {
                    nonVokalCount++;
                }
            }

            printf("Jumlah karakter vokal: %d\n", vokalCount);
            printf("Jumlah karakter nonvokal: %d\n", nonVokalCount);
        } else {
            printf("Nomor urut bulan tidak valid.\n");
        }
    } else {
        printf("Masukkan tidak valid. Harap masukkan huruf A - Z.\n");
    }

    return 0;
}
