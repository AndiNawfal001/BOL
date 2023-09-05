#include <stdio.h>

int main() {
    int jarakKm, jarakM, jarakCm;

    printf("\033[0;32m========================================\n");
    printf("Rumus Mengkonversi KM ke M dan CM\n");
    printf("========================================\033[0m\n\n"); 
    
    printf("Masukkan jarak dalam kilometer: ");
    scanf("%d", &jarakKm);

    while (getchar() != '\n'); // Membersihkan input buffer
    printf("Tekan Enter untuk melanjutkan...");
    getchar(); // Menunggu pengguna menekan tombol Enter


    jarakM = jarakKm * 1000;
    jarakCm = jarakKm * 100000;

    printf("\nHasil konversi:\n");
    printf("%d kilometer = %d meter\n", jarakKm, jarakM);
    printf("%d kilometer = %d sentimeter\n", jarakKm, jarakCm); 

    return 0;
}
