#ifndef BELI_H
#define BELI_H

#include <stdio.h>
#include <string.h>

/* Struct untuk data buku */
typedef struct {
    char kode[10];
    char judul[40];
    char penulis[30];
    char genre[20];
    float harga;
    int stok;
} Buku;

/* Struct untuk item transaksi */
typedef struct {
    char kode_buku[10];
    char judul[40];
    int jumlah;
    float harga_satuan;
    float subtotal;
} ItemTransaksi;

/* Global variables untuk modul beli */
Buku daftarBuku[19];
ItemTransaksi keranjang[50];
int jumlahBuku = 19;
int jumlahItem = 0;
int nomorTransaksi = 1;

/* Inisialisasi data buku */
void initDataBuku() {
    Buku bukuInit[19] = {
        {"R01", "Milea: Suara Dari Dilan", "Pidi Baiq", "Romance", 70000, 10},
        {"R02", "Mariposa", "Luluk HF", "Romance", 100000, 10},
        {"R03", "00:00", "Amalya Falensia", "Romance", 90000, 15},
        {"R04", "Ayat-Ayat Cinta", "Habiburrahman El Shirazy", "Romance", 72000, 5},
        {"R05", "Sepothan", "Popi Pertiwi", "Romance", 99000, 2},
        {"H01", "Kuchisake-Apakah Aku Cantik?", "Hastono N.H.", "Horror", 60000, 7},
        {"H02", "Danur", "Risa Saraswati", "Horror", 80000, 20},
        {"H03", "KKN Desa Penari", "Simpleman", "Horror", 77000, 9},
        {"C01", "My Stupid Boss", "Chaos@work", "Comedy", 85000, 2},
        {"C02", "Sabtu Bersama Bapak", "Adhitya Mulya", "Comedy", 120000, 15},
        {"C03", "Stripeto", "chara.paradise", "Comedy", 45000, 5},
        {"S01", "Keajaiban Toko Kelontong Namia", "Keigo Higashino", "Slice of Life", 130000, 8},
        {"S02", "Keluarga Cemara", "Arswando Atmowiloto", "Slice of Life", 85000, 6},
        {"S03", "Laskar Pelangi", "Andrea Hirata", "Slice of Life", 100000, 2},
        {"A01", "Tanah Para Bandit", "Tere Liye", "Action", 85000, 11},
        {"A02", "Negeri Para Bedebah", "Tere Liye", "Action", 100000, 15},
        {"T01", "Holy Mother", "Akiyoshi Rikako", "Thriller", 85000, 8},
        {"T02", "Pasien", "Naomi Midori", "Thriller", 90000, 4},
        {"T03", "IT", "Stephen King", "Thriller", 110000, 7}
    };
    memcpy(daftarBuku, bukuInit, sizeof(bukuInit));
}

/* Tampilkan tabel buku dengan alignment yang rapi */
void tampilkanTabelBuku(char genreFilter[]) {
    int i, ada = 0;
    
    printf("\n");
    printf("========================================================================================\n");
    printf("| %-6s | %-32s | %-24s | %-11s | %-5s |\n", 
           "KODE", "JUDUL", "PENULIS", "HARGA", "STOK");
    printf("========================================================================================\n");
    
    for (i = 0; i < jumlahBuku; i++) {
        if (strlen(genreFilter) == 0 || strcmp(daftarBuku[i].genre, genreFilter) == 0) {
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

/* Cari buku berdasarkan kode */
int cariBuku(char kode[]) {
    int i;
    for (i = 0; i < jumlahBuku; i++) {
        if (strcmp(daftarBuku[i].kode, kode) == 0) return i;
    }
    return -1;
}

/* Menu genre untuk pembelian */
int menuGenreBeli() {
    int pilihan;
    char genre[][20] = {"", "Romance", "Horror", "Comedy", "Slice of Life", "Action", "Thriller"};
    
    printf("\n=== PILIH GENRE ===\n");
    printf("1. Romance\n2. Horror\n3. Comedy\n4. Slice of Life\n5. Action\n6. Thriller\n0. Selesai Belanja\n");
    printf("Pilih (0-6): ");
    scanf("%d", &pilihan);
    
    if (pilihan >= 1 && pilihan <= 6) {
        tampilkanTabelBuku(genre[pilihan]);
        return pilihan;
    }
    return 0;
}

/* Proses pembelian dengan bisa pilih genre berulang */
void prosesPembelian() {
    char kodeBuku[10], lanjut;
    int jumlah, indexBuku, pilihanGenre;
    
    jumlahItem = 0;
    
    do {
        pilihanGenre = menuGenreBeli();
        
        if (pilihanGenre == 0) {
            if (jumlahItem == 0) {
                printf("Tidak ada buku yang dibeli.\n");
            }
            return;
        }
        
        do {
            printf("\nMasukkan kode buku (0 untuk ganti genre): ");
            scanf("%s", kodeBuku);
            
            if (strcmp(kodeBuku, "0") == 0) break;
            
            indexBuku = cariBuku(kodeBuku);
            if (indexBuku == -1) {
                printf("Kode buku tidak ditemukan!\n");
                continue;
            }
            
            printf("\nBuku: %s\nHarga: Rp%.0f\nStok: %d\n", 
                   daftarBuku[indexBuku].judul, daftarBuku[indexBuku].harga, daftarBuku[indexBuku].stok);
            
            printf("Masukkan jumlah: ");
            scanf("%d", &jumlah);
            
            if (jumlah <= 0) {
                printf("Jumlah tidak valid!\n");
                continue;
            }
            
            if (jumlah > daftarBuku[indexBuku].stok) {
                printf("Stok tidak cukup! Tersedia: %d\n", daftarBuku[indexBuku].stok);
                continue;
            }
            
            strcpy(keranjang[jumlahItem].kode_buku, daftarBuku[indexBuku].kode);
            strcpy(keranjang[jumlahItem].judul, daftarBuku[indexBuku].judul);
            keranjang[jumlahItem].jumlah = jumlah;
            keranjang[jumlahItem].harga_satuan = daftarBuku[indexBuku].harga;
            keranjang[jumlahItem].subtotal = daftarBuku[indexBuku].harga * jumlah;
            jumlahItem++;
            
            printf("\nBuku ditambahkan ke keranjang!\n");
            
            printf("Tambah buku lagi dari genre ini? (y/n): ");
            scanf(" %c", &lanjut);
            
        } while (lanjut == 'y' || lanjut == 'Y');
        
        if (jumlahItem > 0) {
            printf("\nBeli dari genre lain? (y/n): ");
            scanf(" %c", &lanjut);
            if (lanjut != 'y' && lanjut != 'Y') break;
        }
        
    } while (1);
}

/* Cetak struk */
void cetakStruk(char namaPembeli[], char noTransaksi[], float totalBayar, float uangDibayar, float kembalian) {
    int i;
    FILE *file;
    
    printf("\n========================================================================================\n");
    printf("                             STRUK PEMBELIAN BUKU\n");
    printf("                               TOKO BUKU CERIA\n");
    printf("========================================================================================\n");
    printf("No. Transaksi : %s\n", noTransaksi);
    printf("Nama Pembeli  : %s\n", namaPembeli);
    printf("========================================================================================\n");
    printf("| %-6s | %-32s | %-4s | %-11s | %-13s |\n", 
           "KODE", "JUDUL", "QTY", "HARGA", "SUBTOTAL");
    printf("========================================================================================\n");
    
    for (i = 0; i < jumlahItem; i++) {
        printf("| %-6s | %-32s | %-4d | Rp%-9.0f | Rp%-11.0f |\n",
               keranjang[i].kode_buku, keranjang[i].judul, keranjang[i].jumlah,
               keranjang[i].harga_satuan, keranjang[i].subtotal);
    }
    
    printf("========================================================================================\n");
    printf("Total Bayar   : Rp%.0f\n", totalBayar);
    printf("Uang Dibayar  : Rp%.0f\n", uangDibayar);
    printf("Kembalian     : Rp%.0f\n", kembalian);
    printf("========================================================================================\n");
    printf("            Terima kasih sudah berbelanja di Toko Buku Ceria!\n");
    printf("========================================================================================\n");
    
    /* Simpan ke file */
    file = fopen("struk_pembelian.txt", "a");
    if (file != NULL) {
        fprintf(file, "\n=== TRANSAKSI %s ===\n", noTransaksi);
        fprintf(file, "Pembeli: %s\n", namaPembeli);
        for (i = 0; i < jumlahItem; i++) {
            fprintf(file, "%s | %s | Qty:%d | Rp%.0f | Total:Rp%.0f\n",
                    keranjang[i].kode_buku, keranjang[i].judul, keranjang[i].jumlah,
                    keranjang[i].harga_satuan, keranjang[i].subtotal);
        }
        fprintf(file, "Total: Rp%.0f | Bayar: Rp%.0f | Kembali: Rp%.0f\n\n", 
                totalBayar, uangDibayar, kembalian);
        fclose(file);
    }
}

/* Update stok buku */
void updateStok() {
    int i, indexBuku;
    for (i = 0; i < jumlahItem; i++) {
        indexBuku = cariBuku(keranjang[i].kode_buku);
        if (indexBuku != -1) {
            daftarBuku[indexBuku].stok -= keranjang[i].jumlah;
        }
    }
}

/* Generate nomor transaksi */
void generateNoTransaksi(char noTransaksi[]) {
    sprintf(noTransaksi, "TRX-%03d", nomorTransaksi++);
}

/* Fungsi utama transaksi */
void transaksi() {
    char namaPembeli[100], noTransaksi[20];
    float totalBayar = 0, uangDibayar, kembalian;
    int i;
    
    if (jumlahItem == 0) {
        printf("Keranjang kosong!\n");
        return;
    }
    
    for (i = 0; i < jumlahItem; i++) {
        totalBayar += keranjang[i].subtotal;
    }
    
    printf("\n=== DATA PEMBELI ===\n");
    printf("Nama: ");
    getchar();
    fgets(namaPembeli, sizeof(namaPembeli), stdin);
    namaPembeli[strcspn(namaPembeli, "\n")] = 0;
    
    while (strlen(namaPembeli) == 0) {
        printf("Nama tidak boleh kosong!\nNama: ");
        fgets(namaPembeli, sizeof(namaPembeli), stdin);
        namaPembeli[strcspn(namaPembeli, "\n")] = 0;
    }
    
    printf("\n=== PEMBAYARAN ===\n");
    printf("Total: Rp%.0f\n", totalBayar);
    
    do {
        printf("Bayar: Rp");
        scanf("%f", &uangDibayar);
        
        if (uangDibayar < totalBayar) {
            printf("Uang kurang Rp%.0f!\n", totalBayar - uangDibayar);
        }
    } while (uangDibayar < totalBayar);
    
    kembalian = uangDibayar - totalBayar;
    generateNoTransaksi(noTransaksi);
    updateStok();
    cetakStruk(namaPembeli, noTransaksi, totalBayar, uangDibayar, kembalian);
}

/* Menu utama modul beli */
void menuBeli() {
    int pilihan;
    char dummy;
    
    initDataBuku();
    
    printf("\n========================================================================================\n");
    printf("                        SELAMAT DATANG DI TOKO BUKU CERIA\n");
    printf("========================================================================================\n");
    printf("\n=== MENU PEMBELIAN ===\n");
    printf("1. Lihat Semua Buku\n");
    printf("2. Pilih Genre dan Beli Buku\n");
    printf("0. Kembali\n");
    printf("Pilih: ");
    scanf("%d", &pilihan);
    
    switch (pilihan) {
        case 1:
            tampilkanTabelBuku("");
            printf("\nTekan Enter untuk kembali ke menu pembelian...");
            getchar();
            getchar();
            menuBeli();
            break;
        case 2:
            prosesPembelian();
            if (jumlahItem > 0) transaksi();
            break;
        case 0:
            return;
        default:
            printf("Pilihan tidak valid!\n");
            menuBeli();
    }
}

#endif