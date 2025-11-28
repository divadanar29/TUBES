#include <iostream>
#include "tubes.h"

using namespace std;

void tampilMenuUtama() {
    cout << "=====================================\n";
    cout << "        APLIKASI PEMUTAR MUSIK       \n";
    cout << "=====================================\n";
    cout << "1. Login sebagai Admin\n";
    cout << "2. Login sebagai User\n";
    cout << "3. Keluar\n";
    cout << "-------------------------------------\n";
    cout << "Pilih Menu: ";
}

void tampilMenuAdmin() {
    cout << "\n=====================================\n";
    cout << "              MENU ADMIN             \n";
    cout << "=====================================\n";
    cout << "1. Tambah Lagu ke Library\n";
    cout << "2. Lihat Semua Lagu\n";
    cout << "3. Ubah Data Lagu\n";
    cout << "4. Hapus Lagu\n";
    cout << "5. Kembali ke Menu Utama\n";
    cout << "-------------------------------------\n";
    cout << "Pilih Menu: ";
}

void tampilMenuUser() {
    cout << "\n=====================================\n";
    cout << "              MENU USER              \n";
    cout << "=====================================\n";
    cout << "1. Cari Lagu\n";
    cout << "2. Putar Lagu dari Library\n";
    cout << "3. Lihat Playlist\n";
    cout << "4. Tambah Playlist\n";
    cout << "5. Tambah Lagu ke Playlist\n";
    cout << "6. Hapus Lagu dari Playlist\n";
    cout << "7. Play Next Lagu\n";
    cout << "8. Play Previous Lagu\n";
    cout << "9. Kembali ke Menu Utama\n";
    cout << "-------------------------------------\n";
    cout << "Pilih Menu: ";
}

void tampilMenuPemutaran() {
    cout << "\n=====================================\n";
    cout << "          MENU PEMUTARAN LAGU        \n";
    cout << "=====================================\n";
    cout << "1. Play Lagu\n";
    cout << "2. Stop Lagu\n";
    cout << "3. Next Lagu\n";
    cout << "4. Previous Lagu\n";
    cout << "5. Lihat Antrian Lagu (Queue)\n";
    cout << "6. Lihat Riwayat Lagu (Stack)\n";
    cout << "7. Kembali ke Menu User\n";
    cout << "-------------------------------------\n";
    cout << "Pilih Menu: ";
}

int main(){
    int pilihUtama = 0;   // nilai awal supaya while bisa berjalan

    while (pilihUtama != 3) {
        tampilMenuUtama();
        cin >> pilihUtama;

        if (pilihUtama == 1) {
            int pilihAdmin = 0;

            while (pilihAdmin != 5) {
                tampilMenuAdmin();
                cin >> pilihAdmin;

                // proses menu admin...
            }
        }

        else if (pilihUtama == 2) {
            int pilihUser = 0;

            while (pilihUser != 9) {
                tampilMenuUser();
                cin >> pilihUser;

                // proses menu user...
            }
        }
    }

    cout << "Terima kasih telah menggunakan aplikasi.\n";
    return 0;
}
