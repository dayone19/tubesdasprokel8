#ifndef BELI_H
#define BELI_H

#include <stdio.h>
#include "warna.h"

int huruf4;
int genre;

struct genre {
    char kode[5];
    char judul[50];
    char penulis[40];
    int harga;
    int stok;
};

void switch_pilihan();
void proses_pembelian();
void struk(FILE *file, char nama[], char kode[], int harga, int jumlah, int total);
void romance() {
    struct genre Romance[] = {
        {"R01", "Milea: Suara Dari Dilan", "Pidi Baiq", 70000, 10},
        {"R02", "Mariposa", "Luluk HF", 110000, 10},
        {"R03", "00.00", "Ameylia Falensia", 90000, 15},
        {"R04", "Ayat-Ayat Cinta", "Habiburrahman El Shirazy", 72000, 5},
        {"R05", "Septihan", "Popi Pertiwi", 99000, 2}
    };

    int jlh_romance = 5;

    printf("\n%s=================================================== %sGENRE ROMANCE %s==================================================%s\n", kuning, pink, kuning, putih);
    printf("| %-6s | %-40s | %-40s | %-8s | %-5s |\n", "Kode", "Judul", "Penulis", "Harga", "Stok");
    for(int i = 0; i < jlh_romance; i++) {
        printf("| %-6s | %-40s | %-40s | %-8d | %-5d |\n", Romance[i].kode, Romance[i].judul, Romance[i].penulis, Romance[i].harga, Romance[i].stok);
    }
    printf("\n%s=================================================== %sGENRE ROMANCE %s==================================================%s\n", kuning, pink, kuning, putih);

    char jawab;
    printf("Apakah ingin membeli buku dari genre ini? (y/n): ");
    getchar();
    scanf("%c", &jawab);

    if(jawab == 'y' || jawab == 'Y') {
        proses_pembelian();
    } else {
        printf("\nKembali ke menu genre...\n");
        switch_pilihan();
    }
}

void switch_pilihan();
void proses_pembelian();
void struk(FILE *file, char nama[], char kode[], int harga, int jumlah, int total);
void horror() {
     struct genre Horror[] = {
        {"H01", "Kuchisake-Apakah Aku Cantik?", "Hastong N.H.", 60000, 7},
        {"H02", "Danur", "Risa Saraswati", 80000, 20},
        {"H03", "KKN Desa Penari", "Simplemen", 77000, 9}
    };
    int jlh = 3;

    printf("\n%s=================================================== %sGENRE HORROR %s==================================================%s\n", kuning, pink, kuning, putih);
    printf("| %-6s | %-40s | %-40s | %-8s | %-5s |\n","Kode", "Judul", "Penulis", "Harga", "Stok");
    for (int i = 0; i < jlh; i++) {
         printf("| %-6s | %-40s | %-40s | %-8d | %-5d |\n",
               Horror[i].kode, Horror[i].judul, Horror[i].penulis,
               Horror[i].harga, Horror[i].stok);
    }
    printf("\n%s=================================================== %sGENRE HORROR %s==================================================%s\n", kuning, pink, kuning, putih);

    char jawab;
    printf("Apakah ingin membeli buku dari genre ini? (y/n): ");
    getchar();
    scanf("%c", &jawab);

    if(jawab == 'y' || jawab == 'Y') {
        proses_pembelian();
    } else {
        printf("\nKembali ke menu genre...\n");
        switch_pilihan();
    }
}

void switch_pilihan();
void proses_pembelian();
void struk(FILE *file, char nama[], char kode[], int harga, int jumlah, int total);
void comedy() {
     struct genre Comedy[] = {
        {"C01", "My Stupid Boss", "chaos@work", 85000, 2},
        {"C02", "Sabtu Bersama Bapak", "Adhitya Mulya", 120000, 15},
        {"C03", "Skripsip", "Chara Perdana", 45000, 5}
    };
    int jlh = 3;

    printf("\n%s=================================================== %sGENRE COMEDY %s==================================================%s\n", kuning, pink, kuning, putih);
     printf("| %-6s | %-40s | %-40s | %-8s | %-5s |\n", "Kode", "Judul", "Penulis", "Harga", "Stok");
    for (int i = 0; i < jlh; i++) {
         printf("| %-6s | %-40s | %-40s | %-8d | %-5d |\n",
               Comedy[i].kode, Comedy[i].judul, Comedy[i].penulis,
               Comedy[i].harga, Comedy[i].stok);
    }
    printf("\n%s=================================================== %sGENRE COMEDY %s==================================================%s\n", kuning, pink, kuning, putih);

    char jawab;
    printf("Apakah ingin membeli buku dari genre ini? (y/n): ");
    getchar();
    scanf("%c", &jawab);

    if(jawab == 'y' || jawab == 'Y') {
        proses_pembelian();
    } else {
        printf("\nKembali ke menu genre...\n");
        switch_pilihan();
    }
}

void switch_pilihan();
void proses_pembelian();
void struk(FILE *file, char nama[], char kode[], int harga, int jumlah, int total);
void slice_of_life() {
      struct genre Slice[] = {
        {"S01", "Keajaiban Toko Kelontong Namia", "Keigo Higashino", 130000, 8},
        {"S02", "Keluarga Cemara", "Arswendo Atmowiloto", 85000, 5},
        {"S03", "Laskar Pelangi", "Andrea Hirata", 100000, 2}
    };
    int jlh = 3;

    printf("\n%s================================================ %sGENRE SLICE OF LIVE %s===============================================%s\n", kuning, pink, kuning, putih);
     printf("| %-6s | %-40s | %-40s | %-8s | %-5s |\n",
           "Kode", "Judul", "Penulis", "Harga", "Stok");
    for (int i = 0; i < jlh; i++) {
         printf("| %-6s | %-40s | %-40s | %-8d | %-5d |\n",
               Slice[i].kode, Slice[i].judul, Slice[i].penulis,
               Slice[i].harga, Slice[i].stok);
    }
    printf("\n%s================================================ %sGENRE SLICE OF LIVE %s===============================================%s\n", kuning, pink, kuning, putih);

    char jawab;
    printf("Apakah ingin membeli buku dari genre ini? (y/n): ");
    getchar();
    scanf("%c", &jawab);

    if(jawab == 'y' || jawab == 'Y') {
        proses_pembelian();
    } else {
        printf("\nKembali ke menu genre...\n");
        switch_pilihan();
    }
}

void switch_pilihan();
void proses_pembelian();
void struk(FILE *file, char nama[], char kode[], int harga, int jumlah, int total);
void action() {
     struct genre Action[] = {
        {"A01", "Tanah Para Bandit", "Tere Liye", 95000, 11},
        {"A02", "Negeri Para Bedebah", "Tere Liye", 100000, 15}
    };
    int jlh = 2;

    printf("\n%s=================================================== %sGENRE ACTION %s==================================================%s\n", kuning, pink, kuning, putih);
     printf("| %-6s | %-40s | %-40s | %-8s | %-5s |\n",
           "Kode", "Judul", "Penulis", "Harga", "Stok");
    for (int i = 0; i < jlh; i++) {
         printf("| %-6s | %-40s | %-40s | %-8d | %-5d |\n",
               Action[i].kode, Action[i].judul, Action[i].penulis,
               Action[i].harga, Action[i].stok);
    }
    printf("\n%s=================================================== %sGENRE ACTION %s==================================================%s\n", kuning, pink, kuning, putih);
    
    char jawab;
    printf("Apakah ingin membeli buku dari genre ini? (y/n): ");
    getchar();
    scanf("%c", &jawab);

    if(jawab == 'y' || jawab == 'Y') {
        proses_pembelian();
    } else {
        printf("\nKembali ke menu genre...\n");
        switch_pilihan();
    }
}

void switch_pilihan();
void proses_pembelian();
void struk(FILE *file, char nama[], char kode[], int harga, int jumlah, int total);
void thriller() {
     struct genre Thriller[] = {
        {"T01", "Holy Mother", "Akiyoshi Rikako", 85000, 8},
        {"T02", "Pasien", "Naomi Midori", 75000, 6},
        {"T03", "IT", "Stephen King", 110000, 7}
    };
    int jlh = 3;

    printf("\n%s=================================================== %sGENRE THRILLER %s==================================================%s\n", kuning, pink, kuning, putih);
    printf("| %-6s | %-40s | %-40s | %-8s | %-5s |\n","Kode", "Judul", "Penulis", "Harga", "Stok");
    for (int i = 0; i < jlh; i++) {
         printf("| %-6s | %-40s | %-40s | %-8d | %-5d |\n",
               Thriller[i].kode, Thriller[i].judul, Thriller[i].penulis,
               Thriller[i].harga, Thriller[i].stok);
    }
    printf("\n%s=================================================== %sGENRE THRILLER %s==================================================%s\n", kuning, pink, kuning, putih);
    
    char jawab;
    printf("Apakah ingin membeli buku dari genre ini? (y/n): ");
    getchar();
    scanf("%c", &jawab);

    if(jawab == 'y' || jawab == 'Y') {
        proses_pembelian();
    } else {
        printf("\nKembali ke menu genre...\n");
        switch_pilihan();
    }
}

void switch_pilihan();
void proses_pembelian();
void struk(FILE *file, char nama[], char kode[], int harga, int jumlah, int total);
void switch_pilihan() {
    printf("Mau lihat genre yang mana : ");
    huruf4 = scanf("%d", &genre);

     while (huruf4 != 1 || genre < 1 || genre > 6)
     {
        printf("Pilihan tidak valid! Silahkan input ulang : ");
        while (getchar() != '\n');
        huruf4 = scanf("%d", &genre);
     }
    
        switch (genre) {
        case 1:
          romance();
          break;
        case 2:
          horror();
          break;
        case 3:
          comedy();
          break;
        case 4:
          slice_of_life();
          break;
        case 5:
          action();
          break;
        case 6:
          thriller();
          break;
      }
}

char kode[5];
char nama_pembeli[50];
int harga, jumlah, total;

void proses_pembelian() {
    printf("Masukkan nama kamu : \n");
    getchar();
    fgets(nama_pembeli, sizeof(nama_pembeli), stdin);

    printf("Masukkan kode buku : \n");
    scanf("%s", kode);

    printf("Masukkan harga buku : \n");
    scanf("%d", &harga);

    printf("Jumlah buku yang dibeli : \n");
    scanf("%d", &jumlah);

    total = harga * jumlah;
}

void struk(FILE *file, char nama[], char kode[], int harga, int jumlah, int total) {
    fprintf(file,"\n=================== STRUK PEMBELIAN ===================\n" );
    fprintf(file,"Nama Pembeli : %s\n",nama);
    fprintf(file,"Kode Buku    : %s\n",kode);
    fprintf(file,"Harga Satuan : %d\n",harga);
    fprintf(file,"Jumlah Beli  : %d\n",jumlah);
    fprintf(file,"Total Bayar  : %d\n",total);
    fprintf(file,"========================================================\n");
}
void beli_pembeli() {
  FILE *file = fopen("speminjaman.txt", "a");

    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    
    printf("%s-------------------------------------------------------------\n%s",pink,putih);
    printf("        %s---%s>%s Pilih Genre Buku %s<%s---%s\n", pink,kuning,putih,kuning,pink,putih);
    printf("%s--------------------%s----------------------%s\n", kuning, hijau);
    printf("%s|----------------->%s 1.%s Romance           %s|%s\n", pink, kuning, putih, pink, putih);
    printf("%s|----------------->%s 2.%s Horror            %s|%s\n", pink, kuning, putih, pink, putih);
    printf("%s|----------------->%s 3.%s Comedy            %s|%s\n", pink, kuning, putih, pink, putih);
    printf("%s|----------------->%s 4.%s Slice Of Life     %s|%s\n", pink, kuning, putih, pink, putih);
    printf("%s|----------------->%s 5.%s Action            %s|%s\n", pink, kuning, putih, pink, putih);
    printf("%s|----------------->%s 6.%s Thriller          %s|%s\n", pink, kuning, putih, pink, putih);
    printf("%s--------------------%s----------------------%s\n", kuning, hijau);

    switch_pilihan();
    struk(file, nama_pembeli, kode, harga, jumlah, total);
    fclose(file);
    printf("Struk berhasil dicetak.\n");
}
#endif
