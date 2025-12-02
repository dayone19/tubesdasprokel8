#ifndef LAPORAN_H
#define LAPORAN_H

#include <stdio.h>
#include <string.h>
#include "beli.h"
#include "pinjam.h"
#include "warna.h"

void laporan_penjualan() {
    FILE *f = fopen("pembelian.txt","r");
    if (!f) {
        printf("\nBelum ada pembelian.\n");
        return;
    }

    printf("%s================= LAPORAN PENJUALAN =================%s\n", pink, putih);
    printf("| %-3s | %-6s | %-32s | %-4s | %-11s | %-11s |\n",
           "No", "Kode", "Judul", "Qty", "Harga", "Subtotal");
    printf("-------------------------------------------------------------"
           "-----------------\n");

    char line[200];
    int no = 1;
    while(fgets(line,sizeof(line),f)) {
        char kode[10], judul[40];
        int jumlah;
        float harga, subtotal;
        sscanf(line,"%9[^|]|%39[^|]|%d|%f|%f", kode, judul, &jumlah, &harga, &subtotal);
        printf("| %-3d | %-6s | %-32s | %-4d | Rp%-9.0f | Rp%-11.0f |\n",
               no++, kode, judul, jumlah, harga, subtotal);
    }

    printf("-------------------------------------------------------------"
           "-----------------\n");
    fclose(f);
}

void laporan_peminjaman() {
    FILE *f = fopen("peminjaman.txt","r");
    if (!f) {
        printf("\nBelum ada peminjaman.\n");
        return;
    }

    printf("%s================= LAPORAN PEMINJAMAN =================%s\n", hijau, putih);
    printf("| %-3s | %-20s | %-30s | %-20s | %-5s | %-10s |\n",
           "No", "Nama Peminjam", "Judul Buku", "Penulis", "Hari", "Status");
    printf("--------------------------------------------------------------------------"
           "------------------\n");

    char line[200];
    int no = 1;
    while(fgets(line,sizeof(line),f)) {
        char nama[50], judul[100], penulis[50], status[20];
        int lama;
        sscanf(line,"%49[^|]|%99[^|]|%49[^|]|%d|%19[^\n]", nama, judul, penulis, &lama, status);
        printf("| %-3d | %-20s | %-30s | %-20s | %-5d | %-10s |\n",
               no++, nama, judul, penulis, lama, status);
    }

    printf("--------------------------------------------------------------------------"
           "------------------\n");

    fclose(f);
}

void laporan_gabungan() {
    printf("\n===== LAPORAN PENJUALAN =====\n");
    laporan_penjualan();
    laporan_peminjaman();
}

#endif
