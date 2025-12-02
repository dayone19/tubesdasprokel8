#ifndef BELI_H
#define BELI_H

#include <stdio.h>
#include <string.h>

typedef struct {
    char kode[10];
    char judul[40];
    char penulis[30];
    char genre[20];
    float harga;
    int stok;
} Buku;

typedef struct {
    char kode_buku[10];
    char judul[40];
    int jumlah;
    float harga_satuan;
    float subtotal;
} ItemTransaksi;

/* Data global */
Buku daftarBuku[19];
ItemTransaksi keranjang[50];
int jumlahBuku = 19;
int jumlahItem = 0;
int nomorTransaksi = 1;

/* Inisialisasi data buku */
void initDataBuku() {
    Buku init[] = {
        {"R01","Milea: Suara Dari Dilan","Pidi Baiq","Romance",70000,10},
        {"R02","Mariposa","Luluk HF","Romance",100000,10},
        {"R03","00:00","Amalya Falensia","Romance",90000,15},
        {"R04","Ayat-Ayat Cinta","Habiburrahman El Shirazy","Romance",72000,5},
        {"R05","Sepothan","Popi Pertiwi","Romance",99000,2},
        {"H01","Kuchisake-Apakah Aku Cantik?","Hastono N.H.","Horror",60000,7},
        {"H02","Danur","Risa Saraswati","Horror",80000,20},
        {"H03","KKN Desa Penari","Simpleman","Horror",77000,9},
        {"C01","My Stupid Boss","Chaos@work","Comedy",85000,2},
        {"C02","Sabtu Bersama Bapak","Adhitya Mulya","Comedy",120000,15},
        {"C03","Stripeto","chara.paradise","Comedy",45000,5},
        {"S01","Keajaiban Toko Kelontong Namia","Keigo Higashino","Slice of Life",130000,8},
        {"S02","Keluarga Cemara","Arswando", "Slice of Life",85000,6},
        {"S03","Laskar Pelangi","Andrea Hirata","Slice of Life",100000,2},
        {"A01","Tanah Para Bandit","Tere Liye","Action",85000,11},
        {"A02","Negeri Para Bedebah","Tere Liye","Action",100000,15},
        {"T01","Holy Mother","Akiyoshi Rikako","Thriller",85000,8},
        {"T02","Pasien","Naomi Midori","Thriller",90000,4},
        {"T03","IT","Stephen King","Thriller",110000,7},
    };
    memcpy(daftarBuku, init, sizeof(init));
}

/* Tabel buku */
void tampilkanTabelBuku(char genre[]) {
    printf("\n========================================================================================\n");
    printf("| %-6s | %-32s | %-24s | %-11s | %-5s |\n",
           "KODE","JUDUL","PENULIS","HARGA","STOK");
    printf("========================================================================================\n");

    int ada = 0;
    for (int i = 0; i < jumlahBuku; i++) {
        if (strlen(genre)==0 || strcmp(daftarBuku[i].genre, genre)==0) {
            printf("| %-6s | %-32s | %-24s | Rp%-9.0f | %-5d |\n",
                daftarBuku[i].kode,
                daftarBuku[i].judul,
                daftarBuku[i].penulis,
                daftarBuku[i].harga,
                daftarBuku[i].stok);
            ada = 1;
        }
    }

    printf("========================================================================================\n");
    if (!ada) printf("Tidak ada buku dalam kategori ini.\n");
}

int cariBuku(char kode[]) {
    for (int i = 0; i < jumlahBuku; i++)
        if (strcmp(daftarBuku[i].kode, kode) == 0) return i;
    return -1;
}

/* Pilih genre */
int menuGenreBeli() {
    char list[][20] = {"","Romance","Horror","Comedy","Slice of Life","Action","Thriller"};

    printf("\n=== PILIH GENRE ===\n");
    printf("1. Romance\n2. Horror\n3. Comedy\n4. Slice of Life\n5. Action\n6. Thriller\n0. Kembali\n");
    printf("Pilih (0-6): ");

    int p;
    scanf("%d",&p);

    if (p>=1 && p<=6) tampilkanTabelBuku(list[p]);
    return p;
}

/* Proses beli */
void prosesPembelian() {
    jumlahItem = 0;

    while (1) {
        int pilih = menuGenreBeli();
        if (pilih == 0) break;

        while (1) {
            char kode[10];
            printf("\nMasukkan kode buku (0 untuk ganti genre): ");
            scanf("%s", kode);

            if (strcmp(kode,"0")==0) break;

            int idx = cariBuku(kode);
            if (idx == -1) {
                printf("Kode tidak ditemukan!\n");
                continue;
            }

            int jumlah;
            printf("Buku: %s\nHarga: Rp%.0f\nStok: %d\n",
                   daftarBuku[idx].judul, daftarBuku[idx].harga, daftarBuku[idx].stok);

            printf("Jumlah beli: ");
            scanf("%d",&jumlah);

            if (jumlah <= 0 || jumlah > daftarBuku[idx].stok) {
                printf("Jumlah tidak valid atau stok kurang.\n");
                continue;
            }

            ItemTransaksi *it = &keranjang[jumlahItem++];
            strcpy(it->kode_buku, daftarBuku[idx].kode);
            strcpy(it->judul, daftarBuku[idx].judul);
            it->jumlah = jumlah;
            it->harga_satuan = daftarBuku[idx].harga;
            it->subtotal = jumlah * it->harga_satuan;

            daftarBuku[idx].stok -= jumlah;

            printf("Buku ditambahkan ke keranjang!\n");

            char lagi;
            printf("Tambah lagi buku dari genre ini? (y/n): ");
            scanf(" %c",&lagi);

            if (lagi!='y' && lagi!='Y') break;
        }

        char ganti;
        printf("\nPilih genre lain? (y/n): ");
        scanf(" %c",&ganti);
        if (ganti!='y' && ganti!='Y') break;
    }
}

/* Struk */
void cetakStruk(char nama[], float total, float bayar) {
    float kembali = bayar - total;

    printf("\n========================================================================================\n");
    printf("                               STRUK PEMBELIAN\n");
    printf("========================================================================================\n");
    printf("Nama Pembeli : %s\n", nama);

    printf("========================================================================================\n");
    printf("| %-6s | %-32s | %-4s | %-11s | %-11s |\n",
           "KODE","JUDUL","QTY","HARGA","SUBTOTAL");
    printf("========================================================================================\n");

    for (int i = 0; i < jumlahItem; i++) {
        printf("| %-6s | %-32s | %-4d | Rp%-9.0f | Rp%-11.0f |\n",
            keranjang[i].kode_buku, keranjang[i].judul,
            keranjang[i].jumlah, keranjang[i].harga_satuan, keranjang[i].subtotal);
    }

    printf("========================================================================================\n");
    printf("Total Bayar : Rp%.0f\n", total);
    printf("Bayar       : Rp%.0f\n", bayar);
    printf("Kembalian   : Rp%.0f\n", kembali);
    printf("========================================================================================\n");
}

/* Transaksi */
void transaksi() {
    if (jumlahItem == 0) {
        printf("Keranjang kosong!\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < jumlahItem; i++) total += keranjang[i].subtotal;

    char nama[100];
    getchar();
    printf("Nama Pembeli: ");
    fgets(nama, sizeof(nama), stdin);
    nama[strcspn(nama,"\n")] = 0;

    float bayar;
    do {
        printf("Total: Rp%.0f\nBayar: Rp", total);
        scanf("%f",&bayar);
        if (bayar < total)
            printf("Uang kamu kurang!\n");
    } while (bayar < total);

    cetakStruk(nama, total, bayar);
}

/* Menu Beli */
void menuBeli() {
    initDataBuku();

    int p;
    printf("\n=== MENU PEMBELIAN ===\n");
    printf("1. Lihat Semua Buku\n");
    printf("2. Pilih Genre dan Beli Buku\n");
    printf("0. Kembali\n");
    printf("Pilih: ");
    scanf("%d",&p);

    switch (p) {
        case 1:
            tampilkanTabelBuku("");
            printf("Tekan Enter untuk kembali...");
            getchar(); getchar();
            menuBeli();
            break;
        case 2:
            prosesPembelian();
            transaksi();
            break;
        case 0:
            return;
        default:
            printf("Pilihan tidak valid.\n");
            menuBeli();
    }
}

#endif
