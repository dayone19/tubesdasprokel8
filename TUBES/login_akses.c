#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char username [20];
    char password [20];
} user;

user daftar_user[] = {
    {"karyawan", "12345"},
    {"bukuku", "bel123"}
};
int total_user = sizeof(daftar_user) / sizeof(daftar_user[0]);

void menu_karyawan_penuh() {
    printf ("\n=== MENU AKSES PENUH ===\n");
    printf ("1. Beli Buku\n");
    printf ("2. Pinjam Buku\n");
    printf ("3. Kembalikan Buku\n");
    printf ("4. Laporan Karyawan\n");
    printf ("5. Logout\n");
    printf ("---------------------------\n");

    int choice;
    printf ("Silahkan pilih opsi (angka):");
    scanf ("%d", &choice);

    if (choice == 5) {
        printf ("Logging out...\n");
    } else {

    }
}

int verify_login (char *user, char *pass) {
    int i;
    int is_matched =0;

    for (i = 0; i < total_user; i++) {
        if (strcmp (user, daftar_user[i].username) == 0 &&
            strcmp (pass, daftar_user[i].password) == 0)
            {
                printf ("\nLogin Berhasil!, %s.\n", daftar_user[i].username);
                menu_karyawan_penuh();
                is_matched = 1;
                break;
            }
        }
        if (is_matched == 0) {
            printf ("\nLogin Gagal! username atau password salah.\n");
        }
        
        return is_matched;
    }

    void login_screen() {
        char input_user[20];
        char input_pass[20];
        int is_logged_in;

        do {
            system ("cls");
            printf("=== HALAMAN LOGIN TOKO BUKU MINI ===\n");
            printf("[Masukkan 'exit' untuk keluar.]\n");

            printf ("Username: ");
            scanf ("%s", input_user);

            if (strcmp (input_user, "exit") == 0) {
                printf ("Terima kasih \n");
                exit(0);
            }

            printf ("Password: ");
            scanf ("%s", input_pass);

            is_logged_in = verify_login (input_user, input_pass);
        } while (is_logged_in == 0);

    }

    int main() {
        login_screen();
        return 0;
    }


    