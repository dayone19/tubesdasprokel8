#include <stdio.h>
#include "beli.h"
#include "pinjam.h"
#include "laporan.h"
#include "login.h"
#include "warna.h"
#include "pembukaan.h"


int pilih_pembeli;
int huruf2;

void kontrol_pembeli() {
    printf("Input pilihanmu : ");
    huruf2 = scanf("%d", &pilih_pembeli);

    while (huruf2 != 1 || pilih_pembeli < 1 || pilih_pembeli > 3)
    {
        printf("Pilihan tidak valid!\nSilahkan input ulang : ");
        while (getchar() != '\n');
        huruf2 = scanf("%d", &pilih_pembeli);
    }
    
    switch (pilih_pembeli) {
        case 1:
        beli_pembeli();
        break;
        case 2:
        pinjam_buku();
        break;
        case 3:
        kembalikan_buku();
        break;

    }
}

int pilih_karyawan;
int huruf3;
void kontrol_karyawan() {
    
    printf("Input pilihanmu : ");
    huruf3 = scanf("%d", &pilih_karyawan);

    while (huruf3 != 1 || pilih_karyawan < 1 || pilih_karyawan > 3)
    {
        printf("Pilihan tidak valid!\nSilahkan input ulang : ");
        while (getchar() != '\n');
        huruf3 = scanf("%d", &pilih_karyawan);
    }
    
    switch (pilih_karyawan) {
        case 1:
        laporan_penjualan();
        break;
        case 2:
        laporan_peminjaman();
        break;
        case 3:
        laporan_gabungan();
        break;

    }

}