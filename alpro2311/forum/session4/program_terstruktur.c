#include <stdio.h>

int main() {
    int jumlahBilangan;
    int bilangan;
    int maksimum = 0; 

    // Input
    printf("Masukkan jumlah bilangan: ");
    scanf("%d", &jumlahBilangan);

    if (jumlahBilangan <= 0) {
        printf("Error: Jumlah bilangan harus lebih besar dari 0.\n");
        return 1; // Menghentikan program dengan kode kesalahan
    }

    // Pernyataan eksekusi (for loop)
    printf("Masukkan bilangan-bilangan:\n");
    for (int i = 0; i < jumlahBilangan; i++) {
        printf("Bilangan ke-%d: ", i + 1);
        scanf("%d", &bilangan);

        if (i == 0 || bilangan > maksimum) {
            maksimum = bilangan;
        }
    }

    // Output
    printf("Nilai maksimum adalah: %d\n", maksimum);

    return 0;
}
