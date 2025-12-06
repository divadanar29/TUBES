#include "listifyDS.h"

// ====================================================================
//                  IMPLEMENTASI LIBRARY (DLL SONG)
// ====================================================================

// Membuat library kosong (head dan tail = null)
void createLibrary(Library &L) {
    L.head = nullptr;
    L.tail = nullptr;
}

// Mengalokasikan node lagu baru
addressLibrary allocateLibrary(Song s) {
    // Membuat node baru di heap
    addressLibrary p = new NodeLibrary;

    // Mengisi informasi lagu
    p->info = s;

    // Set pointer awal
    p->next = nullptr;
    p->prev = nullptr;

    return p;
}

// Menambahkan lagu baru ke akhir library (DLL)
void addSong(Library &L, Song s) {
    addressLibrary p = allocateLibrary(s);

    // Jika library masih kosong
    if (L.head == nullptr) {
        L.head = p;
        L.tail = p;
    } else {
        // Tambahkan di bagian belakang (tail)
        L.tail->next = p;
        p->prev = L.tail;
        L.tail = p;
    }

    cout << "Lagu '" << s.judul << "' berhasil ditambahkan ke library.\n";
}

// Menampilkan semua lagu dalam library
void showAllSongs(Library L) {
    if (L.head == nullptr) {
        cout << "Library kosong.\n";
        return;
    }

    cout << "\n=== DAFTAR LAGU ===\n";
    addressLibrary p = L.head;
    int idx = 1;

    // Menelusuri node dari head sampai tail
    while (p != nullptr) {
        // Menampilkan detail lagu 
        cout << idx << ". ID: " << p->info.id
             << " | " << p->info.judul
             << " - " << p->info.artis
             << " | " << p->info.genre
             << " | " << p->info.tahun
             << " | " << p->info.durasi << "\n";
        p = p->next;
        idx = idx + 1;
    }
    cout << "====================\n";
}

// Mencari lagu berdasarkan ID (mengembalikan pointer node)
addressLibrary findSongById(Library L, int id) {
    addressLibrary p = L.head;
    addressLibrary result = nullptr;

    // Telusuri sequential hingga ketemu
    while (p != nullptr) {
        if (p->info.id == id) {
            result = p;
        }
        p = p->next;
    }

    return result;
}

// Mengupdate data sebuah lagu berdasarkan ID
void updateSong(Library &L, int id, Song newData) {
    addressLibrary p = findSongById(L, id);

    if (p == nullptr) {
        cout << "Lagu dengan ID " << id << " tidak ditemukan.\n";
    } else {
        // Mengganti seluruh info lagu
        p->info = newData;
        cout << "Lagu berhasil diupdate.\n";
    }
}

// ====================================================================
//              FITUR PENCARIAN — MULTI FIELD SEARCHING
// ====================================================================

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

    // MODE 1 — ID
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
    }

    // MODE 2 — Judul 
    else if (mode == 2) {
        string key;
        cout << "Masukkan Judul (exact): ";
        cin >> key;    // diganti getline agar bisa tanpa ignore

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
    }

    // MODE 3 — Artis 
    else if (mode == 3) {
        string key;
        cout << "Masukkan Artis (exact): ";
        cin >> key;

        while (p != nullptr && !found) {
            if (p->info.artis == key) {
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
    }

    // MODE 4 — Genre 
    else if (mode == 4) {
        string key;
        cout << "Masukkan Genre (exact): ";
        cin >> key;

        while (p != nullptr && !found) {
            if (p->info.genre == key) {
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
    }

    // MODE 5 — Tahun 
    else if (mode == 5) {
        int key;
        cout << "Masukkan Tahun: ";
        cin >> key;

        while (p != nullptr && !found) {
            if (p->info.tahun == key) {
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
    }

    else {
        cout << "Pilihan tidak valid.\n";
    }

    if (!found) {
        cout << "Tidak ada lagu yang cocok.\n";
    }
}

// ====================================================================
//                 DELETE SONG — HAPUS LAGU + RELASI PLAYLIST
// ====================================================================

void deleteSong(Library &L, int id, addressUser userList) {
    addressLibrary p = L.head;
    addressLibrary target = nullptr;

    // Cari node lagu yang ingin dihapus
    while (p != nullptr) {
        if (p->info.id == id) {
            target = p;
        }
        p = p->next;
    }

    if (target == nullptr) {
        cout << "Lagu tidak ditemukan.\n";
    } else {

        // =========================
        // Hapus dari DLL Library
        // =========================

        // Jika node bukan head
        if (target->prev != nullptr) {
            target->prev->next = target->next;
        } else {
            // Node adalah head
            L.head = target->next;
        }

        // Jika node bukan tail
        if (target->next != nullptr) {
            target->next->prev = target->prev;
        } else {
            // Node adalah tail
            L.tail = target->prev;
        }

        // =========================
        // Hapus relasi lagu dari SEMUA playlist semua user
        // =========================
        addressUser u = userList;

        while (u != nullptr) {
            addressPlaylistNode pn = u->firstPlaylist;

            while (pn != nullptr) {
                removeSongFromPlaylist(pn->info, id);
                pn = pn->next;
            }

            u = u->next;
        }

        // Hapus node dari memory
        delete target;

        cout << "Lagu dan seluruh relasinya telah dihapus.\n";
    }
}

// ====================================================================
//                     USER & PLAYLIST (MLL Tipe A)
// ====================================================================

// Membuat user baru
addressUser createUser(string nama) {
    addressUser u = new NodeUser;

    u->username = nama;
    u->firstPlaylist = nullptr;

    u->next = nullptr;
    u->prev = nullptr;

    return u;
}

// Menambahkan user ke akhir daftar user (DLL)
void addUser(addressUser &U, addressUser baru) {
    if (U == nullptr) {
        U = baru;
    } else {
        // Telusuri hingga node terakhir
        addressUser p = U;
        while (p->next != nullptr) {
            p = p->next;
        }

        p->next = baru;
        baru->prev = p;
    }
}

// Membuat playlist node (level user → playlist)
addressPlaylistNode createPlaylistNode(string nama) {
    addressPlaylistNode pn = new PlaylistNode;

    pn->info.nama = nama;
    pn->info.head = nullptr;
    pn->info.tail = nullptr;

    pn->next = nullptr;
    pn->prev = nullptr;

    return pn;
}

// Menambahkan playlist baru ke user (akhir)
void addPlaylistToUser(addressUser u, string nama) {

    if (u == nullptr) {
        cout << "User tidak valid.\n";
    } else {
        // Cek apakah playlist sudah ada
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

// ====================================================================
//                 RELASI PLAYLIST → LAGU (DLL)
// ====================================================================

// Membuat playlist kosong
void createPlaylist(Playlist &P, string nama) {
    P.nama = nama;
    P.head = nullptr;
    P.tail = nullptr;
}

// Mengalokasikan node relasi
addressPlaylist allocatePlaylist(addressLibrary L) {
    if (L == nullptr) return nullptr;

    addressPlaylist r = new NodePlaylist;

    r->lagu = L;
    r->next = nullptr;
    r->prev = nullptr;

    return r;
}

// Menambahkan lagu ke playlist (akhir)
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

// Menghapus lagu dari playlist tertentu
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

// Menampilkan isi playlist
void showPlaylist(Playlist P) {

    if (P.head == nullptr) {
        cout << "Playlist '" << P.nama << "' kosong.\n";
    } else {

        cout << "\n=== PLAYLIST: " << P.nama << " ===\n";

        addressPlaylist p = P.head;
        int idx = 1;

        while (p != nullptr) {

            if (p->lagu != nullptr) {
                cout << idx << ". ID: " << p->lagu->info.id
                    << " | " << p->lagu->info.judul
                    << " - " << p->lagu->info.artis << "\n";

                idx = idx + 1;
            }

            p = p->next;
        }
    }
}

//mengecek apakah playlist kosong
bool isPlaylistEmpty(Playlist P) {
    return P.head == nullptr;
}

// ====================================================================
//                         STACK (RIWAYAT)
// ====================================================================

// Membuat stack kosong
void createStack(Stack &S) {
    S.top = nullptr;
}

// Push lagu ke stack history
void push(Stack &S, addressLibrary L) {

    if (L != nullptr) {

        addressStackNode n = new StackNode;

        n->lagu = L;
        n->next = S.top;

        S.top = n;
    }
}

// Pop dari stack
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

// Mengecek apakah stack kosong
bool isStackEmpty(Stack S) {
    return S.top == nullptr;
}

// Menampilkan isi stack (riwayat)
void showStack(Stack S) {
    cout << "\n=== RIWAYAT PEMUTARAN ===\n";

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

// ====================================================================
//                               QUEUE
// ====================================================================

// Membuat queue kosong
void createQueue(Queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

// Enqueue (tambah antrian)
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

// Dequeue (ambil dari depan)
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

// Mengecek apakah queue kosong
bool isQueueEmpty(Queue Q) {
    return Q.head == nullptr;
}

// Menampilkan queue
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

// ====================================================================
//                        PLAY CONTROL
// ====================================================================

// Memutar satu lagu langsung (bukan playlist)
void playSong(CurrentPlay &cp, addressLibrary s) {

    if (s != nullptr) {

        cp.songPtr = s;
        cp.isPlaying = true;
        cp.fromPlaylist = false;
        cp.currentPlaylistNode = nullptr;

        cout << "\n▶ Memutar: " 
             << s->info.judul << " - " << s->info.artis << "\n";
    } else {
        cout << "Lagu tidak valid.\n";
    }
}

// Memutar lagu dari playlist tertentu berdasarkan ID lagu
void playFromPlaylist(CurrentPlay &cp, Playlist &P, int id) {
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

        cout << "\n▶ Memutar dari playlist: " 
             << cp.songPtr->info.judul << " - " 
             << cp.songPtr->info.artis << "\n";
    } else {
        cout << "Lagu tidak ditemukan di playlist.\n";
    }
}

// Stop lagu
void stopSong(CurrentPlay &cp) {

    if (cp.isPlaying == true && cp.songPtr != nullptr) {

        cout << "■ Stop: " << cp.songPtr->info.judul
             << " - " << cp.songPtr->info.artis << "\n";

        cp.isPlaying = false;

    } else {
        cout << "Tidak ada lagu yang sedang diputar.\n";
    }
}

// ====================================================================
//                     FIND SIMILAR SONG
// ====================================================================

// Mencari lagu serupa berdasarkan:
// PRIORITAS 1 → artis sama  
// PRIORITAS 2 → genre sama  
//
// Pencarian dilakukan dari head → tail.
// Mengembalikan salah satu node pertama yang cocok.
// Jika tidak ada, return nullptr.
addressLibrary findSimilarSong(Library L, addressLibrary current) {
    addressLibrary result = nullptr;

    if (current != nullptr) {

        addressLibrary p = L.head;
        addressLibrary artistMatch = nullptr;
        addressLibrary genreMatch = nullptr;

        // Telusuri seluruh library
        while (p != nullptr) {

            // Jangan cocokkan dengan dirinya sendiri
            if (p != current) {

                // Cocok artis (pertama kali ditemukan)
                if (p->info.artis == current->info.artis 
                    && artistMatch == nullptr) {
                    artistMatch = p;
                }

                // Cocok genre (pertama kali ditemukan)
                if (p->info.genre == current->info.genre 
                    && genreMatch == nullptr) {
                    genreMatch = p;
                }
            }

            p = p->next;
        }

        // Prioritas 1: artis sama
        if (artistMatch != nullptr) {
            result = artistMatch;
        } 
        // Prioritas 2: genre sama
        else if (genreMatch != nullptr) {
            result = genreMatch;
        }
    }

    return result;
}

// ====================================================================
//                            NEXT SONG
// ====================================================================

// Pindah lagu berikutnya (prioritas):
// 1. Dari playlist (jika sedang play dari playlist)
// 2. Lagu mirip (artis/genre sama)
// 3. Tidak ada → tampilkan pesan
void nextSong(Library L, CurrentPlay &cp) {

    if (cp.isPlaying == true && cp.songPtr != nullptr) {

        // PRIORITAS 1 → jika sedang memutar dari playlist
        if (cp.fromPlaylist == true && cp.currentPlaylistNode != nullptr) {

            addressPlaylist nextNode = cp.currentPlaylistNode->next;

            if (nextNode != nullptr) {

                cp.currentPlaylistNode = nextNode;
                cp.songPtr = nextNode->lagu;

                cout << "▶ Next (playlist): " 
                     << cp.songPtr->info.judul 
                     << " - " << cp.songPtr->info.artis << "\n";
            } else {
                cout << "Akhir playlist.\n";
            }

        } else {
            // PRIORITAS 2 → cari lagu mirip
            addressLibrary similar = findSimilarSong(L, cp.songPtr);

            if (similar != nullptr) {
                cp.songPtr = similar;

                cout << "▶ Next (similar): " 
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

// ====================================================================
//                       PREVIOUS SONG
// ====================================================================

// Mengambil riwayat dari stack (history)
void prevSong(CurrentPlay &cp, Stack &history) {

    addressLibrary last = pop(history);

    if (last != nullptr) {

        cp.songPtr = last;
        cp.isPlaying = true;
        cp.fromPlaylist = false;
        cp.currentPlaylistNode = nullptr;

        cout << "▶ Kembali ke: " 
             << last->info.judul 
             << " - " << last->info.artis << "\n";

    } else {
        cout << "Tidak ada riwayat sebelumnya.\n";
    }
}
