#include <stdio.h>
#include <string.h>

// =========================================================
//           DEFINISI STRUKTUR DATA
// =========================================================

typedef struct {
    char kode[10];      // Kode buku (R1, SOL1, dll)
    char judul[50];     // Judul buku
    char penulis[30];   // Nama penulis
    int harga;          // Harga per buku
    int stok;           // Jumlah stok
} Buku;

// =========================================================
//                   DATA BUKU (INVENTARIS)
// =========================================================

// Kita isi data sesuai request (Romance, Horror, Comedy, Slice of Life, Action, Thriller)
Buku daftarBuku[] = {
    // ROMANCE (R1 - R5)
    {"R1", "Milea: Suara Dari Dilan", "Pidi Baiq", 70000, 10},
    {"R2", "Mariposa", "Luluk HF", 110000, 10},
    {"R3", "00.00", "Ameylia Falensia", 90000, 15},
    {"R4", "Ayat-Ayat Cinta", "Habiburrahman El Shirazy", 72000, 5},
    {"R5", "Septihan", "Popi Pertiwi", 99000, 2},

    // HORROR (H1 - H3)
    {"H1", "Kuchisake-Apakah Aku Cantik?", "Hastong N.H.", 60000, 7},
    {"H2", "Danur", "Risa Saraswati", 80000, 20},
    {"H3", "KKN Desa Penari", "Simplemen", 77000, 9},

    // COMEDY (C1 - C3)
    {"C1", "My Stupid Boss", "chaos@work", 85000, 2},
    {"C2", "Sabtu Bersama Bapak", "Adhitya Mulya", 120000, 15},
    {"C3", "Skripsip", "chara perdana", 45000, 5},

    // SLICE OF LIFE (SOL1 - SOL3)
    {"SOL1", "Keajaiban Toko Kelontong Namia", "Keigo Higashino", 130000, 8},
    {"SOL2", "Keluarga Cemara", "Arswendo Atmowiloto", 85000, 5},
    {"SOL3", "Laskar pelangi", "Andrea Hirata", 100000, 2},

    // ACTION (A1 - A2)
    {"A1", "Tanah Para Bandit", "Tere Liye", 95000, 11},
    {"A2", "Negeri Para Bedebah", "Tere Liye", 100000, 15},

    // THRILLER (T1 - T3)
    {"T1", "Holy Mother", "Akiyoshi Rikako", 85000, 8},
    {"T2", "Pasien", "Naomi Midori", 75000, 6},
    {"T3", "IT", "Stephen King", 110000, 7}
};

// Menghitung total buku secara otomatis
const int JUMLAH_BUKU = sizeof(daftarBuku) / sizeof(daftarBuku[0]);


// =========================================================
//               DEKLARASI FUNGSI (PROTOTYPE)
// =========================================================
void tampilkanBuku(Buku buku[], int n);


// =========================================================
//                     FUNGSI UTAMA
// =========================================================
int main() {
    // Ini hanya untuk mengetes fitur 1.1
    printf("\n--- TEST FITUR 1.1: TAMPILKAN DAFTAR BUKU ---\n\n");
    
    tampilkanBuku(daftarBuku, JUMLAH_BUKU);

    return 0;
}


// =========================================================
//            IMPLEMENTASI FUNGSI (LOGIKA PROGRAM)
// =========================================================

// 1.1 Tampilkan Daftar Buku (Final Version)
void tampilkanBuku(Buku buku[], int n) {
    // Header Tabel
    printf("====================================================================================================\n");
    printf("| %-6s | %-32s | %-25s | %-10s | %-4s |\n", 
           "KODE", "JUDUL BUKU", "PENULIS", "HARGA (Rp)", "STOK");
    printf("====================================================================================================\n");
    
    // Loop untuk mencetak setiap baris data
    for (int i = 0; i < n; i++) {
        printf("| %-6s | %-32s | %-25s | %-10d | %-4d |\n", 
               buku[i].kode, 
               buku[i].judul, 
               buku[i].penulis, 
               buku[i].harga, 
               buku[i].stok);
    }
    
    // Footer Tabel
    printf("====================================================================================================\n");
}