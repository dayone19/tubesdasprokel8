#ifndef LAPORAN_H
#define LAPORAN_H

#include <stdio.h>
#include <string.h>
#include "beli.h"
#include "pinjam.h"
#include "warna.h"

/* Laporan penjualan (dari pembelian) */
void laporan_penjualan() {
    if (jumlahItem == 0) {
        printf("\nBelum ada pembelian.\n");
        return;
    }

    printf("%s================= LAPORAN PENJUALAN =================%s\n", pink, putih);
    printf("| %-3s | %-6s | %-32s | %-4s | %-11s | %-11s |\n",
           "No", "Kode", "Judul", "Qty", "Harga", "Subtotal");
    printf("-------------------------------------------------------------"
           "-----------------\n");

    for (int i = 0; i < jumlahItem; i++) {
        printf("| %-3d | %-6s | %-32s | %-4d | Rp%-9.0f | Rp%-11.0f |\n",
               i + 1,
               keranjang[i].kode_buku,
               keranjang[i].judul,
               keranjang[i].jumlah,
               keranjang[i].harga_satuan,
               keranjang[i].subtotal);
    }
    printf("-------------------------------------------------------------"
           "-----------------\n");
}

/* Buku paling diminati dari pembelian */
void buku_paling_diminati() {
    if (jumlahItem == 0) {
        printf("\nBelum ada pembelian.\n");
        return;
    }

    int idx = 0;
    for (int i = 1; i < jumlahItem; i++)
        if (keranjang[i].jumlah > keranjang[idx].jumlah)
            idx = i;

    printf("%s========= BUKU PALING DIMINATI =========%s\n", hijau, putih);
    printf("Kode Buku : %s\n", keranjang[idx].kode_buku);
    printf("Judul     : %s\n", keranjang[idx].judul);
    printf("Jumlah    : %d\n", keranjang[idx].jumlah);
    printf("=======================================\n");
}

/* Catatan pendapatan dari pembelian */
void catatan_pendapatan() {
    if (jumlahItem == 0) {
        printf("\nBelum ada pembelian.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < jumlahItem; i++) total += keranjang[i].subtotal;

    printf("%s========= CATATAN PENDAPATAN =========%s\n", hijau, putih);
    printf("Total Pendapatan: Rp%.0f\n", total);
    printf("======================================\n");
}

#endif
