#include <stdio.h>

// warna
const char *pink  = "\033[1;35m";
const char *putih = "\033[0m";
const char *hijau = "\033[1;32m";
const char *cyan  = "\033[1;36m";
const char *kuning= "\033[1;33m";

// variabel lain
int login;
int huruf;

void pembukaan_global(){
    printf("%s===============================================================%s\n", pink, putih);
    printf("            %s--%s Selamat Datang di Toko Buku Mini %s--%s\n", pink, putih, pink, putih);
    printf("%s===============================================================%s\n", pink, putih);
    printf("%s***************************************************************%s\n", hijau,putih);
    printf("                        %s----->%s  1. Karyawan\n",hijau, putih );
    printf("Masuk Sebagai\n");
    printf("                        %s----->%s  2. Pembeli\n",hijau, putih );
    printf("%s***************************************************************%s\n", hijau,putih);
    printf("Pilih : ");
    
 
}

void pembukaan_pembeli() {
    printf("%s-------------------------------%s--------------------------------\n%s",pink,hijau,putih);
    printf("       %s-%s-%sSelamat Datang Pembeli Toko BUku Mini >_< %s-%s-%s\n",pink,hijau,putih,pink,hijau,putih);
    printf("%s-------------------------------%s--------------------------------\n%s",hijau,pink,putih);
    printf("Disini kamu bisa membeli, meminjam, dan mengembalikan buku >_<!\n");
    printf("%s-------------------------------------------------------------\n%s",pink,putih);
    printf("*************************  - 1. Membeli Buku\n");
    printf("----------------> CHOOSE   - 2. Meminjam Buku\n");
    printf("*************************  - 3. Mengembalikan Buku\n");
    printf("%s-------------------------------------------------------------\n%s",pink,putih);
}


void pembukaan_karyawan() {
    printf("%s-------------------------------%s--------------------------------\n%s",cyan,pink,putih);
    printf("       %s-%s-%sSelamat Datang Karyawan Toko BUku Mini >_< %s-%s-%s\n",pink,cyan,putih,pink,cyan,putih);
    printf("%s-------------------------------%s--------------------------------\n%s",pink,cyan,putih);
    printf("         Karyawan saat ini tersisa bang Marco saja!\n");
    printf("%s-------------------------------%s--------------------------------\n%s",cyan,pink,putih);
}


void login_password();       
void kontrol_pembeli(); 
void kontrol_karyawan();

void pilihan() {
     huruf = scanf("%d", &login);

     while (huruf != 1 || login < 1 || login > 2)
     {
        printf("Pilihan tidak valid! Silahkan input ulang : ");
        while (getchar() != '\n');
        huruf = scanf("%d", &login);
     }
    
        switch (login) {
        case 1:
          pembukaan_karyawan();
          login_password();
          kontrol_karyawan();
          break;
        case 2:
          pembukaan_pembeli();
          kontrol_pembeli();
          break;
      }
     
}

