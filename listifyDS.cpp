#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "ListifyDS.h"

using namespace std;

void clrscr() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void konfirmKeluar(){
    cout << "Tekan apapun untuk kembali" << endl;
    string test1;
    cin >> test1;
}

void createLibrary(Library &L) {
    L.head = nullptr;
    L.tail = nullptr;
}

addressLibrary allocateLibrary(Song s) {
    addressLibrary p = new NodeLibrary;
    p->info = s;
    p->info.favorite = false;
    p->info.playCount = 0;
    p->next = nullptr;
    p->prev = nullptr;

    return p;
}

void addSong(Library &L, Song s) {
    addressLibrary cek = L.head;
    bool found = false;

    while (cek != nullptr) {
        if (cek->info.id == s.id) {
            found = true;
        }
        cek = cek->next;
    }

    if (found == true) {
        cout << "GAGAL: ID " << s.id << " sudah digunakan.\n";
    } else {
        addressLibrary p = allocateLibrary(s);

        if (L.head == nullptr) {
            L.head = p;
            L.tail = p;
        } else {
            L.tail->next = p;
            p->prev = L.tail;
            L.tail = p;
        }

        cout << "Lagu '" << s.judul << "' berhasil ditambahkan.\n";
    }
}

void showAllSongs(Library L) {
    if (L.head == nullptr) {
        cout << "Library kosong.\n";
        return;
    }

    cout << "\n=== DAFTAR LAGU ===\n";
    addressLibrary p = L.head;
    int idx = 1;

    while (p != nullptr) {
        string combined = p->info.judul +" - "+ p->info.artis;
        cout << " ID: "
             << setw(5) << left << p->info.id     << " | "
             << setw(30) << left <<   combined << " | "
             << setw(15) << left << p->info.genre  << " | "
             << setw(5) << left << p->info.tahun  << " | "
             << setw(5) << left << p->info.durasi << " |\n";
            p = p->next;
        idx = idx + 1;
    }
    cout << "====================\n";
}

addressLibrary findSongById(Library L, int id) {
    addressLibrary p = L.head;
    addressLibrary result = nullptr;

    while (p != nullptr) {
        if (p->info.id == id) {
            result = p;
        }
        p = p->next;
    }

    return result;
}

void updateSong(Library &L, int id) {
    addressLibrary p = findSongById(L, id);

    if (p == nullptr) {
        cout << "Lagu tidak ditemukan.\n";
    } else {
        cout << "\n=== DATA LAGU SAAT INI ===\n";
        cout << "ID     : " << p->info.id << endl;
        cout << "Judul  : " << p->info.judul << endl;
        cout << "Artis  : " << p->info.artis << endl;
        cout << "Genre  : " << p->info.genre << endl;
        cout << "Tahun  : " << p->info.tahun << endl;
        cout << "Durasi : " << p->info.durasi << endl;

        int pilihan;

        cout << "\n=== EDIT LAGU ===\n";
        cout << "1. Edit Judul\n";
        cout << "2. Edit Artis\n";
        cout << "3. Edit Genre\n";
        cout << "4. Edit Tahun\n";
        cout << "5. Edit Durasi\n";
        cout << "Pilih (1-5): ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan judul baru: ";
            cin >> p->info.judul;
            cout << "Judul berhasil diubah.\n";

        } else if (pilihan == 2) {
            cout << "Masukkan artis baru: ";
            cin >> p->info.artis;
            cout << "Artis berhasil diubah.\n";

        } else if (pilihan == 3) {
            cout << "Masukkan genre baru: ";
            cin >> p->info.genre;
            cout << "Genre berhasil diubah.\n";

        } else if (pilihan == 4) {
            cout << "Masukkan tahun baru: ";
            cin >> p->info.tahun;
            cout << "Tahun berhasil diubah.\n";

        } else if (pilihan == 5) {
            cout << "Masukkan durasi baru: ";
            cin >> p->info.durasi;
            cout << "Durasi berhasil diubah.\n";

        } else {
            cout << "Input tidak valid.\n";
        }
    }
}

void searchSong(Library L) {
    if (L.head == nullptr) {
        cout << "Library kosong.\n";
        return;
    }

    cout << "\n=== PENCARIAN LAGU ===\n";
    cout << "1. Berdasarkan ID\n";
    cout << "2. Berdasarkan Judul\n";
    cout << "3. Berdasarkan Artis\n";
    cout << "4. Berdasarkan Genre\n";
    cout << "5. Berdasarkan Tahun\n";
    cout << "Pilih (1-5): ";

    int mode;
    cin >> mode;

    bool found = false;
    addressLibrary p = L.head;

    if (mode == 1) {
        int id;
        cout << "Masukkan ID: ";
        cin >> id;

        while (p != nullptr && !found) {
            if (p->info.id == id) {
                cout << "\n-- DITEMUKAN --\n";
                cout << "ID    : " << p->info.id << "\n";
                cout << "Judul : " << p->info.judul << "\n";
                cout << "Artis : " << p->info.artis << "\n";
                cout << "Genre : " << p->info.genre << "\n";
                cout << "Tahun : " << p->info.tahun << "\n";
                cout << "Durasi: " << p->info.durasi << "\n";
                found = true;
            } else {
                p = p->next;
            }
        }
    } else if (mode == 2) {
        string key;
        cout << "Masukkan Judul: ";
        cin >> key;

        while (p != nullptr && !found) {
            if (p->info.judul == key) {
                cout << "\n-- DITEMUKAN --\n";
                cout << "ID    : " << p->info.id << "\n";
                cout << "Judul : " << p->info.judul << "\n";
                cout << "Artis : " << p->info.artis << "\n";
                cout << "Genre : " << p->info.genre << "\n";
                cout << "Tahun : " << p->info.tahun << "\n";
                cout << "Durasi: " << p->info.durasi << "\n";
                found = true;
            } else {
                p = p->next;
            }
        }
    } else if (mode == 3) {
        string key;
        cout << "Masukkan Artis: ";
        cin >> key;

        while (p != nullptr) {
            if (p->info.artis == key) {
                cout << "\n-- DITEMUKAN --\n";
                cout << "ID    : " << p->info.id << "\n";
                cout << "Judul : " << p->info.judul << "\n";
                cout << "Artis : " << p->info.artis << "\n";
                cout << "Genre : " << p->info.genre << "\n";
                cout << "Tahun : " << p->info.tahun << "\n";
                cout << "Durasi: " << p->info.durasi << "\n";
                found = true;
            }
            p = p->next;
        }
    } else if (mode == 4) {
        string key;
        cout << "Masukkan Genre: ";
        cin >> key;

        while (p != nullptr) {
            if (p->info.genre == key) {
                cout << "\n-- DITEMUKAN --\n";
                cout << "ID    : " << p->info.id << "\n";
                cout << "Judul : " << p->info.judul << "\n";
                cout << "Artis : " << p->info.artis << "\n";
                cout << "Genre : " << p->info.genre << "\n";
                cout << "Tahun : " << p->info.tahun << "\n";
                cout << "Durasi: " << p->info.durasi << "\n";
                found = true;
            }
            p = p->next;
        }
    } else if (mode == 5) {
        int key;
        cout << "Masukkan Tahun: ";
        cin >> key;

        while (p != nullptr) {
            if (p->info.tahun == key) {
                cout << "\n-- DITEMUKAN --\n";
                cout << "ID    : " << p->info.id << "\n";
                cout << "Judul : " << p->info.judul << "\n";
                cout << "Artis : " << p->info.artis << "\n";
                cout << "Genre : " << p->info.genre << "\n";
                cout << "Tahun : " << p->info.tahun << "\n";
                cout << "Durasi: " << p->info.durasi << "\n";
                found = true;
            }
            p = p->next;
        }
    } else {
        cout << "Pilihan tidak valid.\n";
    }

    if (!found) {
        cout << "Tidak ada lagu yang cocok.\n";
    }
}

void deleteSong(Library &L, int id, addressUser userList) {
    addressLibrary p = L.head;
    addressLibrary target = nullptr;

    while (p != nullptr) {
        if (p->info.id == id) {
            target = p;
        }
        p = p->next;
    }

    if (target == nullptr) {
        cout << "Lagu tidak ditemukan.\n";
    } else {
        if (target->prev != nullptr) {
            target->prev->next = target->next;
        } else {
            L.head = target->next;
        }

        if (target->next != nullptr) {
            target->next->prev = target->prev;
        } else {
            L.tail = target->prev;
        }
        addressUser u = userList;

        while (u != nullptr) {
            addressPlaylistNode pn = u->firstPlaylist;

            while (pn != nullptr) {
                removeSongFromPlaylist(pn->info, id);
                pn = pn->next;
            }
            u = u->next;
        }
        delete target;

        cout << "Lagu dan seluruh relasinya telah dihapus.\n";
    }
}

addressUser createUser(string nama, string pw) {
    addressUser u = new NodeUser;
    u->username = nama;
    u->password = pw;
    u->firstPlaylist = nullptr;
    u->next = nullptr;
    u->prev = nullptr;

    return u;
}

void addUser(addressUser &U, addressUser baru) {
    if (U == nullptr) {
        U = baru;
    } else {
        addressUser p = U;
        while (p->next != nullptr) {
            p = p->next;
        }

        p->next = baru;
        baru->prev = p;
    }
}

addressPlaylistNode createPlaylistNode(string nama) {
    addressPlaylistNode pn = new PlaylistNode;
    pn->info.nama = nama;
    pn->info.head = nullptr;
    pn->info.tail = nullptr;
    pn->next = nullptr;
    pn->prev = nullptr;

    return pn;
}

void addPlaylistToUser(addressUser u, string nama) {
    if (u == nullptr) {
        cout << "User tidak valid.\n";
    } else {
        addressPlaylistNode cek = u->firstPlaylist;
        bool duplicate = false;

        while (cek != nullptr) {
            if (cek->info.nama == nama) {
                duplicate = true;
            }
            cek = cek->next;
        }

        if (duplicate == false) {
            addressPlaylistNode pn = createPlaylistNode(nama);

            if (u->firstPlaylist == nullptr) {
                u->firstPlaylist = pn;
            } else {
                addressPlaylistNode q = u->firstPlaylist;

                while (q->next != nullptr) {
                    q = q->next;
                }
                q->next = pn;
                pn->prev = q;
            }

            cout << "Playlist '" << nama << "' ditambahkan untuk user " << u->username << ".\n";
        } else {
            cout << "User sudah memiliki playlist dengan nama tersebut.\n";
        }
    }
}

void deletePlaylist(addressUser u, string namaPlaylist) {
    if (u == nullptr || u->firstPlaylist == nullptr) {
        cout << "Tidak ada playlist.\n";
        return;
    }

    addressPlaylistNode p = u->firstPlaylist;

    while (p != nullptr && p->info.nama != namaPlaylist) {
        p = p->next;
    }

    if (p == nullptr) {
        cout << "Playlist tidak ditemukan.\n";
        return;
    }

    addressPlaylist q = p->info.head;
    while (q != nullptr) {
        addressPlaylist del = q;
        q = q->next;
        delete del;
    }

    if (p->prev != nullptr) {
        p->prev->next = p->next;
    } else { 
        u->firstPlaylist = p->next;   
    }

    if (p->next != nullptr) {
        p->next->prev = p->prev;
    }
    delete p;
    
    cout << "Playlist \"" << namaPlaylist << "\" telah dihapus.\n";
}

void renamePlaylist(addressUser u, string oldName, string newName) {
    if (u == nullptr) {
        cout << "User tidak valid.\n";
        return;
    }

    addressPlaylistNode p = u->firstPlaylist;
    bool found = false;

    while (p != nullptr && !found) {   
        if (p->info.nama == oldName) {
            p->info.nama = newName;
            found = true;
            cout << "Playlist '" << oldName << "' diganti menjadi '" << newName << "'.\n";
        } else {
            p = p->next;
        }
    }
    if (!found) {
        cout << "Playlist tidak ditemukan untuk user tersebut.\n";
    }
}

void searchPlaylist(addressUser users, string playlistName) {
    addressUser u = users;
    bool found = false;

    while (u != nullptr) {
        addressPlaylistNode pn = u->firstPlaylist;

        while (pn != nullptr) {
            if (pn->info.nama == playlistName) {
                cout << "\n=== Playlist Ditemukan ===\n";
                cout << "Nama: " << pn->info.nama << "\n";
                cout << "Pemilik: " << u->username << "\n";
                showPlaylist(pn->info);
                found = true;
            }
            pn = pn->next;
        }

        u = u->next;
    }

    if (!found) {
        cout << "Playlist '" << playlistName << "' tidak ditemukan.\n";
    }
}

void createPlaylist(Playlist &P, string nama) {
    P.nama = nama;
    P.head = nullptr;
    P.tail = nullptr;
}

addressPlaylist allocatePlaylist(addressLibrary L) {
    if (L == nullptr) {
        return nullptr;
    }
    addressPlaylist r = new NodePlaylist;

    r->lagu = L;
    r->next = nullptr;
    r->prev = nullptr;

    return r;
}

void addSongToPlaylist(Playlist &P, addressLibrary L) {
    if (L == nullptr) {
        cout << "Lagu tidak valid.\n";
    } else {
        addressPlaylist node = allocatePlaylist(L);

        if (P.head == nullptr) {
            P.head = P.tail = node;
        } else {
            P.tail->next = node;
            node->prev = P.tail;
            P.tail = node;
        }
        cout << "Lagu '" << L->info.judul << "' ditambahkan ke playlist '" << P.nama << "'.\n";
    }
}

void removeSongFromPlaylist(Playlist &P, int id) {
    addressPlaylist p = P.head;

    while (p != nullptr) {
        addressPlaylist nextNode = p->next;

        if (p->lagu != nullptr && p->lagu->info.id == id) {

            if (p->prev != nullptr) {
                p->prev->next = p->next;
            } else {
                P.head = p->next;
            }

            if (p->next != nullptr) {
                p->next->prev = p->prev;
            } else {
                P.tail = p->prev;
            }

            delete p;
        }

        p = nextNode;
    }
}

void showPlaylist(Playlist P) {
    if (P.head == nullptr) {
        cout << "Playlist '" << P.nama << "' kosong.\n";
    } else {

        cout << "\n=== PLAYLIST: " << P.nama << " ===\n";

        addressPlaylist p = P.head;
        int idx = 1;

        while (p != nullptr) {

            if (p->lagu != nullptr) {
            string combined = p->lagu->info.judul + string(" - ") + p->lagu->info.artis;

            cout << setw(3) << idx << ". "
                 << "ID: " << setw(4) << left << p->lagu->info.id
                 << " | " << setw(40) << left << combined
                 << "\n";

                idx = idx + 1;
            }

            p = p->next;
        }
    }
}

bool isPlaylistEmpty(Playlist P) {
    return P.head == nullptr;
}

void createStack(Stack &S) {
    S.top = nullptr;
}

void push(Stack &S, addressLibrary L) {
    if (L != nullptr) {

        addressStackNode n = new StackNode;

        n->lagu = L;
        n->next = S.top;

        S.top = n;
    }
}

addressLibrary pop(Stack &S) {
    addressLibrary result = nullptr;

    if (S.top != nullptr) {
        addressStackNode t = S.top;
        result = t->lagu;
        S.top = t->next;

        delete t;
    }
    return result;
}

bool isStackEmpty(Stack S) {
    return S.top == nullptr;
}

void showStack(Stack S) {
    if (S.top == nullptr) {
        cout << "(Kosong)\n";
    } else {
        addressStackNode p = S.top;
        int idx = 1;

        while (p != nullptr) {
            if (p->lagu != nullptr) {
                cout << idx << ". " << p->lagu->info.judul
                     << " - " << p->lagu->info.artis << "\n";
                idx = idx + 1;
            }

            p = p->next;
        }
    }
}

void createQueue(Queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

void enqueue(Queue &Q, addressLibrary L) {
    if (L != nullptr) {

        addressQueueNode n = new QueueNode;

        n->lagu = L;
        n->next = nullptr;

        if (Q.head == nullptr) {
            Q.head = Q.tail = n;
        } else {
            Q.tail->next = n;
            Q.tail = n;
        }
    }
}

addressLibrary dequeue(Queue &Q) {
    addressLibrary result = nullptr;

    if (Q.head != nullptr) {
        addressQueueNode t = Q.head;

        result = t->lagu;
        Q.head = t->next;

        if (Q.head == nullptr) {
            Q.tail = nullptr;
        }

        delete t;
    }

    return result;
}

bool isQueueEmpty(Queue Q) {
    return Q.head == nullptr;
}

void showQueue(Queue Q) {
    cout << "\n=== ANTRIAN LAGU ===\n";

    if (Q.head == nullptr) {
        cout << "(Kosong)\n";
    } else {
        addressQueueNode p = Q.head;
        int idx = 1;

        while (p != nullptr) {

            if (p->lagu != nullptr) {
                cout << idx << ". " << p->lagu->info.judul
                     << " - " << p->lagu->info.artis << "\n";

                idx = idx + 1;
            }

            p = p->next;
        }
    }
}

void playSong(CurrentPlay &cp, addressLibrary s, Stack &history) {
    if (s != nullptr) {
        cp.songPtr = s;
        cp.isPlaying = true;
        cp.fromPlaylist = false;
        cp.currentPlaylistNode = nullptr;

        s->info.playCount++;

        cout << "\n Memutar: "
             << s->info.judul << " - " << s->info.artis << "\n";
    } else {
        cout << "Lagu tidak valid.\n";
    }
}

void playFromPlaylist(CurrentPlay &cp, Playlist &P, int id, Stack &history) {
    addressPlaylist p = P.head;
    addressPlaylist found = nullptr;

    while (p != nullptr) {
        if (p->lagu != nullptr && p->lagu->info.id == id) {
            found = p;
        }
        p = p->next;
    }

    if (found != nullptr) {
        cp.songPtr = found->lagu;
        cp.isPlaying = true;
        cp.fromPlaylist = true;
        cp.currentPlaylistNode = found;

        cp.songPtr->info.playCount++;

        cout << "\n Memutar dari playlist: "
             << cp.songPtr->info.judul << " - "
             << cp.songPtr->info.artis << "\n";
    } else {
        cout << "Lagu tidak ditemukan di playlist.\n";
    }
}

void stopSong(CurrentPlay &cp) {
    if (cp.isPlaying == true && cp.songPtr != nullptr) {
        cout << " Stop: " << cp.songPtr->info.judul << " - " << cp.songPtr->info.artis << "\n";
        cp.isPlaying = false;
    } else {
        cout << "Tidak ada lagu yang sedang diputar.\n";
    }
}

addressLibrary findSimilarSong(Library L, addressLibrary current) {
    addressLibrary result = nullptr;
    if (current != nullptr) {
        addressLibrary p = L.head;
        addressLibrary artistMatch = nullptr;
        addressLibrary genreMatch = nullptr;

        while (p != nullptr) {
            if (p != current) {
                if (p->info.artis == current->info.artis
                    && artistMatch == nullptr) {
                    artistMatch = p;
                }
                if (p->info.genre == current->info.genre
                    && genreMatch == nullptr) {
                    genreMatch = p;
                }
            }

            p = p->next;
        }
        if (artistMatch != nullptr) {
            result = artistMatch;
        } else if (genreMatch != nullptr) {
            result = genreMatch;
        }
    }
    return result;
}

void nextSong(Library L, CurrentPlay &cp, Stack &history) {
    if (cp.isPlaying == true && cp.songPtr != nullptr) {
        if (cp.fromPlaylist == true && cp.currentPlaylistNode != nullptr) {
            addressPlaylist nextNode = cp.currentPlaylistNode->next;
            
            if (nextNode != nullptr) {
                
                if (cp.songPtr != nullptr && (history.top == nullptr || history.top->lagu != cp.songPtr)) {
                    push(history, cp.songPtr);
                }
                
                cp.currentPlaylistNode = nextNode;
                cp.songPtr = nextNode->lagu;
                cp.songPtr->info.playCount++;
                cout << " Next (playlist): "
                     << cp.songPtr->info.judul
                     << " - " << cp.songPtr->info.artis << "\n";
            } else {
                cout << "Akhir playlist.\n";
            }

        } else {
            addressLibrary similar = findSimilarSong(L, cp.songPtr);
            if (similar != nullptr) {
                
                if (cp.songPtr != nullptr && (history.top == nullptr || history.top->lagu != cp.songPtr)) {
                    push(history, cp.songPtr);
                }

                cp.songPtr = similar;
                cp.songPtr->info.playCount++;
                cout << " Next (similar): "
                     << cp.songPtr->info.judul
                     << " - " << cp.songPtr->info.artis << "\n";
            } else {
                cout << "Tidak ada lagu mirip.\n";
            }
        }

    } else {
        cout << "Tidak ada lagu yang sedang diputar.\n";
    }
}

void prevSong(CurrentPlay &cp, Stack &history) {
    addressLibrary last = pop(history);

    if (last != nullptr) {
        cp.songPtr = last;
        cp.isPlaying = true;
        cp.fromPlaylist = false;
        cp.currentPlaylistNode = nullptr;

        last->info.playCount++;

        cout << " Kembali ke: "
             << last->info.judul
             << " - " << last->info.artis << "\n";
    } else {
        cout << "Tidak ada riwayat sebelumnya.\n";
    }
}

void showMostPlayed(Library L) {
    if (L.head == nullptr) {
        cout << "Library kosong.\n";
        return;
    }

    addressLibrary p = L.head;
    int maxCount = -1;
    addressLibrary best = nullptr;

    while (p != nullptr) {
        if (p->info.playCount > maxCount) {
            maxCount = p->info.playCount;
            best = p;
        }
        p = p->next;
    }

    if (best != nullptr && maxCount > 0) {
        cout << "\n=== Lagu Paling Sering Diputar ===\n";
        cout << best->info.judul << " - " << best->info.artis
             << " | Diputar: " << best->info.playCount << " kali\n";
        cout << "=================================\n";
    } else {
        cout << "Belum ada data pemutaran atau semua playCount = 0.\n";
    }
}

void markFavoriteById(Library &L, int id) {
    addressLibrary p = findSongById(L, id);
    if (p == nullptr) {
        cout << "Lagu tidak ditemukan.\n";
    } else {
        p->info.favorite = true;
        cout << "Lagu '" << p->info.judul << "' ditandai favorit.\n";
    }
}

void unmarkFavoriteById(Library &L, int id) {
    addressLibrary p = findSongById(L, id);
    if (p == nullptr) {
        cout << "Lagu tidak ditemukan.\n";
    } else {
        p->info.favorite = false;
        cout << "Lagu '" << p->info.judul << "' dihapus dari favorit.\n";
    }
}

void showFavoriteSongs(Library L) {
    if (L.head == nullptr) {
        cout << "Library kosong.\n";
        return;
    }

    addressLibrary p = L.head;
    bool any = false;
    cout << "\n=== Lagu Favorit ===\n";
    while (p != nullptr) {
        if (p->info.favorite) {
            cout << "ID: " << p->info.id << " | " << p->info.judul
                 << " - " << p->info.artis << " | Diputar: " << p->info.playCount << "\n";
            any = true;
        }
        p = p->next;
    }
    if (!any) cout << "(Belum ada lagu favorit)\n";
}

addressLibrary getRandomSong(Library L) {
    int total = 0;
    addressLibrary p = L.head;
    while (p != nullptr) { 
        total++; p = p->next; 
    }
    
    if (total == 0) {
        return nullptr;
    }
    
    int idx = rand() % total;
    p = L.head;
    int i = 0;
    while (p != nullptr) {
        if (i == idx) return p;
        i++;
        p = p->next;
    }
    return nullptr;
}

void shufflePlayLibrary(Library L, CurrentPlay &cp, Stack &history) {
    addressLibrary r = getRandomSong(L);
    if (r != nullptr) {
        playSong(cp, r, history);
        cout << "(Mode Shuffle)\n";
    } else {
        cout << "Library kosong.\n";
    }
}

void setUserPassword(addressUser u, string pass) {
    if (u == nullptr) {
        return;
    }
    u->password = pass;
}

bool verifyUserPassword(addressUser u, string pass) {
    if (u == nullptr) {
        return false;
    }
    return u->password == pass;
}

addressUser findUser(addressUser U, string username) {
    addressUser p = U;
    while (p != nullptr) {
        if (p->username == username) {
            return p;
        }
        p = p->next;
    }
    return nullptr; 
}
