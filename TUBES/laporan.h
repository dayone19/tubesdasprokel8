#include <stdio.h>
#include "beli.h"




void laporan_penjualan() {
     printf("\n%s=================== LAPORAN PENJUALAN ===================%s\n", hijau, putih);
     printf("| %-20s | %-6s | %-10s | %-6s | %-10s |\n", 
           "Nama Pembeli", "Kode", "Harga", "Jumlah", "Total");
     printf("--------------------------------------------------------------\n");

     printf("| %-20s | %-6s | %-10d | %-6d | %-10d |\n", 
           nama_pembeli, kode, harga, jumlah, total);

     printf("==============================================================\n");
}


void buku_paling_diminati() {

}

void catatan_pendapatan() {


}

