#include <stdio.h>
//test
int main() {
    int lulus = 0;
    int gagal = 0;

    printf("Dalam mata kuliah Pengelolaan Bisnis Brokering Real-Estate,\n");
    printf("terdapat 100 mahasiswa yang menempuh ujian.\n");

    // 100 bisa di ganti dengan jumlah mahasiswa yang berbeda
    for (int i = 1; i <= 100; i++) {
        char nama[50];
        int hasil;

        printf("Nama mahasiswa %d: ", i);
        scanf("%s", nama);

        printf("Masukkan hasil (1=lulus, 2=gagal) untuk %s: ", nama);
        scanf("%d", &hasil);

        if (hasil == 1) {
            printf("%s lulus ujian.\n", nama);
            lulus++;
        } else if (hasil == 2) {
            printf("%s gagal ujian.\n", nama);
            gagal++;
        } else {
            printf("Hasil tidak valid untuk %s.\n", nama);
        }
    }

    printf("\nJumlah mahasiswa yang lulus: %d\n", lulus);
    printf("Jumlah mahasiswa yang gagal: %d\n", gagal);

    // / 100 bisa di ganti dengan jumlah mahasiswa yang berbeda
    int persentaseLulus = (double)lulus / 100 * 100;
    printf("Persentase lulus : %d persen \n", persentaseLulus);
    
    if (persentaseLulus >= 80) {
        printf("Kelulusan kelas telah mencapai target!\n");
    }else{
        printf("Kelulusan belum mencapai target!");
    }

    return 0;
}