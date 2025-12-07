#include <iostream>
#include "ListifyDS.h"
using namespace std;

int main() {
    Library lib;
    createLibrary(lib);

    addressUser users = nullptr;
    CurrentPlay cp;
    cp.songPtr = nullptr;
    cp.isPlaying = false;
    cp.fromPlaylist = false;
    cp.currentPlaylistNode = nullptr;

    Stack history;
    createStack(history);

    Queue Q;
    createQueue(Q);

    cout << "=== Selamat datang di Listify.DS ===\n";

    bool exitMain = false;

    while (!exitMain) {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";

        int pilih;
        cin >> pilih;

        /* =========================
           ========== ADMIN ========
           ========================= */
        if (pilih == 1) {

            bool exitAdmin = false;

            while (!exitAdmin) {
                cout << "\n=== MENU ADMIN ===\n";
                cout << "1. Tambah Lagu\n";
                cout << "2. Update Lagu\n";
                cout << "3. Hapus Lagu\n";
                cout << "4. Lihat Semua Lagu\n";
                cout << "0. Kembali ke Menu Utama\n";
                cout << "Pilih: ";

                int adminMenu;
                cin >> adminMenu;

                if (adminMenu == 1) {
                    Song s;

                    cout << "Masukkan ID: "; cin >> s.id;
                    cout << "Masukkan Judul: "; cin >> s.judul;
                    cout << "Masukkan Artis: "; cin >> s.artis;
                    cout << "Masukkan Genre: "; cin >> s.genre;
                    cout << "Masukkan Tahun: "; cin >> s.tahun;
                    cout << "Masukkan Durasi: "; cin >> s.durasi;

                    addSong(lib, s);
                }
                else if (adminMenu == 2) {
                    int id;
                    cout << "Masukkan ID lagu yang ingin diupdate: "; cin >> id;

                    Song newData;
                    cout << "Masukkan Judul baru: "; cin >> newData.judul;
                    cout << "Masukkan Artis baru: "; cin >> newData.artis;
                    cout << "Masukkan Genre baru: "; cin >> newData.genre;
                    cout << "Masukkan Tahun baru: "; cin >> newData.tahun;
                    cout << "Masukkan Durasi baru: "; cin >> newData.durasi;

                    updateSong(lib, id, newData);
                }
                else if (adminMenu == 3) {
                    int id;
                    cout << "Masukkan ID lagu yang ingin dihapus: ";
                    cin >> id;

                    deleteSong(lib, id, users);
                }
                else if (adminMenu == 4) {
                    showAllSongs(lib);
                }
                else if (adminMenu == 0) {
                    cout << "Kembali ke Menu Utama.\n";
                    exitAdmin = true;
                }
                else {
                    cout << "Pilihan tidak valid.\n";
                }
            }
        }

        /* =========================
           ========== USER =========
           ========================= */
        else if (pilih == 2) {

            cout << "Masukkan username: ";
            string uname;
            cin >> uname;

            addressUser currentUser = users;

            while (currentUser != nullptr && currentUser->username != uname) {
                currentUser = currentUser->next;
            }

            if (currentUser == nullptr) {
                cout << "User tidak ditemukan. Buat akun baru? (y/n): ";
                char yn;
                cin >> yn;

                if (yn == 'y' || yn == 'Y') {
                    currentUser = createUser(uname);
                    addUser(users, currentUser);
                    cout << "Akun berhasil dibuat.\n";
                } else {
                    continue;
                }
            }

            bool exitUser = false;

            while (!exitUser) {
                cout << "\n=== MENU USER ===\n";
                cout << "1.  Show Semua Lagu\n";
                cout << "2.  Search Lagu\n";
                cout << "3.  Create Playlist\n";
                cout << "4.  Show Playlist\n";
                cout << "5.  Add Lagu ke Playlist\n";
                cout << "6.  Playlist Controls\n";
                cout << "7.  Lihat History (STACK)\n";
                cout << "8.  Lihat Antrian Lagu (QUEUE)\n";
                cout << "9.  Tambahkan Lagu ke Antrian\n";
                cout << "10. Putar Lagu dari Antrian\n";
                cout << "0.  Logout\n";
                cout << "Pilih: ";

                int menuUser;
                cin >> menuUser;

                if (menuUser == 1) {
                    showAllSongs(lib);
                }
                else if (menuUser == 2) {
                    searchSong(lib);
                }
                else if (menuUser == 3) {
                    cout << "Masukkan nama playlist baru: ";
                    string pname;
                    cin >> pname;
                    addPlaylistToUser(currentUser, pname);
                }
                else if (menuUser == 4) {
                    if (currentUser->firstPlaylist == nullptr) {
                        cout << "Belum ada playlist.\n";
                    }
                    else {
                        addressPlaylistNode p = currentUser->firstPlaylist;
                        int idx = 1;

                        cout << "\n=== DAFTAR PLAYLIST " << currentUser->username << " ===\n";
                        while (p != nullptr) {
                            cout << idx << ". " << p->info.nama << "\n";
                            p = p->next;
                            idx++;
                        }

                        cout << "Pilih playlist: ";
                        int pilihPL;
                        cin >> pilihPL;

                        p = currentUser->firstPlaylist;
                        idx = 1;

                        while (p != nullptr && idx < pilihPL) {
                            p = p->next;
                            idx++;
                        }

                        if (p == nullptr) {
                            cout << "Playlist tidak ditemukan.\n";
                        }
                        else {
                            showPlaylist(p->info);
                        }
                    }
                }
                else if (menuUser == 5) {
                    if (currentUser->firstPlaylist == nullptr) {
                        cout << "Belum ada playlist.\n";
                    } else {
                        cout << "Masukkan nomor playlist: ";
                        int plNum; cin >> plNum;

                        addressPlaylistNode p = currentUser->firstPlaylist;
                        int idx = 1;

                        while (p != nullptr && idx < plNum) {
                            p = p->next;
                            idx++;
                        }

                        if (p != nullptr) {
                            cout << "Masukkan ID lagu yang ingin ditambahkan: ";
                            int id; cin >> id;
                            addressLibrary s = findSongById(lib, id);

                            addSongToPlaylist(p->info, s);
                        } else {
                            cout << "Playlist tidak ditemukan.\n";
                        }
                    }
                }
                else if (menuUser == 6) {
                    if (currentUser->firstPlaylist == nullptr) {
                        cout << "Belum ada playlist.\n";
                    } else {
                        cout << "\n=== Playlist Controls ===\n";
                        cout << "1. Play Lagu\n";
                        cout << "2. Stop\n";
                        cout << "3. Next\n";
                        cout << "4. Previous\n";
                        cout << "0. Kembali\n";
                        cout << "Pilih: ";

                        int ctrl;
                        cin >> ctrl;

                        if (ctrl == 1) {
                            cout << "Masukkan nomor playlist: ";
                            int plNum; cin >> plNum;

                            addressPlaylistNode p = currentUser->firstPlaylist;
                            int idx = 1;

                            while (p != nullptr && idx < plNum) {
                                p = p->next;
                                idx++;
                            }

                            if (p != nullptr) {
                                cout << "Masukkan ID lagu: ";
                                int id; cin >> id;
                                playFromPlaylist(cp, p->info, id);
                                push(history, cp.songPtr);
                            } else cout << "Playlist tidak ditemukan.\n";
                        }
                        else if (ctrl == 2) stopSong(cp);
                        else if (ctrl == 3) nextSong(lib, cp);
                        else if (ctrl == 4) prevSong(cp, history);
                    }
                }
                else if (menuUser == 7) {
                    showStack(history);
                }
                else if (menuUser == 8) {
                    showQueue(Q);
                }
                else if (menuUser == 9) {
                    cout << "Masukkan ID lagu: ";
                    int id; cin >> id;
                    addressLibrary s = findSongById(lib, id);
                    enqueue(Q, s);
                }
                else if (menuUser == 10) {
                    if (!isQueueEmpty(Q)) {
                        addressLibrary s = dequeue(Q);
                        playSong(cp, s);
                        push(history, s);
                    } else cout << "Antrian kosong.\n";
                }
                else if (menuUser == 0) {
                    cout << "Logout berhasil.\n";
                    exitUser = true;
                }
                else {
                    cout << "Pilihan tidak valid.\n";
                }
            }
        }

        /* =========================
           ======== EXIT ===========
           ========================= */
        else if (pilih == 0) {
            cout << "Terima kasih telah menggunakan Listify.DS\n";
            exitMain = true;
        }

        else {
            cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}
