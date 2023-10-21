#include <stdio.h>

int main() {
    char text[100];

    // Membaca teks dari stdin (keyboard) ke dalam variable
    printf("Masukkan teks: ");
    scanf("%s", text);

    // Mencetak teks ke stdout (layar)
    printf("Anda memasukkan: %s\n");

    return 0;
}
