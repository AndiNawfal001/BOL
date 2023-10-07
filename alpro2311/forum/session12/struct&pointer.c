#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struktur Contact
struct Contact {
    char nama[50];
    char no_hp[15];
    char no_kantor[15];
    char email[50];
    char perusahaan[50];
};

// Fungsi untuk menambahkan kontak
void tambahContact(struct Contact **contacts, int *count) {
    struct Contact newContact;

    printf("Masukkan nama: ");
    scanf("%s", newContact.nama);
    printf("Masukkan nomor HP: ");
    scanf("%s", newContact.no_hp);
    printf("Masukkan nomor kantor: ");
    scanf("%s", newContact.no_kantor);
    printf("Masukkan email: ");
    scanf("%s", newContact.email);
    printf("Masukkan nama perusahaan: ");
    scanf("%s", newContact.perusahaan);

    // Mengalokasikan memori untuk kontak baru
    *contacts = realloc(*contacts, (*count + 1) * sizeof(struct Contact));

    if (*contacts == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        exit(1);
    }

    // Menyalin data kontak ke dalam array dinamis
    (*contacts)[*count] = newContact;
    (*count)++;
}

// Fungsi untuk menampilkan semua kontak
void tampilkanContacts(struct Contact *contacts, int count) {
    printf("\nDaftar Kontak:\n");
    for (int i = 0; i < count; i++) {
        printf("Nama: %s\n", contacts[i].nama);
        printf("Nomor HP: %s\n", contacts[i].no_hp);
        printf("Nomor Kantor: %s\n", contacts[i].no_kantor);
        printf("Email: %s\n", contacts[i].email);
        printf("Perusahaan: %s\n", contacts[i].perusahaan);
        printf("\n");
    }
}

// Fungsi untuk menghapus semua kontak
void hapusContacts(struct Contact **contacts, int *count) {
    free(*contacts); // Membuang memori yang dialokasikan untuk kontak
    *contacts = NULL; // Menetapkan pointer ke NULL
    *count = 0; // Menetapkan jumlah kontak ke 0
    printf("Semua kontak telah dihapus.\n");
}

int main() {
    struct Contact *contacts = NULL;
    int count = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Kontak\n");
        printf("2. Tampilkan Kontak\n");
        printf("3. Hapus Semua Kontak\n");
        printf("4. Keluar\n");
        printf("Pilih tindakan (1/2/3/4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                tambahContact(&contacts, &count);
                break;
            case 2:
                tampilkanContacts(contacts, count);
                break;
            case 3:
                hapusContacts(&contacts, &count);
                break;
            case 4:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 4);

    return 0;
}
