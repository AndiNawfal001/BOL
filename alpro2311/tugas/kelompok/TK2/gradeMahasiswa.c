#include <stdio.h>

int main() {
    int jumlahMahasiswa = 0;
    float rataRata = 0.0;
    int jumlahLulus = 0; // Jumlah mahasiswa yang lulus
    int jumlahTidakLulus = 0; // Jumlah mahasiswa yang tidak lulus

    printf("\033[0;32m========================================\n");
    printf("PROGRAM HITUNG GRADE MAHASISWA\n");
    printf("========================================\033[0m\n"); 

    while (jumlahMahasiswa < 10) {
        float nilaiQuis, nilaiTugas, nilaiAbsensi, nilaiPraktek, nilaiUAS;
        int validInput = 1;

        printf("\nInput nilai mahasiswa ke-%d:\n", jumlahMahasiswa + 1);

        // Input Nilai Quis
        do {
            printf("Nilai Quis: ");
            if (scanf("%f", &nilaiQuis) != 1) {
                printf("\033[0;31mError: Masukkan angka untuk nilai Quis.\033[0m\n");
                while (getchar() != '\n'); // Membersihkan input buffer
                validInput = 0; // Set validInput menjadi 0 (input tidak valid)
            } else if (nilaiQuis < 0 || nilaiQuis > 100) {
                printf("\033[0;31mError: Masukkan angka antara 0 dan 100 untuk nilai Quis.\033[0m\n");
                while (getchar() != '\n'); // Membersihkan input buffer
                validInput = 0; // Set validInput menjadi 0 (input tidak valid)
            } else {
                validInput = 1; // Set validInput menjadi 1 (input valid)
            }
        } while (!validInput);

        // Input Nilai Tugas
        do {
            printf("Nilai Tugas: ");
            if (scanf("%f", &nilaiTugas) != 1) {
                printf("\033[0;31mError: Masukkan angka untuk nilai Tugas.\033[0m\n");
                while (getchar() != '\n'); // Membersihkan input buffer
                validInput = 0; // Set validInput menjadi 0 (input tidak valid)
            } else if (nilaiTugas < 0 || nilaiTugas > 100) {
                printf("\033[0;31mError: Masukkan angka antara 0 dan 100 untuk nilai Tugas.\033[0m\n");
                while (getchar() != '\n'); // Membersihkan input buffer
                validInput = 0; // Set validInput menjadi 0 (input tidak valid)
            } else {
                validInput = 1; // Set validInput menjadi 1 (input valid)
            }
        } while (!validInput);

        // Input Nilai Absensi
        do {
            printf("Nilai Absensi: ");
            if (scanf("%f", &nilaiAbsensi) != 1) {
                printf("\033[0;31mError: Masukkan angka untuk nilai Absensi.\033[0m\n");
                while (getchar() != '\n'); // Membersihkan input buffer
                validInput = 0; // Set validInput menjadi 0 (input tidak valid)
            } else if (nilaiAbsensi < 0 || nilaiAbsensi > 100) {
                printf("\033[0;31mError: Masukkan angka antara 0 dan 100 untuk nilai Absensi.\033[0m\n");
                while (getchar() != '\n'); // Membersihkan input buffer
                validInput = 0; // Set validInput menjadi 0 (input tidak valid)
            } else {
                validInput = 1; // Set validInput menjadi 1 (input valid)
            }
        } while (!validInput);

        // Input Nilai Praktek
        do {
            printf("Nilai Praktek: ");
            if (scanf("%f", &nilaiPraktek) != 1) {
                printf("\033[0;31mError: Masukkan angka untuk nilai Praktek.\033[0m\n");
                while (getchar() != '\n'); // Membersihkan input buffer
                validInput = 0; // Set validInput menjadi 0 (input tidak valid)
            } else if (nilaiPraktek < 0 || nilaiPraktek > 100) {
                printf("\033[0;31mError: Masukkan angka antara 0 dan 100 untuk nilai Praktek.\033[0m\n");
                while (getchar() != '\n'); // Membersihkan input buffer
                validInput = 0; // Set validInput menjadi 0 (input tidak valid)
            } else {
                validInput = 1; // Set validInput menjadi 1 (input valid)
            }
        } while (!validInput);

        // Input Nilai UAS
        do {
            printf("Nilai UAS: ");
            if (scanf("%f", &nilaiUAS) != 1) {
                printf("\033[0;31mError: Masukkan angka untuk nilai UAS.\033[0m\n");
                while (getchar() != '\n'); // Membersihkan input buffer
                validInput = 0; // Set validInput menjadi 0 (input tidak valid)
            } else if (nilaiUAS < 0 || nilaiUAS > 100) {
                printf("\033[0;31mError: Masukkan angka antara 0 dan 100 untuk nilai UAS.\033[0m\n");
                while (getchar() != '\n'); // Membersihkan input buffer
                validInput = 0; // Set validInput menjadi 0 (input tidak valid)
            } else {
                validInput = 1; // Set validInput menjadi 1 (input valid)
            }
        } while (!validInput);

        // Menghitung rata-rata nilai mahasiswa
        float nilaiRataRata = (nilaiQuis + nilaiTugas + nilaiAbsensi + nilaiPraktek + nilaiUAS) / 5;
        rataRata += nilaiRataRata;

        // Menentukan grade berdasarkan nilai rata-rata
        char grade;
        if (nilaiRataRata <= 55) {
            grade = 'E';
            jumlahTidakLulus++; 
        } else if (nilaiRataRata <= 65) {
            grade = 'D';
            jumlahTidakLulus++;
        } else if (nilaiRataRata <= 75) {
            grade = 'C';
            jumlahLulus++;
        } else if (nilaiRataRata <= 85) {
            grade = 'B';
            jumlahLulus++;
        } else {
            grade = 'A';
            jumlahLulus++; 
        }

        // Menampilkan nilai rata-rata dan grade
        printf("Nilai rata-rata: %.2f\n", nilaiRataRata);
        printf("Grade: %c\n\n", grade);

        jumlahMahasiswa++;
        printf("========================================\n"); 

    }

    // Menghitung rata-rata nilai semua mahasiswa
    rataRata /= 10;

    // Menampilkan rata-rata nilai semua mahasiswa
    printf("\nRata-rata nilai semua mahasiswa: %.2f\n", rataRata);

    // Menampilkan jumlah mahasiswa yang lulus dan tidak lulus
    printf("\033[0;36mJumlah mahasiswa yang Lulus: %d\033[0m\n", jumlahLulus);
    printf("\033[0;33mJumlah mahasiswa yang Tidak Lulus: %d\033[0m\n", jumlahTidakLulus);

    return 0;
}
