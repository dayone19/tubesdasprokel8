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

void printHeaderJudul() {
    printf("=============================================================\n");
    printf("|                                                           |\n");
    printf("|                DAFTAR BUKU YANG BISA DIPINJAM             |\n");
    printf("|                                                           |\n");
    printf("=============================================================\n");
}

void printHeaderTabel() {
    printf("---------------------------------------------------------------------------------------------------------------\n");
    printf("| KODE  |      GENRE       |             JUDUL BUKU             |          PENULIS          |   STOK   |\n");
    printf("---------------------------------------------------------------------------------------------------------------\n");
}

void printGenreLine(const char *genre) {
    printf("---------------------------------------------------------------------------------------------------------------\n");
    printf(">>> %s\n", genre);
    printf("---------------------------------------------------------------------------------------------------------------\n");
}

int main() {

    Buku buku[] = {
        {"R1", "ROMANCE", "Milea: Suara Dari Dilan", "Pidi Baiq", 10},
        {"R2", "ROMANCE", "Mariposa", "Luluk HF", 10},
        {"R3", "ROMANCE", "00.00", "Ameylia Falensia", 15},
        {"R4", "ROMANCE", "Ayat-Ayat Cinta", "Habiburrahman El Shirazy", 5},
        {"R5", "ROMANCE", "Septihan", "Popi Pertiwi", 2},

        {"H1", "HORROR", "Kuchisake - Apakah Aku Cantik?", "Hastong N.H.", 7},
        {"H2", "HORROR", "Danur", "Risa Saraswati", 20},
        {"H3", "HORROR", "KKN Desa Penari", "Simplemen", 9},

        {"C1", "COMEDY", "My Stupid Boss", "chaos@work", 2},
        {"C2", "COMEDY", "Sabtu Bersama Bapak", "Adhitya Mulya", 15},
        {"C3", "COMEDY", "Skripsip", "Chara Perdana", 5},

        {"S1", "SLICE OF LIFE", "Keajaiban Toko Kelontong Namia", "Keigo Higashino", 8},
        {"S2", "SLICE OF LIFE", "Keluarga Cemara", "Arswendo Atmowiloto", 5},
        {"S3", "SLICE OF LIFE", "Laskar Pelangi", "Andrea Hirata", 2},

        {"A1", "ACTION", "Tanah Para Bandit", "Tere Liye", 11},
        {"A2", "ACTION", "Negeri Para Bedebah", "Tere Liye", 15},

        {"T1", "THRILLER", "Holy Mother", "Akiyoshi Rikako", 8},
        {"T2", "THRILLER", "Pasien", "Naomi Midori", 6},
        {"T3", "THRILLER", "IT", "Stephen King", 7}
    };

    int jumlahBuku = sizeof(buku) / sizeof(buku[0]);
    Peminjaman pem;
    char kodeInput[10];
    int found = 0;

    FILE *file;

    printf("Nama Peminjam: ");
    scanf(" %[^\n]", pem.nama);

    printHeaderJudul();

    char lastGenre[30] = "";

    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(lastGenre, buku[i].genre) != 0) {
            printGenreLine(buku[i].genre);
            printHeaderTabel();
            strcpy(lastGenre, buku[i].genre);
        }

        printf("| %-5s | %-15s | %-30s | %-24s | %-7d |\n",
               buku[i].kode,
               buku[i].genre,
               buku[i].judul,
               buku[i].penulis,
               buku[i].stok
        );
    }

    printf("---------------------------------------------------------------------------------------------------------------\n");


    printf("\nKODE BUKU : ");
    scanf("%s", kodeInput);

    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(buku[i].kode, kodeInput) == 0) {
            found = 1;

            if (buku[i].stok == 0) {
                printf("\nMAAF, STOK BUKU '%s' HABIS >< !!\n", buku[i].judul);
                return 0;
            }

            printf("Ingin meminjam berapa lama?? :D : ");
            scanf("%d", &pem.lamaPinjam);

            strcpy(pem.judul, buku[i].judul);
            strcpy(pem.penulis, buku[i].penulis);
            strcpy(pem.status, "DIPINJAM");

            buku[i].stok--;

            file = fopen("peminjaman.txt", "a");
            if (file != NULL) {
                fprintf(file, "NAMA   : %s\n", pem.nama);
                fprintf(file, "JUDUL  : %s\n", pem.judul);
                fprintf(file, "PENULIS: %s\n", pem.penulis);
                fprintf(file, "DURASI : %d hari\n", pem.lamaPinjam);
                fprintf(file, "STATUS : %s\n", pem.status);
                fprintf(file, "----------------------------------------\n");
                fclose(file);
            }

            printf("\n=== BUKTI PEMINJAMAN ===\n");
            printf("NAMA PEMINJAM : %s\n", pem.nama);
            printf("JUDUL BUKU    : %s\n", pem.judul);
            printf("PENULIS       : %s\n", pem.penulis);
            printf("LAMA PINJAM   : %d hari\n", pem.lamaPinjam);
            printf("STATUS        : %s\n", pem.status);
            break;
        }
    }

    if (!found) {
        printf("\nKODE BUKU TIDAK DITEMUKAN! ;o\n");
    }

    return 0;
}
