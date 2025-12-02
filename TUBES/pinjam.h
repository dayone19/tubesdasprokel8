#include <stdio.h>
#include <string.h>
#include "warna.h"
typedef struct {
    char kode[10];
    char genre[30];
    char judul[100];
    char penulis[50];
    int stok;
} buku;

typedef struct {
    char nama[50];
    char judul[100];
    char penulis[50];
    int lamaPinjam;
    char status[20];
} peminjaman;

void printHeaderJudul() {
    printf("%s=============================================================%s\n", pink, putih);
    printf("%s|                                                           |%s\n", pink, putih);
    printf("%s|                DAFTAR BUKU YANG BISA DIPINJAM             |%s\n", pink, putih);
    printf("%s|                                                           |%s\n", pink, putih);
    printf("%s=============================================================%s\n", pink, putih);
}

void printHeaderTabel() {
    printf("%s---------------------------------------------------------------------------------------------------------------%s\n", kuning, putih);
    printf("%s| KODE  |      GENRE       |             JUDUL BUKU             |          PENULIS          |   STOK   |%s\n",
           kuning, putih);
    printf("%s---------------------------------------------------------------------------------------------------------------%s\n", kuning, putih);
}

void printGenreLine(const char *genre) {
    printf("%s---------------------------------------------------------------------------------------------------------------%s\n", hijau, putih);
    printf("%s>>> %s%s\n", hijau, genre, putih);
    printf("%s---------------------------------------------------------------------------------------------------------------%s\n", hijau, putih);
}

int pinjam_buku() {

    buku buku[] = {
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
    peminjaman pem;
    char kodeInput[10];
    int found = 0;

    FILE *file;

    printf("%sNama Peminjam:%s ", pink, putih);
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

    printf("%s---------------------------------------------------------------------------------------------------------------%s\n", kuning, putih);

    printf("\nMasukkan kode buku: ");
    scanf("%s", kodeInput);

    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(buku[i].kode, kodeInput) == 0) {
            found = 1;

            if (buku[i].stok == 0) {
                printf("\n%sMAAF, STOK BUKU '%s' HABIS.%s\n", pink, buku[i].judul, putih);
                return 0;
            }

            printf("Lama peminjaman (hari): ");
            scanf("%d", &pem.lamaPinjam);

            strcpy(pem.judul, buku[i].judul);
            strcpy(pem.penulis, buku[i].penulis);
            strcpy(pem.status, "DIPINJAM");

            buku[i].stok--;

            file = fopen("peminjaman.txt", "a");
            if (file != NULL) {
                fprintf(file, "\n=== BUKTI PEMINJAMAN ===\n");
                fprintf(file, "NAMA   : %s\n", pem.nama);
                fprintf(file, "JUDUL  : %s\n", pem.judul);
                fprintf(file, "PENULIS: %s\n", pem.penulis);
                fprintf(file, "DURASI : %d hari\n", pem.lamaPinjam);
                fprintf(file, "STATUS : %s\n", pem.status);
                fprintf(file, "----------------------------------------\n");
                fclose(file);
            }

            printf("\n%s=== BUKTI PEMINJAMAN ===%s\n", hijau, putih);
            printf("Nama Peminjam : %s\n", pem.nama);
            printf("Judul Buku    : %s\n", pem.judul);
            printf("Penulis       : %s\n", pem.penulis);
            printf("Lama Pinjam   : %d hari\n", pem.lamaPinjam);
            printf("Status        : %s\n", pem.status);
            break;
        }
    }

    if (!found) {
        printf("\n%sKODE BUKU TIDAK DITEMUKAN!%s\n", pink, putih);
    }

    return 0;
}