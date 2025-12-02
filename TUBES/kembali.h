#ifndef KEMBALI_H
#define KEMBALI_H

#include <stdio.h>
#include <string.h>
#include "warna.h"

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
    int hariPinjam;
    int dendaTersimpan;
} Peminjaman;

int kembalikan_buku() {

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

    int jumlahBuku = sizeof(buku)/sizeof(buku[0]);

    FILE *f = fopen("peminjaman.txt","r");
    if (!f) {
        printf("%sFile peminjaman.txt tidak ditemukan!%s\n", merah, putih);
        return 0;
    }

    FILE *temp = fopen("temp.txt","w");

    Peminjaman data;
    char namaInput[50];
    int hariKembali;
    int found = 0;

    printf("%sMasukkan nama peminjam : %s", pink, putih);
    scanf(" %[^\n]", namaInput);

    while (fscanf(f,"%[^|]|%[^|]|%[^|]|%d|%d\n",
                  data.nama, data.judul, data.penulis,
                  &data.hariPinjam, &data.dendaTersimpan) != EOF)
    {
        if (strcmp(data.nama, namaInput)==0) {
            found = 1;

            printf("\n%s=== DATA DITEMUKAN ===%s\n", hijau, putih);
            printf("Nama Peminjam : %s\n", data.nama);
            printf("Judul Buku    : %s\n", data.judul);
            printf("Penulis       : %s\n", data.penulis);
            printf("Lama Pinjam   : %d hari\n", data.hariPinjam);

            printf("\n%sTotal hari sampai pengembalian : %s", kuning, putih);
            scanf("%d", &hariKembali);

            int selisih = hariKembali - data.hariPinjam;
            if (selisih < 0) selisih += 30;

            int denda = selisih * 10000;

            printf("\n%s=== BUKTI PENGEMBALIAN ===%s\n", hijau, putih);
            printf("Nama Peminjam : %s\n", data.nama);
            printf("Judul Buku    : %s\n", data.judul);
            printf("Penulis       : %s\n", data.penulis);
            printf("Total Hari    : %d hari\n", hariKembali);

            if (selisih > 0) {
                printf("%sTerlambat     : %d hari%s\n", merah, selisih, putih);
                printf("%sDenda         : Rp %d%s\n", merah, denda, putih);
            } else {
                printf("%sTerlambat     : Tidak terlambat%s\n", hijau, putih);
                printf("%sDenda         : Rp 0%s\n", hijau, putih);
            }

            for (int i=0; i<jumlahBuku; i++) {
                if (strcmp(buku[i].judul, data.judul)==0) {
                    buku[i].stok++;
                    printf("\nStok Buku '%s' sekarang: %d\n",
                           buku[i].judul, buku[i].stok);
                    break;
                }
            }

        } else {
            fprintf(temp,"%s|%s|%s|%d|%d\n",
                    data.nama, data.judul, data.penulis,
                    data.hariPinjam, data.dendaTersimpan);
        }
    }

    fclose(f);
    fclose(temp);

    remove("peminjaman.txt");
    rename("temp.txt","peminjaman.txt");

    if (!found) {
        printf("%s\nNama tidak ditemukan data peminjam!%s\n", merah, putih);
    } else {
        printf("\n%sDATA BERHASIL DIHAPUS DARI PEMINJAMAN DAN STOK DIUPDATE%s\n", hijau, putih);
    }

    return 0;
}
#endif
