#include <stdio.h>
#include <string.h>

typedef struct {
    char kode[10];
    char genre[30];
    char judul[100];
    char penulis[50];
    int stok;
} Buku;

typedef struct {
    char nama[50];
    char judul[100];
    char penulis[50];
    int lamaPinjam;
    char status[20];
} Peminjaman;

int main() {

    // ==========================================
    //               DATA BUKU
    // ==========================================
    Buku buku[] = {
        // ROMANCE
        {"R1", "ROMANCE", "Milea: Suara Dari Dilan", "Pidi Baiq", 10},
        {"R2", "ROMANCE", "Mariposa", "Luluk HF", 10},
        {"R3", "ROMANCE", "00.00", "Ameylia Falensia", 15},
        {"R4", "ROMANCE", "Ayat-Ayat Cinta", "Habiburrahman El Shirazy", 5},
        {"R5", "ROMANCE", "Septihan", "Popi Pertiwi", 2},

        // HORROR
        {"H1", "HORROR", "Kuchisake - Apakah Aku Cantik?", "Hastong N.H.", 7},
        {"H2", "HORROR", "Danur", "Risa Saraswati", 20},
        {"H3", "HORROR", "KKN Desa Penari", "Simplemen", 9},

        // COMEDY
        {"C1", "COMEDY", "My Stupid Boss", "chaos@work", 2},
        {"C2", "COMEDY", "Sabtu Bersama Bapak", "Adhitya Mulya", 15},
        {"C3", "COMEDY", "Skripsip", "Chara Perdana", 5},

        // SLICE OF LIFE
        {"S1", "SLICE OF LIFE", "Keajaiban Toko Kelontong Namia", "Keigo Higashino", 8},
        {"S2", "SLICE OF LIFE", "Keluarga Cemara", "Arswendo Atmowiloto", 5},
        {"S3", "SLICE OF LIFE", "Laskar Pelangi", "Andrea Hirata", 2},

        // ACTION
        {"A1", "ACTION", "Tanah Para Bandit", "Tere Liye", 11},
        {"A2", "ACTION", "Negeri Para Bedebah", "Tere Liye", 15},

        // THRILLER
        {"T1", "THRILLER", "Holy Mother", "Akiyoshi Rikako", 8},
        {"T2", "THRILLER", "Pasien", "Naomi Midori", 6},
        {"T3", "THRILLER", "IT", "Stephen King", 7}
    };

    int jumlahBuku = sizeof(buku) / sizeof(buku[0]);

    // ==========================================
    //             VARIABEL
    // ==========================================
    Peminjaman pem;
    char kodeInput[10];
    int found = 0;

    // ==========================================
    //           INPUT NAMA PEMINJAM
    // ==========================================
    printf("Masukkan nama peminjam: ");
    scanf(" %[^\n]", pem.nama);

    // ==========================================
    //            TAMPILKAN LIST BUKU
    // ==========================================
    printf("============================================\n");
    printf("|                                          |\n");
    printf("|        DAFTAR BUKU YANG BISA DIPINJAM    |\n");
    printf("|                                          |\n");
    printf("============================================\n");
    for (int i = 0; i < jumlahBuku; i++) {
        printf("%-3s | %-15s | %-35s (%-25s) | Stok: %d\n",
               buku[i].kode,
               buku[i].genre,
               buku[i].judul,
               buku[i].penulis,
               buku[i].stok);
    }

    // ==========================================
    //                PILIH BUKU
    // ==========================================
    printf("\nMASUKKAN KODE BUKU : ");
    scanf("%s", kodeInput);

    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(buku[i].kode, kodeInput) == 0) {
            found = 1;

            if (buku[i].stok == 0) {
                printf("\nMAAF, STOK BUKU '%s' SEDANG HABIS.\n", buku[i].judul);
                return 0;
            }

            // ==========================================
            //            INPUT LAMA PINJAM
            // ==========================================
            printf("Masukkan lama peminjaman (hari): ");
            scanf("%d", &pem.lamaPinjam);

            // ==========================================
            //               SIMPAN DATA
            // ==========================================
            strcpy(pem.judul, buku[i].judul);
            strcpy(pem.penulis, buku[i].penulis);
            strcpy(pem.status, "Dipinjam");

            // ==========================================
            //               UPDATE STOK
            // ==========================================
            buku[i].stok--;

            // ==========================================
            //               CETAK BUKTI
            // ==========================================
            printf("\n=== BUKTI PEMINJAMAN ===\n");
            printf("Nama Peminjam : %s\n", pem.nama);
            printf("Judul Buku    : %s\n", pem.judul);
            printf("Penulis       : %s\n", pem.penulis);
            printf("Lama Pinjam   : %d hari\n", pem.lamaPinjam);
            printf("Status        : %s\n", pem.status);

            break;
        }
    }

    if (!found) {
        printf("\nKODE BUKU TIDAK DITEMUKAN !!!\n");
    }

    return 0;
}
