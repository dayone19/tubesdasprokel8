#include <stdio.h>
#include <string.h>
#include <time.h>

/* Struct untuk data buku */
struct Buku {
    char kode[10];
    char judul[100];
    char penulis[50];
    char genre[20];
    float harga;
    int stok;
};

/* Struct untuk item transaksi */
struct ItemTransaksi {
    char kode_buku[10];
    char judul[100];
    int jumlah;
    float harga_satuan;
    float subtotal;
};

/* Global variables */
struct Buku daftarBuku[19];
struct ItemTransaksi keranjang[50];
int jumlahBuku = 19;
int jumlahItem = 0;
int nomorTransaksiHariIni = 1;

/* Fungsi untuk inisialisasi data buku */
void initDataBuku() {
    /* ROMANCE (R01-R05) */
    strcpy(daftarBuku[0].kode, "R01");
    strcpy(daftarBuku[0].judul, "Milea: Suara Dari Dilan");
    strcpy(daftarBuku[0].penulis, "Pidi Baiq");
    strcpy(daftarBuku[0].genre, "Romance");
    daftarBuku[0].harga = 70000;
    daftarBuku[0].stok = 10;
    
    strcpy(daftarBuku[1].kode, "R02");
    strcpy(daftarBuku[1].judul, "Mariposa");
    strcpy(daftarBuku[1].penulis, "Luluk HF");
    strcpy(daftarBuku[1].genre, "Romance");
    daftarBuku[1].harga = 100000;
    daftarBuku[1].stok = 10;
    
    strcpy(daftarBuku[2].kode, "R03");
    strcpy(daftarBuku[2].judul, "00:00");
    strcpy(daftarBuku[2].penulis, "Amalya Falensia");
    strcpy(daftarBuku[2].genre, "Romance");
    daftarBuku[2].harga = 90000;
    daftarBuku[2].stok = 15;
    
    strcpy(daftarBuku[3].kode, "R04");
    strcpy(daftarBuku[3].judul, "Ayat-Ayat Cinta");
    strcpy(daftarBuku[3].penulis, "Habiburrahman El Shirazy");
    strcpy(daftarBuku[3].genre, "Romance");
    daftarBuku[3].harga = 72000;
    daftarBuku[3].stok = 5;
    
    strcpy(daftarBuku[4].kode, "R05");
    strcpy(daftarBuku[4].judul, "Sepothan");
    strcpy(daftarBuku[4].penulis, "Popi Pertiwi");
    strcpy(daftarBuku[4].genre, "Romance");
    daftarBuku[4].harga = 99000;
    daftarBuku[4].stok = 2;
    
    /* HORROR (H01-H03) */
    strcpy(daftarBuku[5].kode, "H01");
    strcpy(daftarBuku[5].judul, "Kuchisake-Apakah Aku Cantik?");
    strcpy(daftarBuku[5].penulis, "Hastono N.H.");
    strcpy(daftarBuku[5].genre, "Horror");
    daftarBuku[5].harga = 60000;
    daftarBuku[5].stok = 7;
    
    strcpy(daftarBuku[6].kode, "H02");
    strcpy(daftarBuku[6].judul, "Danur");
    strcpy(daftarBuku[6].penulis, "Risa Saraswati");
    strcpy(daftarBuku[6].genre, "Horror");
    daftarBuku[6].harga = 80000;
    daftarBuku[6].stok = 20;
    
    strcpy(daftarBuku[7].kode, "H03");
    strcpy(daftarBuku[7].judul, "KKN Desa Penari");
    strcpy(daftarBuku[7].penulis, "Simpleman");
    strcpy(daftarBuku[7].genre, "Horror");
    daftarBuku[7].harga = 77000;
    daftarBuku[7].stok = 9;
    
    /* COMEDY (C01-C03) */
    strcpy(daftarBuku[8].kode, "C01");
    strcpy(daftarBuku[8].judul, "My Stupid Boss");
    strcpy(daftarBuku[8].penulis, "Chaos@work");
    strcpy(daftarBuku[8].genre, "Comedy");
    daftarBuku[8].harga = 85000;
    daftarBuku[8].stok = 2;
    
    strcpy(daftarBuku[9].kode, "C02");
    strcpy(daftarBuku[9].judul, "Sabtu Bersama Bapak");
    strcpy(daftarBuku[9].penulis, "Adhitya Mulya");
    strcpy(daftarBuku[9].genre, "Comedy");
    daftarBuku[9].harga = 120000;
    daftarBuku[9].stok = 15;
    
    strcpy(daftarBuku[10].kode, "C03");
    strcpy(daftarBuku[10].judul, "Stripeto");
    strcpy(daftarBuku[10].penulis, "chara.paradise");
    strcpy(daftarBuku[10].genre, "Comedy");
    daftarBuku[10].harga = 45000;
    daftarBuku[10].stok = 5;
    
    /* SLICE OF LIFE (S01-S03) */
    strcpy(daftarBuku[11].kode, "S01");
    strcpy(daftarBuku[11].judul, "Keajaiban Toko Kelontong Namia");
    strcpy(daftarBuku[11].penulis, "Keigo Higashino");
    strcpy(daftarBuku[11].genre, "Slice of Life");
    daftarBuku[11].harga = 130000;
    daftarBuku[11].stok = 8;
    
    strcpy(daftarBuku[12].kode, "S02");
    strcpy(daftarBuku[12].judul, "Keluarga Cemara");
    strcpy(daftarBuku[12].penulis, "Arswando Atmowiloto");
    strcpy(daftarBuku[12].genre, "Slice of Life");
    daftarBuku[12].harga = 85000;
    daftarBuku[12].stok = 6;
    
    strcpy(daftarBuku[13].kode, "S03");
    strcpy(daftarBuku[13].judul, "Laskar Pelangi");
    strcpy(daftarBuku[13].penulis, "Andrea Hirata");
    strcpy(daftarBuku[13].genre, "Slice of Life");
    daftarBuku[13].harga = 100000;
    daftarBuku[13].stok = 2;
    
    /* ACTION (A01-A02) */
    strcpy(daftarBuku[14].kode, "A01");
    strcpy(daftarBuku[14].judul, "Tanah Para Bandit");
    strcpy(daftarBuku[14].penulis, "Tere Liye");
    strcpy(daftarBuku[14].genre, "Action");
    daftarBuku[14].harga = 85000;
    daftarBuku[14].stok = 11;
    
    strcpy(daftarBuku[15].kode, "A02");
    strcpy(daftarBuku[15].judul, "Negeri Para Bedebah");
    strcpy(daftarBuku[15].penulis, "Tere Liye");
    strcpy(daftarBuku[15].genre, "Action");
    daftarBuku[15].harga = 100000;
    daftarBuku[15].stok = 15;
    
    /* THRILLER (T01-T03) */
    strcpy(daftarBuku[16].kode, "T01");
    strcpy(daftarBuku[16].judul, "Holy Mother");
    strcpy(daftarBuku[16].penulis, "Akiyoshi Rikako");
    strcpy(daftarBuku[16].genre, "Thriller");
    daftarBuku[16].harga = 85000;
    daftarBuku[16].stok = 8;
    
    strcpy(daftarBuku[17].kode, "T02");
    strcpy(daftarBuku[17].judul, "Pasien");
    strcpy(daftarBuku[17].penulis, "Naomi Midori");
    strcpy(daftarBuku[17].genre, "Thriller");
    daftarBuku[17].harga = 90000;
    daftarBuku[17].stok = 4;
    
    strcpy(daftarBuku[18].kode, "T03");
    strcpy(daftarBuku[18].judul, "IT");
    strcpy(daftarBuku[18].penulis, "Stephen King");
    strcpy(daftarBuku[18].genre, "Thriller");
    daftarBuku[18].harga = 110000;
    daftarBuku[18].stok = 7;
}

/* Fungsi untuk tampilkan tabel buku */
void tampilkanTabelBuku(char genreFilter[]) {
    int i, ada = 0;
    
    printf("\n");
    printf("================================================================================\n");
    printf("| %-6s | %-35s | %-20s | %-10s | %-5s |\n", 
           "KODE", "JUDUL", "PENULIS", "HARGA", "STOK");
    printf("================================================================================\n");
    
    for (i = 0; i < jumlahBuku; i++) {
        if (strlen(genreFilter) == 0 || strcmp(daftarBuku[i].genre, genreFilter) == 0) {
            printf("| %-6s | %-35s | %-20s | Rp%-8.0f | %-5d |\n",
                   daftarBuku[i].kode,
                   daftarBuku[i].judul,
                   daftarBuku[i].penulis,
                   daftarBuku[i].harga,
                   daftarBuku[i].stok);
            ada = 1;
        }
    }
    
    printf("================================================================================\n");
    
    if (!ada) {
        printf("Tidak ada buku dalam kategori ini.\n");
    }
}

/* Fungsi untuk cari buku berdasarkan kode */
int cariBuku(char kode[]) {
    int i;
    for (i = 0; i < jumlahBuku; i++) {
        if (strcmp(daftarBuku[i].kode, kode) == 0) {
            return i;
        }
    }
    return -1;
}

/* Fungsi untuk menu genre */
void menuGenre() {
    int pilihan;
    char genreFilter[20] = "";
    
    do {
        printf("\n=== PILIH GENRE ===\n");
        printf("1. Romance\n");
        printf("2. Horror\n");
        printf("3. Comedy\n");
        printf("4. Slice of Life\n");
        printf("5. Action\n");
        printf("6. Thriller\n");
        printf("0. Kembali/Cancel\n");
        printf("Pilih (0-6): ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1:
                strcpy(genreFilter, "Romance");
                tampilkanTabelBuku(genreFilter);
                return;
            case 2:
                strcpy(genreFilter, "Horror");
                tampilkanTabelBuku(genreFilter);
                return;
            case 3:
                strcpy(genreFilter, "Comedy");
                tampilkanTabelBuku(genreFilter);
                return;
            case 4:
                strcpy(genreFilter, "Slice of Life");
                tampilkanTabelBuku(genreFilter);
                return;
            case 5:
                strcpy(genreFilter, "Action");
                tampilkanTabelBuku(genreFilter);
                return;
            case 6:
                strcpy(genreFilter, "Thriller");
                tampilkanTabelBuku(genreFilter);
                return;
            case 0:
                return;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);
}

/* Fungsi untuk proses pembelian */
void prosesPembelian() {
    char kodeBuku[10];
    int jumlah, indexBuku;
    char lanjut;
    
    jumlahItem = 0;
    
    do {
        printf("\nMasukkan kode buku yang ingin kamu beli (atau tekan 0 untuk batal): ");
        scanf("%s", kodeBuku);
        
        if (strcmp(kodeBuku, "0") == 0) {
            printf("Pembelian dibatalkan.\n");
            return;
        }
        
        indexBuku = cariBuku(kodeBuku);
        
        if (indexBuku == -1) {
            printf("Kode buku tidak ditemukan!\n");
            continue;
        }
        
        printf("\nBuku yang dipilih: %s\n", daftarBuku[indexBuku].judul);
        printf("Harga: Rp %.0f\n", daftarBuku[indexBuku].harga);
        printf("Stok tersedia: %d\n", daftarBuku[indexBuku].stok);
        
        printf("\nMasukkan jumlah buku yang ingin kamu beli: ");
        scanf("%d", &jumlah);
        
        if (jumlah <= 0) {
            printf("Jumlah tidak valid!\n");
            continue;
        }
        
        if (jumlah > daftarBuku[indexBuku].stok) {
            printf("Maaf, stok tidak mencukupi! Stok tersedia: %d\n", daftarBuku[indexBuku].stok);
            continue;
        }
        
        strcpy(keranjang[jumlahItem].kode_buku, daftarBuku[indexBuku].kode);
        strcpy(keranjang[jumlahItem].judul, daftarBuku[indexBuku].judul);
        keranjang[jumlahItem].jumlah = jumlah;
        keranjang[jumlahItem].harga_satuan = daftarBuku[indexBuku].harga;
        keranjang[jumlahItem].subtotal = daftarBuku[indexBuku].harga * jumlah;
        jumlahItem++;
        
        printf("\nBuku berhasil ditambahkan ke keranjang!\n");
        
        printf("\nTambah buku lagi? (y/n): ");
        scanf(" %c", &lanjut);
        
    } while (lanjut == 'y' || lanjut == 'Y');
}

/* Fungsi untuk cetak struk */
void cetakStruk(char namaPembeli[], char noTransaksi[], float totalBayar, float uangDibayar, float kembalian) {
    int i;
    FILE *file;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    printf("\n");
    printf("================================================================================\n");
    printf("                          STRUK PEMBELIAN BUKU\n");
    printf("                            TOKO BUKU CERIA\n");
    printf("================================================================================\n");
    printf("No. Transaksi : %s\n", noTransaksi);
    printf("Tanggal       : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("Nama Pembeli  : %s\n", namaPembeli);
    printf("================================================================================\n");
    printf("| %-6s | %-35s | %-4s | %-10s | %-12s |\n", 
           "KODE", "JUDUL", "QTY", "HARGA", "SUBTOTAL");
    printf("================================================================================\n");
    
    for (i = 0; i < jumlahItem; i++) {
        printf("| %-6s | %-35s | %-4d | Rp%-8.0f | Rp%-10.0f |\n",
               keranjang[i].kode_buku,
               keranjang[i].judul,
               keranjang[i].jumlah,
               keranjang[i].harga_satuan,
               keranjang[i].subtotal);
    }
    
    printf("================================================================================\n");
    printf("Total Bayar   : Rp %.0f\n", totalBayar);
    printf("Uang Dibayar  : Rp %.0f\n", uangDibayar);
    printf("Kembalian     : Rp %.0f\n", kembalian);
    printf("================================================================================\n");
    printf("           Terima kasih sudah berbelanja di Toko Buku Ceria!\n");
    printf("         Semoga buku-buku ini membuat hari Anda lebih ceria! :)\n");
    printf("================================================================================\n");
    
    file = fopen("struk_pembelian.txt", "a");
    if (file != NULL) {
        fprintf(file, "\n");
        fprintf(file, "================================================================================\n");
        fprintf(file, "                          STRUK PEMBELIAN BUKU\n");
        fprintf(file, "                            TOKO BUKU CERIA\n");
        fprintf(file, "================================================================================\n");
        fprintf(file, "No. Transaksi : %s\n", noTransaksi);
        fprintf(file, "Tanggal       : %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        fprintf(file, "Nama Pembeli  : %s\n", namaPembeli);
        fprintf(file, "================================================================================\n");
        
        for (i = 0; i < jumlahItem; i++) {
            fprintf(file, "Kode: %s | Judul: %s | Qty: %d | Harga: Rp%.0f | Subtotal: Rp%.0f\n",
                    keranjang[i].kode_buku,
                    keranjang[i].judul,
                    keranjang[i].jumlah,
                    keranjang[i].harga_satuan,
                    keranjang[i].subtotal);
        }
        
        fprintf(file, "================================================================================\n");
        fprintf(file, "Total Bayar   : Rp %.0f\n", totalBayar);
        fprintf(file, "Uang Dibayar  : Rp %.0f\n", uangDibayar);
        fprintf(file, "Kembalian     : Rp %.0f\n", kembalian);
        fprintf(file, "================================================================================\n\n");
        
        fclose(file);
    }
}

/* Fungsi untuk update stok */
void updateStok() {
    int i, j, indexBuku;
    
    for (i = 0; i < jumlahItem; i++) {
        indexBuku = cariBuku(keranjang[i].kode_buku);
        if (indexBuku != -1) {
            daftarBuku[indexBuku].stok -= keranjang[i].jumlah;
        }
    }
}

/* Fungsi untuk generate nomor transaksi */
void generateNoTransaksi(char noTransaksi[]) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    sprintf(noTransaksi, "TRX-%02d%02d%02d-%03d", 
            tm.tm_mday, tm.tm_mon + 1, tm.tm_year % 100, nomorTransaksiHariIni);
    
    nomorTransaksiHariIni++;
}

/* Fungsi utama transaksi */
void transaksi() {
    char namaPembeli[100];
    char noTransaksi[20];
    float totalBayar = 0;
    float uangDibayar;
    float kembalian;
    int i;
    
    if (jumlahItem == 0) {
        printf("Keranjang kosong! Tidak ada yang dibeli.\n");
        return;
    }
    
    for (i = 0; i < jumlahItem; i++) {
        totalBayar += keranjang[i].subtotal;
    }
    
    printf("\n=== DATA PEMBELI ===\n");
    printf("Masukkan nama kamu: ");
    getchar();
    fgets(namaPembeli, sizeof(namaPembeli), stdin);
    namaPembeli[strcspn(namaPembeli, "\n")] = 0;
    
    while (strlen(namaPembeli) == 0) {
        printf("Nama tidak boleh kosong!\n");
        printf("Masukkan nama kamu: ");
        fgets(namaPembeli, sizeof(namaPembeli), stdin);
        namaPembeli[strcspn(namaPembeli, "\n")] = 0;
    }
    
    printf("\n=== PEMBAYARAN ===\n");
    printf("Total yang harus dibayar: Rp %.0f\n", totalBayar);
    
    do {
        printf("Masukkan uang kamu untuk membayar: Rp ");
        scanf("%f", &uangDibayar);
        
        if (uangDibayar < totalBayar) {
            printf("Uang tidak cukup! Kurang Rp %.0f\n", totalBayar - uangDibayar);
            printf("Silakan masukkan ulang.\n\n");
        }
    } while (uangDibayar < totalBayar);
    
    kembalian = uangDibayar - totalBayar;
    
    generateNoTransaksi(noTransaksi);
    
    updateStok();
    
    cetakStruk(namaPembeli, noTransaksi, totalBayar, uangDibayar, kembalian);
}

/* Main program */
int main() {
    int pilihanMenu, pilihanLanjut;
    
    initDataBuku();
    
    do {
        printf("\n");
        printf("================================================================================\n");
        printf("                     SELAMAT DATANG DI TOKO BUKU CERIA\n");
        printf("================================================================================\n");
        printf("\n=== MENU UTAMA ===\n");
        printf("1. Lihat Semua Daftar Buku\n");
        printf("2. Lihat Buku Berdasarkan Genre\n");
        printf("3. Keluar\n");
        printf("Pilih (1-3): ");
        scanf("%d", &pilihanMenu);
        
        switch (pilihanMenu) {
            case 1:
                tampilkanTabelBuku("");
                prosesPembelian();
                if (jumlahItem > 0) {
                    transaksi();
                }
                break;
                
            case 2:
                menuGenre();
                prosesPembelian();
                if (jumlahItem > 0) {
                    transaksi();
                }
                break;
                
            case 3:
                printf("\n================================================================================\n");
                printf("    Terima kasih sudah mengunjungi Toko Buku Ceria!\n");
                printf("    Semoga buku-buku kami membuat hari Anda lebih ceria! :)\n");
                printf("================================================================================\n");
                return 0;
                
            default:
                printf("Pilihan tidak valid!\n");
                continue;
        }
        
        if (pilihanMenu == 1 || pilihanMenu == 2) {
            printf("\n=== TRANSAKSI SELESAI ===\n");
            printf("Apakah ingin transaksi lagi?\n");
            printf("1. Ya (kembali ke menu awal)\n");
            printf("2. Tidak (keluar program)\n");
            printf("Pilih: ");
            scanf("%d", &pilihanLanjut);
            
            if (pilihanLanjut == 2) {
                printf("\n================================================================================\n");
                printf("    Terima kasih sudah berbelanja di Toko Buku Ceria!\n");
                printf("    Sampai jumpa lagi! :)\n");
                printf("================================================================================\n");
                return 0;
            }
        }
        
    } while (1);
    
    return 0;
}