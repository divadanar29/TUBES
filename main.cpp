#include <iostream>
#include <string>
#include "ListifyDS.h"
using namespace std;

int main() {
    Library L;
    createLibrary(L);
    addressUser users = nullptr;
    CurrentPlay cp = {nullptr, false, false, nullptr};
    Stack history;
    initStack(history);

    cout << "=== SELAMAT DATANG DI LISTIFYDS ===" << endl;

    int pilihanMain = -1;

    while (pilihanMain != 0) {
        cout << endl;
        cout << "===== MENU UTAMA =====" << endl;
        cout << "1. Menu Admin" << endl;
        cout << "2. Menu User" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihanMain;

        if (pilihanMain == 1) {
            int pilihanAdmin = -1;
            while (pilihanAdmin != 0) {
                cout << endl;
                cout << "=== MENU ADMIN ===" << endl;
                cout << "1. Tambah Lagu" << endl;
                cout << "2. Lihat Semua Lagu" << endl;
                cout << "3. Update Lagu" << endl;
                cout << "4. Hapus Lagu" << endl;
                cout << "0. Kembali" << endl;
                cout << "Pilihan: "; cin >> pilihanAdmin;

                if (pilihanAdmin == 1) {
                    Song s;
                    cout << "Masukkan ID Lagu: "; cin >> s.id;
                    cout << "Masukkan Judul: "; cin >> s.judul;
                    cout << "Masukkan Artis: "; cin >> s.artis;
                    cout << "Masukkan Genre: "; cin >> s.genre;
                    cout << "Masukkan Tahun: "; cin >> s.tahun;
                    addSong(L, s);
                }
                else if (pilihanAdmin == 2) showAllSongs(L);
                else if (pilihanAdmin == 3) {
                    int id;
                    cout << "ID Lagu yang ingin diupdate: "; cin >> id;
                    Song s;
                    cout << "Judul Baru: "; cin >> s.judul;
                    cout << "Artis Baru: "; cin >> s.artis;
                    cout << "Genre Baru: "; cin >> s.genre;
                    cout << "Tahun Baru: "; cin >> s.tahun;
                    updateSong(L, id, s);
                }
                else if (pilihanAdmin == 4) {
                    int id;
                    cout << "ID Lagu yang ingin dihapus: "; cin >> id;
                    deleteSong(L, id, users);
                }
                else if (pilihanAdmin == 0) cout << "Kembali ke Menu Utama" << endl;
                else cout << "Pilihan tidak valid" << endl;
            }
        }
        else if (pilihanMain == 2) {
            cout << endl;
            cout << "Username (ketik 'buat' untuk user baru): ";
            string uname; cin >> uname;
            addressUser me = nullptr;

            if (uname == "buat") {
                cout << "Nama user baru: "; string newname; cin >> newname;
                me = createUser(newname);
                addUser(users, me);
                cout << "User '" << newname << "' berhasil dibuat." << endl;
            } else {
                me = users;
                while (me && me->username != uname) me = me->next;
                if (!me) {
                    cout << "User tidak ditemukan" << endl;
                    continue;
                }
                cout << "Selamat datang, " << me->username << "!" << endl;
            }

            int pilihanUser = -1;
            while (pilihanUser != 0) {
                cout << endl;
                cout << "=== MENU USER (" << me->username << ") ===" << endl;
                cout << "1. Cari Lagu" << endl;
                cout << "2. Putar Lagu dari Library" << endl;
                cout << "3. Stop Lagu" << endl;
                cout << "4. Next Lagu" << endl;
                cout << "5. Prev Lagu" << endl;
                cout << "6. Playlist" << endl;
                cout << "7. Lihat Semua Lagu" << endl;
                cout << "0. Logout" << endl;
                cout << "Pilihan: "; cin >> pilihanUser;

                if (pilihanUser == 1) searchSong(L);
                else if (pilihanUser == 2) {
                    int id; cout << "ID Lagu: "; cin >> id;
                    addressLibrary s = findSongById(L, id);
                    if (!s) cout << "Lagu tidak ditemukan" << endl;
                    else {
                        if (cp.isPlaying && cp.songPtr) push(history, cp.songPtr);
                        playSong(cp, s);
                    }
                }
                else if (pilihanUser == 3) stopSong(cp);
                else if (pilihanUser == 4) nextSong(L, cp);
                else if (pilihanUser == 5) prevSong(cp, history);
                else if (pilihanUser == 6) {
                    int menuPl = -1;
                    while(menuPl != 0) {
                        cout << endl;
                        cout << "=== MENU PLAYLIST ===" << endl;
                        cout << "1. Buat Playlist" << endl;
                        cout << "2. Tambah Lagu ke Playlist" << endl;
                        cout << "3. Hapus Lagu dari Playlist" << endl;
                        cout << "4. Lihat Playlist" << endl;
                        cout << "0. Kembali" << endl;
                        cout << "Pilihan: "; cin >> menuPl;

                        if(menuPl == 1) {
                            string nama; cout << "Nama Playlist: "; cin >> nama;
                            addPlaylistToUser(me, nama);
                        }
                        else if(menuPl == 2) {
                            if(!me->firstPlaylist) {cout<<"Belum ada playlist"<< endl; continue;}
                            string plnama; cout << "Nama Playlist: "; cin >> plnama;
                            addressPlaylistNode pl = me->firstPlaylist;
                            while(pl && pl->info.nama != plnama) pl = pl->next;
                            if(!pl) {cout<<"Playlist tidak ditemukan"<< endl; continue;}
                            int id; cout << "ID Lagu: "; cin >> id;
                            addressLibrary s = findSongById(L, id);
                            if(!s) {cout<<"Lagu tidak ditemukan"<< endl; continue;}
                            addSongToPlaylist(pl->info, s);
                        }
                        else if(menuPl == 3) {
                            if(!me->firstPlaylist) {cout<<"Belum ada playlist"<< endl; continue;}
                            string plnama; cout << "Nama Playlist: "; cin >> plnama;
                            addressPlaylistNode pl = me->firstPlaylist;
                            while(pl && pl->info.nama != plnama) pl = pl->next;
                            if(!pl) {cout<<"Playlist tidak ditemukan"<< endl; continue;}
                            int id; cout << "ID Lagu yang ingin dihapus: "; cin >> id;
                            removeSongFromPlaylist(pl->info, id);
                            cout<<"Lagu dihapus"<< endl;
                        }
                        else if(menuPl == 4) {
                            if(!me->firstPlaylist) {cout<<"Belum ada playlist"<< endl; continue;}
                            addressPlaylistNode pl = me->firstPlaylist;
                            while(pl) {showPlaylist(pl->info); pl = pl->next;}
                        }
                        else if(menuPl == 0) cout<<"Kembali ke Menu User"<< endl;
                        else cout<<"Pilihan tidak valid"<< endl;
                    }
                }
                else if (pilihanUser == 7) showAllSongs(L);
                else if (pilihanUser == 0) cout << "Logout " << me->username << endl;
                else cout << "Pilihan tidak valid" << endl;
            }
        }
        else if (pilihanMain == 0) cout << "Terima kasih telah menggunakan ListifyDS!" << endl;
        else cout << "Pilihan tidak valid" << endl;
    }

    return 0;
}
