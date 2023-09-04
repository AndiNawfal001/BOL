#include <stdio.h>
#include <string.h>

int main() {
    double konstan_pertamax = 15.0;
    double stop_and_go_pertamax = 10.0;
    double konstan_pertalite = 12.0;
    double stop_and_go_pertalite = 8.0;

    double liter_bensin, jarak, keiritan = 0.0;
    char jenis_bensin[10], mode_menyopir[20];

    printf("Masukkan jenis bensin (Pertamax/Pertalite): ");
    scanf("%s", jenis_bensin);

    printf("Masukkan jumlah liter bensin: ");
    scanf("%lf", &liter_bensin);

    printf("Masukkan jarak yang ditempuh (km): ");
    scanf("%lf", &jarak);

    printf("Masukkan mode mengemudi (konstan/stop&go): ");
    scanf("%s", mode_menyopir);

    if (strcmp(jenis_bensin, "Pertamax") == 0) {
        if (strcmp(mode_menyopir, "konstan") == 0) {
            keiritan = konstan_pertamax;
        } else if (strcmp(mode_menyopir, "stop&go") == 0) {
            keiritan = stop_and_go_pertamax;
        }
    } else if (strcmp(jenis_bensin, "Pertalite") == 0) {
        if (strcmp(mode_menyopir, "konstan") == 0) {
            keiritan = konstan_pertalite;
        } else if (strcmp(mode_menyopir, "stop&go") == 0) {
            keiritan = stop_and_go_pertalite;
        }
    } else {
        printf("Jenis bensin yang dimasukkan tidak valid.\n");
        return 1;
    }

    double bensin_terpakai = jarak / keiritan;

    double bensin_akhir = liter_bensin - bensin_terpakai;

    printf("Jumlah liter pengurangan bensin setelah menempuh jarak: %.2lf liter\n", bensin_terpakai);
    printf("Jumlah liter bensin akhir: %.2lf liter\n", bensin_akhir);

    return 0;
}
