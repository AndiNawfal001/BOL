#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Fungsi untuk membersihkan layar
void clearScreen() {
    system("clear || cls");
}

// Fungsi untuk menampilkan menu utama
void showMainMenu() {
    printf("Selamat datang di Program Menu Data Mahasiswa\n");
    printf("Apa yang Anda ingin lakukan?\n");
    printf("1. Add Data Mahasiswa\n");
    printf("2. View Data Mahasiswa\n");
    printf("3. Delete Data Mahasiswa\n");
    printf("4. Update Data Mahasiswa\n");
    printf("5. Search Data Mahasiswa\n");
    printf("6. Keluar\n");
}

// Fungsi untuk menampilkan submenu Add Data Mahasiswa
void showAddMenu() {
    printf("Menu Add Data Mahasiswa\n");
    printf("Masukkan data mahasiswa:\n"); 
    printf("1. Masukkan NIM: "); 
    printf("2. Masukkan Nama: "); 
    printf("3. Masukkan Alamat: "); 
    printf("4. Masukkan No HP: "); 
    printf("5. Kembali ke Menu Utama\n");
}

// Fungsi untuk menambahkan data mahasiswa
void addStudent() { 
    printf("Fungsi Add Data Mahasiswa sedang dipanggil...\n"); 
}

// Fungsi untuk menampilkan data mahasiswa
void viewStudents() { 
    printf("Fungsi View Data Mahasiswa sedang dipanggil...\n"); 
}

// Fungsi untuk menghapus data mahasiswa
void deleteStudent() { 
    printf("Fungsi Delete Data Mahasiswa sedang dipanggil...\n"); 
}

// Fungsi untuk memperbarui data mahasiswa
void updateStudent() { 
    printf("Fungsi Update Data Mahasiswa sedang dipanggil...\n"); 
}

// Fungsi untuk mencari data mahasiswa
void searchStudent() { 
    printf("Fungsi Search Data Mahasiswa sedang dipanggil...\n"); 
}

int main() {
    int choice;

    do {
        clearScreen();
        showMainMenu();
        printf("Masukkan satu angka (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                clearScreen();
                showAddMenu();
                int addChoice;
                scanf("%d", &addChoice);
                if (addChoice == 5) {
                    break; // Kembali ke Menu Utama
                } else if (addChoice == 1) {
                    addStudent();
                } 

            case 2:
                viewStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                searchStudent();
                break;
            case 6:
                printf("Terima kasih telah menggunakan program.\nTekan tombol apapun untuk keluar...\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan masukkan angka 1-6.\n");
                break;
        }
 
        printf("\nTekan tombol apapun untuk melanjutkan...\n");
        getchar();
        getchar(); // Dua kali untuk menunggu pengguna menekan tombol

    } while (choice != 6);

    return 0;
}
