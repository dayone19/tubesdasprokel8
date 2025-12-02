#ifndef BELI_H
#define BELI_H

#include <stdio.h>
#include <string.h>
#include "warna.h"

#define MAX_BOOK 10

struct Buku {
    char kode[5];
    char judul[50];
    char penulis[40];
    int harga;
    int stok;
};

// daftar genre
char *nama_genre[6] = {
    "Romance", "Horror", "Comedy",
    "Slice of Life", "Action", "Thriller"
};

// buku tiap genre
struct Buku daftar[6][MAX_BOOK];
int jumlah_buku[6] = {5, 3, 3, 3, 2, 3};

// variabel global
char nama_pembeli[50];
char kode_buku[5];
int harga_beli, jumlah_beli, total_beli;

// -----------------------------------------------------------
// LOAD DATA BUKU (biar bersih dan tidak banyak fungsi duplikat)
// -----------------------------------------------------------

void load_data() {

    // ROMANCE
    struct Buku romance_temp[5] = {
        {"R01","Milea: Suara Dari Dilan","Pidi Baiq",70000,10},
        {"R02","Mariposa","Luluk HF",110000,10},
        {"R03","00.00","Ameylia Falensia",90000,15},
        {"R04","Ayat-Ayat Cinta","Habiburrahman El Shirazy",72000,5},
        {"R05","Septihan","Popi Pertiwi",99000,2}
    };
    memcpy(daftar[0], romance_temp, sizeof(romance_temp));

    // HORROR
    struct Buku horror_temp[3] = {
        {"H01","Kuchisake","Hastong N.H.",60000,7},
        {"H02","Danur","Risa Saraswati",80000,20},
        {"H03","KKN Desa Penari","Simplemen",77000,9}
    };
    memcpy(daftar[1], horror_temp, sizeof(horror_temp));

    // COMEDY
    struct Buku comedy_temp[3] = {
        {"C01","My Stupid Boss","chaos@work",85000,2},
        {"C02","Sabtu Bersama Bapak","Adhitya Mulya",120000,15},
        {"C03","Skripsip","Chara Perdana",45000,5}
    };
    memcpy(daftar[2], comedy_temp, sizeof(comedy_temp));

    // SLICE OF LIFE
    struct Buku slice_temp[3] = {
        {"S01","Keajaiban Toko Kelontong","Keigo Higashino",130000,8},
        {"S02","Keluarga Cemara","Arswendo Atmowiloto",85000,5},
        {"S03","Laskar Pelangi","Andrea Hirata",100000,2}
    };
    memcpy(daftar[3], slice_temp, sizeof(slice_temp));

    // ACTION
    struct Buku action_temp[2] = {
        {"A01","Tanah Para Bandit","Tere Liye",95000,11},
        {"A02","Negeri Para Bedebah","Tere Liye",100000,15}
    };
    memcpy(daftar[4], action_temp, sizeof(action_temp));

    // THRILLER
    struct Buku thriller_temp[3] = {
        {"T01","Holy Mother","Akiyoshi Rikako",85000,8},
        {"T02","Pasien","Naomi Midori",75000,6},
        {"T03","IT","Stephen King",110000,7}
    };
    memcpy(daftar[5], thriller_temp, sizeof(thriller_temp));
}

// -----------------------------------------------------------
// TAMPILKAN TABEL GENRE TERTENTU
// -----------------------------------------------------------

void tampilkan_genre(int g) {
    printf("\n%s========================= %sGENRE %s%s =========================%s\n",
        kuning, pink, nama_genre[g], kuning, putih);

    printf("| %-6s | %-35s | %-25s | %-8s | %-5s |\n",
        "Kode", "Judul", "Penulis", "Harga", "Stok");

    for(int i=0;i<jumlah_buku[g];i++){
        printf("| %-6s | %-35s | %-25s | %-8d | %-5d |\n",
            daftar[g][i].kode, daftar[g][i].judul,
            daftar[g][i].penulis, daftar[g][i].harga,
            daftar[g][i].stok);
    }

    printf("%s=======================================================================%s\n",
        kuning, putih);
}

// -----------------------------------------------------------
// PEMBELIAN
// -----------------------------------------------------------

void proses_pembelian() {

    printf("Masukkan nama pembeli: ");
    getchar();
    fgets(nama_pembeli, sizeof(nama_pembeli), stdin);

    printf("Masukkan kode buku: ");
    scanf("%s", kode_buku);

    // cari buku berdasarkan kode
    for(int g=0; g<6; g++){
        for(int i=0; i<jumlah_buku[g]; i++){
            if(strcmp(kode_buku, daftar[g][i].kode)==0){
                harga_beli = daftar[g][i].harga;

                printf("Masukkan jumlah beli: ");
                scanf("%d", &jumlah_beli);

                total_beli = harga_beli * jumlah_beli;
                return;
            }
        }
    }

    printf("Kode buku tidak ditemukan.\n");
}

// -----------------------------------------------------------
// CETAK STRUK
// -----------------------------------------------------------

void struk(FILE *file) {
    fprintf(file,"=================== STRUK PEMBELIAN ===================\n");
    fprintf(file,"Nama Pembeli : %s", nama_pembeli);
    fprintf(file,"Kode Buku    : %s\n", kode_buku);
    fprintf(file,"Harga Satuan : %d\n", harga_beli);
    fprintf(file,"Jumlah Beli  : %d\n", jumlah_beli);
    fprintf(file,"Total Bayar  : %d\n", total_beli);
    fprintf(file,"========================================================\n");
}

// -----------------------------------------------------------
// MENU BELI
// -----------------------------------------------------------

void beli_pembeli() {

    load_data();

    FILE *file = fopen("struk_pembelian.txt","a");
    if(!file){
        printf("File gagal dibuka.\n");
        return;
    }

    printf("%s===== PILIH GENRE =====%s\n", pink, putih);
    for(int i=0;i<6;i++){
        printf("%d. %s\n", i+1, nama_genre[i]);
    }

    int pilih;
    printf("Pilih genre (1-6): ");
    scanf("%d",&pilih);

    if(pilih < 1 || pilih > 6){
        printf("Pilihan tidak valid.\n");
        return;
    }

    tampilkan_genre(pilih-1);
    proses_pembelian();
    struk(file);

    fclose(file);
    printf("Struk berhasil dicetak.\n");
}

#endif
