#ifndef KEMBALI_H
#define KEMBALI_H

#include <stdio.h>
#include <string.h>
#include "warna.h"
#include "pinjam.h"

int kembalikan_buku() {

    FILE *f = fopen("peminjaman.txt","r");
    if (!f) {
        printf("%sFile peminjaman.txt tidak ditemukan!%s\n", merah, putih);
        return 0;
    }

    FILE *temp = fopen("temp.txt","w");
    if (!temp) {
        fclose(f);
        printf("%sGagal membuat file sementara!%s\n", merah, putih);
        return 0;
    }

    peminjaman data;
    char namaInput[50];
    int found = 0;

    printf("%sMasukkan nama peminjam : %s", pink, putih);
    scanf(" %[^\n]", namaInput);

    while(fscanf(f,"%[^|]|%[^|]|%[^|]|%d|%[^\n]\n",
                 data.nama, data.judul, data.penulis,
                 &data.lamaPinjam, data.status) != EOF)
    {
        if(strcmp(data.nama, namaInput) == 0 && strcmp(data.status, "DIPINJAM") == 0) {
            found = 1;

            printf("%s=== DATA DITEMUKAN ===%s\n", hijau, putih);
            printf("Nama Peminjam : %s\n", data.nama);
            printf("Judul Buku    : %s\n", data.judul);
            printf("Penulis       : %s\n", data.penulis);
            printf("Lama Pinjam   : %d hari\n", data.lamaPinjam);

            printf("\n%sBuku dikembalikan%s\n", hijau, putih);
            fprintf(temp,"%s|%s|%s|%d|%s\n", data.nama, data.judul, data.penulis, data.lamaPinjam, "KEMBALI");

        } else {
            fprintf(temp,"%s|%s|%s|%d|%s\n", data.nama, data.judul, data.penulis, data.lamaPinjam, data.status);
        }
    }

    fclose(f);
    fclose(temp);

    remove("peminjaman.txt");
    rename("temp.txt", "peminjaman.txt");

    if(!found){
        printf("%sNama peminjam tidak ditemukan atau buku sudah dikembalikan!%s\n", merah, putih);
    } else {
        printf("%sPengembalian berhasil.%s\n", hijau, putih);
    }

    return 0;
}

#endif
