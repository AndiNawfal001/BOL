#include <stdio.h>

int main() {
    FILE *file;
    char text[] = "Contoh teks yang akan disimpan dalam file.";

    // Membuka file untuk penulisan
    file = fopen("contoh.txt", "w");
    
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    // Menulis teks ke dalam file
    fputs(text, file);
    
    // Menutup file
    fclose(file);

    return 0;
}
