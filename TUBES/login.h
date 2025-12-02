#include <stdio.h>
#include "warna.h"

#ifndef LOGIN_H
#define LOGIN_H

char Username[10];
char Password[10];

// user & password yg benar
char user_benar[] = "marco";
char pass_benar[] = "marco12345";

int cek_password(char *a, char *b) {
    int i = 0;

    while (a[i] == b[i]) {
        if (a[i] == '\0')
            return 1;
        i++;
    } return 0;
}

void login_password() {
    int berhasil = 0;

    do
    {
        printf("\n                      %s+++%s Silahkan Login %s+++%s\n", pink,putih,cyan,putih);
        printf("%s===%s>%s Username %s:%s ", kuning,cyan,putih,pink,putih);
        scanf("%s", &Username);
        printf("%s===%s>%s Password %s:%s ", kuning,cyan,putih,pink,putih);
        scanf("%s", &Password);

    if (cek_password(Username, user_benar) && cek_password(Password, pass_benar)) {
        berhasil = 1;
    } else {
      
        printf("%sUsername%s atau %sPassword%s %ssalah%s!\n",pink, putih, cyan, putih, kuning, putih);
      
    } 

    } while (!berhasil);

        printf("%s++++++++++++++++%s> %sSELAMAT! %sKAMU BERHASIL LOGIN%s\n", kuning, cyan, pink, hijau, putih);
        printf("%s-------------------------------%s--------------------------------\n%s",cyan,pink,putih);
        printf("*************************  - 1. Laporan Penjualan\n");
        printf("----------------> CHOOSE   - 2. Laporan Peminjaman\n");
        printf("*************************  - 3. Laporan Gabungan\n");
        printf("%s-------------------------------%s--------------------------------\n%s",cyan,pink,putih);

}
#endif