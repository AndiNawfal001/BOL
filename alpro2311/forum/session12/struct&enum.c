#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enumerasi untuk Penerbit
enum Penerbit {
    GRAMEDIA,
    ELEXMEDIA,
    ANDI_OFFSET,
    PUSTAKA
};

// Enumerasi untuk Kategori Buku
enum Kategori {
    FIKSI,
    TEKS,
    SEJARAH,
    NOVEL
};

// Struct untuk Data Buku
struct Buku {
    char ISBN[20];
    char Judul[100];
    char Pengarang[50];
    int TahunTerbit;
    enum Penerbit Penerbit;
    enum Kategori Kategori;
};

// Fungsi untuk menampilkan data buku
void tampilkanBuku(struct Buku buku) {
    printf("ISBN: %s\n", buku.ISBN);
    printf("Judul: %s\n", buku.Judul);
    printf("Pengarang: %s\n", buku.Pengarang);
    printf("Tahun Terbit: %d\n", buku.TahunTerbit);
    
    switch (buku.Penerbit) {
        case GRAMEDIA:
            printf("Penerbit: Gramedia\n");
            break;
        case ELEXMEDIA:
            printf("Penerbit: Elexmedia\n");
            break;
        case ANDI_OFFSET:
            printf("Penerbit: Andi Offset\n");
            break;
        case PUSTAKA:
            printf("Penerbit: Pustaka\n");
            break;
        default:
            printf("Penerbit: Tidak Diketahui\n");
            break;
    }

    switch (buku.Kategori) {
        case FIKSI:
            printf("Kategori: Fiksi\n");
            break;
        case TEKS:
            printf("Kategori: Teks\n");
            break;
        case SEJARAH:
            printf("Kategori: Sejarah\n");
            break;
        case NOVEL:
            printf("Kategori: Novel\n");
            break;
        default:
            printf("Kategori: Tidak Diketahui\n");
            break;
    }
}

int main() {
    struct Buku daftarBuku[100]; // Maksimum 100 buku
    int jumlahBuku = 0;

    int pilihan;
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Buku\n");
        printf("2. Tampilkan Daftar Buku\n");
        printf("3. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                if (jumlahBuku < 100) {
                    struct Buku buku;
                    printf("ISBN: ");
                    scanf("%s", buku.ISBN);
                    printf("Judul: ");
                    scanf("%s", buku.Judul);
                    printf("Pengarang: ");
                    scanf("%s", buku.Pengarang);
                    printf("Tahun Terbit: ");
                    scanf("%d", &buku.TahunTerbit);
                    printf("Penerbit (0: Gramedia, 1: Elexmedia, 2: Andi Offset, 3: Pustaka): ");
                    scanf("%d", &buku.Penerbit);
                    printf("Kategori (0: Fiksi, 1: Teks, 2: Sejarah, 3: Novel): ");
                    scanf("%d", &buku.Kategori);
                    
                    daftarBuku[jumlahBuku] = buku;
                    jumlahBuku++;
                    printf("Buku berhasil ditambahkan.\n");
                } else {
                    printf("Maaf, daftar buku sudah penuh.\n");
                }
                break;
            case 2:
                printf("\nDaftar Buku:\n");
                for (int i = 0; i < jumlahBuku; i++) {
                    printf("Buku %d:\n", i + 1);
                    tampilkanBuku(daftarBuku[i]);
                    printf("\n");
                }
                break;
            case 3:
                printf("Terima kasih, program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 3);

    return 0;
}
