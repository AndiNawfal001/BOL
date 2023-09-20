#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Deklarasi variabel
    char nama1[20];
    char *nama2;
    char *nama3[20];

    // Mengisikan data ke variabel nama1
    strcpy(nama1, "Brisia Jodie");

    // Mengisikan data ke variabel nama2 (dengan alokasi memori)
    nama2 = strdup("Brisia Jodie");

    // Mengisikan data ke variabel nama3 (dengan alokasi memori)
    for (int i = 0; i < 20; i++) {
        nama3[i] = strdup("Brisia Jodie");
    }

    // Menggunakan variabel-variabel yang telah diisi
    printf("nama1: %s\n", nama1);
    printf("nama2: %s\n", nama2);
    printf("nama3[0]: %s\n", nama3[0]);

    // Selain variabel nama3[0], nama3[1] hingga nama3[19] juga berisi "Brisia Jodie"

    // Bebaskan memori yang dialokasikan untuk nama2 dan nama3
    free(nama2);
    for (int i = 0; i < 20; i++) {
        free(nama3[i]);
    }

    return 0;
}
