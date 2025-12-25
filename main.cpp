#include <iostream>
#include <string>
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

    Song dummySongs[15] = {
    {1, "Saturn", "SZA", "RnB", 2023, "4:03"},
    {2, "Flowers", "Miley_Cyrus", "Pop", 2023, "3:20"},
    {3, "Hanya_Kau", "Lyodra", "Pop", 2023, "3:55"},
    {4, "Monokrom", "Tulus", "Pop", 2022, "3:42"},
    {5, "Supernova", "Niki", "Indie", 2024, "3:40"},
    {6, "Dynamite", "BTS", "KPop", 2022, "2:46"},
    {7, "Sial", "Mahalini", "Pop", 2023, "3:12"},
    {8, "AfterHours", "TheWeekend", "RnB", 2023, "4:10"},
    {9, "Bertaut", "Nadin_Amizah", "Indie", 2022, "4:01"},
    {10, "Rush", "Troye_Sivan", "Pop", 2023, "2:37"},
    {11, "Permission", "Weeekly", "KPop", 2024, "3:11"},
    {12, "Janji_Setia", "Tiara_Andini", "Pop", 2022, "3:54"},
    {13, "Shallows", "Keshi", "Indie", 2024, "3:29"},
    {14, "Domino", "Jessie_J", "Pop", 2023, "3:43"},
    {15, "Gemintang", "Hanindhiya", "Pop", 2023, "4:06"}
    };


    for (int i = 0; i < 15; i++) addSong(lib, dummySongs[i]);

    addressUser u1 = createUser("muti", "123");
    addressUser u2 = createUser("salwa", "345");
    addressUser u3 = createUser("diva", "567");

    addUser(users, u1);
    addUser(users, u2);
    addUser(users, u3);


    addPlaylistToUser(u1, "Chill_Mix");
    addPlaylistToUser(u1, "Pop_Indo");
    addPlaylistToUser(u1, "Workout");

    addPlaylistToUser(u2, "Drive_Night");
    addPlaylistToUser(u2, "Boost");
    addPlaylistToUser(u2, "Easy_Listening");

    addPlaylistToUser(u3, "Goodmood");
    addPlaylistToUser(u3, "Indo_Hits");
    addPlaylistToUser(u3, "Calm_Day");

    addSongToPlaylist(u1->firstPlaylist->info, findSongById(lib, 1));
    addSongToPlaylist(u1->firstPlaylist->info, findSongById(lib, 4));
    addSongToPlaylist(u1->firstPlaylist->info, findSongById(lib, 12));

    addSongToPlaylist(u1->firstPlaylist->next->info, findSongById(lib, 5));
    addSongToPlaylist(u1->firstPlaylist->next->info, findSongById(lib, 7));
    addSongToPlaylist(u1->firstPlaylist->next->info, findSongById(lib, 9));

    addSongToPlaylist(u1->firstPlaylist->next->next->info, findSongById(lib, 11));
    addSongToPlaylist(u1->firstPlaylist->next->next->info, findSongById(lib, 6));
    addSongToPlaylist(u1->firstPlaylist->next->next->info, findSongById(lib, 15));


    addSongToPlaylist(u2->firstPlaylist->info, findSongById(lib, 2));
    addSongToPlaylist(u2->firstPlaylist->info, findSongById(lib, 13));
    addSongToPlaylist(u2->firstPlaylist->info, findSongById(lib, 12));

    addSongToPlaylist(u2->firstPlaylist->next->info, findSongById(lib, 6));
    addSongToPlaylist(u2->firstPlaylist->next->info, findSongById(lib, 11));
    addSongToPlaylist(u2->firstPlaylist->next->info, findSongById(lib, 10));


    addSongToPlaylist(u2->firstPlaylist->next->next->info, findSongById(lib, 3));
    addSongToPlaylist(u2->firstPlaylist->next->next->info, findSongById(lib, 8));
    addSongToPlaylist(u2->firstPlaylist->next->next->info, findSongById(lib, 14));


    addSongToPlaylist(u3->firstPlaylist->info, findSongById(lib, 4));
    addSongToPlaylist(u3->firstPlaylist->info, findSongById(lib, 5));
    addSongToPlaylist(u3->firstPlaylist->info, findSongById(lib, 10));

    addSongToPlaylist(u3->firstPlaylist->next->info, findSongById(lib, 7));
    addSongToPlaylist(u3->firstPlaylist->next->info, findSongById(lib, 14));
    addSongToPlaylist(u3->firstPlaylist->next->info, findSongById(lib, 15));

    addSongToPlaylist(u3->firstPlaylist->next->next->info, findSongById(lib, 1));
    addSongToPlaylist(u3->firstPlaylist->next->next->info, findSongById(lib, 2));
    addSongToPlaylist(u3->firstPlaylist->next->next->info, findSongById(lib, 9));

    bool exitMain = false;
    while (!exitMain) {
        clrscr();

        cout << "=== Selamat datang di Listify.DS ===\n";
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";

        int pilih;
        cin >> pilih;

        if (pilih == 1) {
            string adminUser, adminPass;
            clrscr();
            cout << "=== LOGIN ADMIN ===\n";
            cout << "Username: "; cin >> adminUser;
            cout << "Password: "; cin >> adminPass;

            if (adminUser != "admin" || adminPass != "123") {
                cout << "Login admin gagal!\n";
                continue;
            }

            bool exitAdmin = false;
            while (!exitAdmin) {
                clrscr();
                cout << "\n=== MENU ADMIN ===\n";
                cout << "1. Tambah Lagu\n";
                cout << "2. Update Lagu\n";
                cout << "3. Hapus Lagu\n";
                cout << "4. Lihat Semua Lagu\n";
                cout << "0. Kembali\n";
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
                    konfirmKeluar();
                }
                else if (adminMenu == 2) {
                    int id;
                    cout << "ID lagu: "; cin >> id;
                    updateSong(lib, id);
                    konfirmKeluar();
                }
                else if (adminMenu == 3) {
                    int id;
                    cout << "ID lagu: "; cin >> id;
                    deleteSong(lib, id, users);
                    konfirmKeluar();
                }
                else if (adminMenu == 4) {
                    showAllSongs(lib);
                    konfirmKeluar();
                }
                else if (adminMenu == 0) {
                    exitAdmin = true;
                }
            }
        }
        else if (pilih == 2) {
            string uname, pw;
            clrscr();
            cout << "Masukkan username: "; cin >> uname;
            cout << "Masukkan password: "; cin >> pw;

            addressUser currentUser = findUser(users, uname);

            if (currentUser == nullptr) {
                cout << "User tidak ditemukan. Buat akun baru? (y/n): ";
                char yn; cin >> yn;
                if (yn == 'y' || yn == 'Y') {
                    currentUser = createUser(uname, pw);
                    addUser(users, currentUser);
                    cout << "Akun berhasil dibuat.\n";
                } else {
                    continue;
                }
            }
            else {
                if (!verifyUserPassword(currentUser, pw)) {
                    cout << "Password salah!\n";
                    continue;
                }
                cout << "Login berhasil.\n";
            }

            bool exitUser = false;
            while (!exitUser) {
                clrscr();
                cout << "\n=== MENU USER UTAMA ===\n";
                cout << "1. Library\n";
                cout << "2. Playlist\n";
                cout << "3. Antrian Lagu\n";
                cout << "4. Shuffle\n";
                cout << "5. Favorite Lagu\n";
                cout << "6. Top Played\n";
                cout << "0. Log Out\n";
                cout << "Pilih: ";

                int menuUser;
                cin >> menuUser;

                if (menuUser == 1) {
                    bool exitLib = false;
                    while (!exitLib) {
                        clrscr();
                        cout << "\n=== MENU LIBRARY ===\n";
                        cout << "1. Lihat Semua Lagu\n";
                        cout << "2. Cari Lagu\n";
                        cout << "3. Play Lagu\n";
                        cout << "4. Stop Lagu\n";
                        cout << "5. Next Lagu\n";
                        cout << "6. Prev Lagu\n";
                        cout << "0. Kembali\n";
                        cout << "Pilih: ";

                        int libChoice;
                        cin >> libChoice;

                        if (libChoice == 1) {
                            showAllSongs(lib);
                            konfirmKeluar();
                        }
                        else if (libChoice == 2) {
                            searchSong(lib);
                            konfirmKeluar();
                        }
                        else if (libChoice == 3) {
                            int id;
                            cout << "Masukkan ID lagu: "; cin >> id;
                            addressLibrary s = findSongById(lib, id);
                            if (s == nullptr) cout << "Lagu tidak ditemukan.\n";
                            else {
                                push(history, cp.songPtr);
                                playSong(cp, s, history);
                                konfirmKeluar();
                            }
                        }
                        else if (libChoice == 4) {
                                stopSong(cp);
                                konfirmKeluar();
                        }
                        else if (libChoice == 5) {
                                nextSong(lib, cp, history);
                                konfirmKeluar();
                        }
                        else if (libChoice == 6) {
                                prevSong(cp, history);
                                konfirmKeluar();
                        }
                        else if (libChoice == 0) {
                                exitLib = true;
                                konfirmKeluar();
                        }
                    }
                }
                else if (menuUser == 2) {
                    bool exitPlaylist = false;
                    while (!exitPlaylist) {
                        clrscr();
                        cout << "\n=== MENU PLAYLIST ===\n";
                        cout << "1. Show Semua Playlist\n";
                        cout << "2. Create Playlist\n";
                        cout << "3. Show Playlist\n";
                        cout << "4. Add Lagu ke Playlist\n";
                        cout << "5. Playlist Controls\n";
                        cout << "6. Rename Playlist\n";
                        cout << "7. Hapus Playlist\n";
                        cout << "8. Remove Lagu dari Playlist\n";
                        cout << "0. Kembali\n";
                        cout << "Pilih: ";

                        int pl;
                        cin >> pl;

                        if (pl == 1) {
                            addressPlaylistNode p = currentUser->firstPlaylist;
                            int idx = 1;
                            cout << "\n=== DAFTAR PLAYLIST ===\n";
                            if (p == nullptr) cout << "(Belum ada playlist)\n";
                            while (p != nullptr) {
                                cout << idx++ << ". " << p->info.nama << "\n";
                                p = p->next;
                            }
                            konfirmKeluar();
                        }
                        else if (pl == 2) {
                            string pname;
                            cout << "Nama playlist baru: ";
                            cin >> pname;
                            addPlaylistToUser(currentUser, pname);
                            konfirmKeluar();
                        }
                        else if (pl == 3) {
                            int num;
                            cout << "Pilih nomor playlist: ";
                            cin >> num;

                            addressPlaylistNode p = currentUser->firstPlaylist;
                            int i = 1;
                            while (p != nullptr && i < num) {
                                p = p->next; i++;
                            }

                            if (p == nullptr) cout << "Playlist tidak ditemukan.\n";
                            else showPlaylist(p->info);
                            konfirmKeluar();
                        }
                        else if (pl == 4) {
                            int num;
                            cout << "Nomor playlist: ";
                            cin >> num;

                            addressPlaylistNode p = currentUser->firstPlaylist;
                            int i = 1;
                            while (p != nullptr && i < num) {
                                p = p->next; i++;
                            }

                            if (p != nullptr) {
                                int id;
                                cout << "ID lagu: "; cin >> id;
                                addSongToPlaylist(p->info, findSongById(lib, id));
                            } else cout << "Playlist tidak ditemukan.\n";
                            konfirmKeluar();
                        }
                        else if (pl == 5) {
                            int num;
                            cout << "Nomor playlist: "; cin >> num;

                            addressPlaylistNode p = currentUser->firstPlaylist;
                            int i = 1;
                            while (p != nullptr && i < num) {
                                p = p->next; i++;
                            }

                            if (p != nullptr) {
                                bool exitCtrl = false;
                                while (!exitCtrl) {
                                    clrscr();
                                    cout << "\n--- Playlist Controls ---\n";
                                    cout << "1. Play\n";
                                    cout << "2. Stop\n";
                                    cout << "3. Next\n";
                                    cout << "4. Previous\n";
                                    cout << "0. Kembali\n";
                                    cout << "Pilih: ";

                                    int c;
                                    cin >> c;

                                    if (c == 1) {
                                        int id;
                                        cout << "ID lagu: "; cin >> id;
                                        push(history, cp.songPtr);
                                        playFromPlaylist(cp, p->info, id, history);
                                        konfirmKeluar();
                                    }
                                    else if (c == 2) {
                                        stopSong(cp);
                                        konfirmKeluar();
                                    }
                                    else if (c == 3){
                                        nextSong(lib, cp, history);
                                        konfirmKeluar();
                                    }
                                    else if (c == 4){
                                        prevSong(cp, history);
                                        konfirmKeluar();
                                    }
                                    else if (c == 0) {
                                        exitCtrl = true;
                                        konfirmKeluar();
                                    }
                                }
                            } else cout << "Playlist tidak ditemukan.\n";
                        }
                        else if (pl == 6) {
                            string oldName, newName;
                            cout << "Nama lama: "; cin >> oldName;
                            cout << "Nama baru: "; cin >> newName;
                            renamePlaylist(currentUser, oldName, newName);
                            konfirmKeluar();
                        }
                        else if (pl == 7) {
                            string del;
                            cout << "Nama playlist yang ingin dihapus: "; cin >> del;
                            deletePlaylist(currentUser, del);
                            konfirmKeluar();
                        }
                        else if (pl == 8) {
                            int num;
                            cout << "Nomor playlist: "; cin >> num;

                            addressPlaylistNode p = currentUser->firstPlaylist;
                            int i = 1;
                            while (p != nullptr && i < num) {
                                p = p->next; i++;
                            }

                            if (p != nullptr) {
                                int id;
                                cout << "ID lagu yang dihapus: "; cin >> id;
                                removeSongFromPlaylist(p->info, id);
                            } else cout << "Playlist tidak ditemukan.\n";
                            konfirmKeluar();
                        }
                        else if (pl == 0) exitPlaylist = true;
                    }
                }
                else if (menuUser == 3) {
                    bool exitQueue = false;
                    while (!exitQueue) {
                        clrscr();
                        cout << "\n=== MENU ANTRIAN LAGU ===\n";
                        cout << "1. Lihat Antrian\n";
                        cout << "2. Tambahkan Lagu ke Antrian\n";
                        cout << "3. Putar Lagu dari Antrian\n";
                        cout << "0. Kembali\n";
                        cout << "Pilih: ";

                        int q;
                        cin >> q;

                        if (q == 1) {
                            showQueue(Q);
                            konfirmKeluar();
                        }
                        else if (q == 2) {
                            int id;
                            cout << "ID lagu: "; cin >> id;
                            enqueue(Q, findSongById(lib, id));
                            konfirmKeluar();
                        }
                        else if (q == 3) {
                            if (!isQueueEmpty(Q)) {
                                addressLibrary s = dequeue(Q);
                                playSong(cp, s, history);
                            } else cout << "Queue kosong.\n";
                            konfirmKeluar();
                        }
                        else if (q == 0) {
                                exitQueue = true;
                        }
                    }
                }
                else if (menuUser == 4) {
                        shufflePlayLibrary(lib, cp, history);
                        konfirmKeluar();
                }
                else if (menuUser == 5) {
                    bool exitFav = false;
                    while (!exitFav) {
                        clrscr();
                        cout << "\n=== MENU FAVORITE ===\n";
                        cout << "1. Tandai Lagu Favorite\n";
                        cout << "2. Hapus Favorite\n";
                        cout << "3. Lihat Semua Favorite\n";
                        cout << "0. Kembali\n";
                        cout << "Pilih: ";

                        int f;
                        cin >> f;

                        if (f == 1) {
                            int id;
                            cout << "ID lagu: "; cin >> id;
                            markFavoriteById(lib, id);
                        }
                        else if (f == 2) {
                            int id;
                            cout << "ID lagu: "; cin >> id;
                            unmarkFavoriteById(lib, id);
                        }
                        else if (f == 3) {
                            showFavoriteSongs(lib);
                            konfirmKeluar();

                        }
                        else if (f == 0) {
                            exitFav = true;
                        }
                    }
                }
                else if (menuUser == 6) {
                        showMostPlayed(lib);
                        konfirmKeluar();
                }
                else if (menuUser == 0) {
                    cout << "Logout berhasil.\n";
                    exitUser = true;
                    konfirmKeluar();
                }
            }
        }

        else if (pilih == 0) exitMain = true;
    }

    return 0;
}



