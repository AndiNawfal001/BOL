#include <stdio.h>
#include <stdbool.h>

int main() {
    int m, n, p, q;

    //INPUT 
    printf("Masukkan jumlah baris matriks pertama: ");
    scanf("%d", &m);
    printf("Masukkan jumlah kolom matriks pertama: ");
    scanf("%d", &n);
    printf("Masukkan jumlah baris matriks kedua: ");
    scanf("%d", &p);
    printf("Masukkan jumlah kolom matriks kedua: ");
    scanf("%d", &q);

    // ERROR CHECK
    if (n != p) {
        printf("\x1b[31mError: Perkalian matriks tidak valid. Jumlah kolom matriks pertama harus sama dengan jumlah baris matriks kedua.\x1b[0m\n");
        return 1;
    }

    int matriks1[m][n];
    int matriks2[p][q];
    int hasil[m][q];
    int i, j, k;

    //INPUT
    printf("Masukkan elemen-elemen matriks pertama (%dx%d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            int input;
            //ERROR CHECK
            if (scanf("%d", &input) != 1) {
                printf("\x1b[31mError: Input harus berupa bilangan bulat.\x1b[0m\n");
                return 1;
            }
            matriks1[i][j] = input;
        }
    }
    
    //INPUT
    printf("Masukkan elemen-elemen matriks kedua (%dx%d):\n", p, q);
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            int input;
            //ERROR CHECK
            if (scanf("%d", &input) != 1) {
                printf("\x1b[31mError: Input harus berupa bilangan bulat.\x1b[0m\n");
                return 1;
            }
            matriks2[i][j] = input;
        }
    }

    //PROSES
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            hasil[i][j] = 0;
        }
    } 
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            for (k = 0; k < n; k++) {
                hasil[i][j] += matriks1[i][k] * matriks2[k][j];
            }
        }
    }

    //OUTPUT
    printf("Hasil perkalian matriks:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d ", hasil[i][j]);
        }
        printf("\n");
    }

    return 0;
}
