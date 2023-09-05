#include <stdio.h>
#include <ctype.h>

int main() {
    char belanjaLagi; 
    int totalBelanja, jumlahBelanja = 0, jumlahDiskon = 0, belanjaKe = 0, semuaDiskon;
    float diskonTotal, diskonAktif; 
    
    printf("\033[0;32m========================================\n");
    printf("HITUNG DISKON TOTAL BELANJA\n");
    printf("========================================\033[0m\n\n"); 

    do {
        belanjaKe++;
        printf("Masukkan total harga: Rp. ");
        scanf("%d", &totalBelanja);

        // Diskon 20% setiap ke-4 belanja
        diskonAktif = (belanjaKe == 4) ? 0.20 : 0.0;

        // Diskon berdasarkan total belanja
        if (totalBelanja < 200000) {
            diskonTotal = 0.0;
        } else if (totalBelanja < 500000) { 
            diskonTotal = 0.10;
        } else if (totalBelanja < 1000000) { 
            diskonTotal = 0.20;
        } else {
            diskonTotal = 0.30;
        }

        // Hitung jumlah harga diskon setelah kedua diskon
        jumlahDiskon = (totalBelanja * diskonTotal) + (totalBelanja * diskonAktif);   

        // Hitung hasil diskon
        semuaDiskon = (diskonTotal + diskonAktif) *100;

        // Hitung jumlah belanja yang harus dibayar setelah didiskon
        jumlahBelanja = totalBelanja - jumlahDiskon; 

        printf("Anda mendapatkan potongan diskon : %d persen \n", semuaDiskon);
        printf("Potongan harga yang diperoleh : Rp. %d\n", jumlahDiskon);
        printf("Jumlah harga yang harus di bayar : Rp. %d\n", jumlahBelanja);
        printf("Sudah berapa kali belanja : %d\n\n", belanjaKe); 
     
        printf("\033[0;34mApakah anda ingin belanja lagi? (Y/N): \033[0m");
        scanf(" %c", &belanjaLagi); 
        printf("\n"); 

        // Cek input user dan ulang pertanyaan jika salah
        while(belanjaLagi != 'y' && belanjaLagi != 'n' && belanjaLagi != 'Y' && belanjaLagi != 'N'){
            printf("\033[0;31mMohon input (Y/N)\nY = belanja lagi\nN = tidak belanja lagi\033[0m\n\n");
            printf("\033[0;34mApakah anda ingin belanja lagi? (Y/N): \033[0m"); 
            scanf(" %c", &belanjaLagi);  
            printf("\n"); 
        } 
        
        // Jika sesi sudah 4 maka sesi di reset ke sesi 1
        belanjaKe = (belanjaKe == 4) ? 0 : belanjaKe;
        
    } while (belanjaLagi == 'y');  
 
    printf("\n");
    printf("\033[0;32m========================================\n");
    printf("TERIMA KASIH TELAH BELANJA DISINI\n");
    printf("========================================\n\n"); 

    return 0;
}