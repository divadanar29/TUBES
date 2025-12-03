#include <iostream>
#include "tubes.h"

using namespace std;

// Library (DLL)
void createLibrary(Library &L){
    L.head = nullptr;
    L.tail = nullptr;
}

addressLibrary allocateLibrary(Song s){
    addressLibrary P = new NodeLibrary;
    P->info = s;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void addSong(Library &L, Song s){
    addressLibrary P = allocateLibrary(s);

    if (L.head == nullptr) {
        L.head = P;
        L.tail = P;
    } else {
        L.tail->next = P;
        P->prev = L.tail;
        L.tail = P;
    }
}

void showAllSongs(Library L){
    addressLibrary P = L.head;

    while (P != nullptr) {
        cout << P->info.id << " - " << P->info.judul << endl;
        P = P->next;
    }
}

addressLibrary findSongById(Library L, int id){
    addressLibrary P = L.head;
    addressLibrary hasil = nullptr;

    while (P != nullptr) {
        if (P->info.id == id) {
            hasil = P;
        }
        P = P->next;
    }

    return hasil;
}

void updateSong(Library &L, int id, Song newData){
    addressLibrary P = findSongById(L, id);

    if (P != nullptr) {
        P->info = newData;
    }
}

void deleteSong(Library &L, int id){
    addressLibrary P = findSongById(L, id);

    if (P != nullptr) {

        bool onlyOne = (L.head == P && L.tail == P);
        bool isHead = (L.head == P);
        bool isTail = (L.tail == P);

        if (onlyOne) {
            L.head = nullptr;
            L.tail = nullptr;

        } else if (isHead) {
            L.head = P->next;
            L.head->prev = nullptr;

        } else if (isTail) {
            L.tail = P->prev;
            L.tail->next = nullptr;

        } else {
            P->prev->next = P->next;
            P->next->prev = P->prev;
        }

        delete P;
    }
}

// Playlist (SLL relasi)
void createPlaylist(Playlist &P, string nama);
addressPlaylist allocatePlaylist(addressLibrary L);
void addSongToPlaylist(Playlist &P, addressLibrary L);
void removeSongFromPlaylist(Playlist &P, int id);
void showPlaylist(Playlist P);

// Stack History
void createStack(HistoryStack &S);
void pushHistory(HistoryStack &S, addressLibrary L);
addressLibrary popHistory(HistoryStack &S);
bool isStackEmpty(HistoryStack S);
void showHistory(HistoryStack S);

// Queue Antrian
void createQueue(PlayQueue &Q){
    Q.head = nullptr;
    Q.tail = nullptr;
}

void enqueue(PlayQueue &Q, addressLibrary L){
    addressQueue P = new NodeQueue;
    P->lagu = L;
    P->next = nullptr;

    if (Q.head == nullptr) {
        Q.head = P;
        Q.tail = P;
    } else {
        Q.tail->next = P;
        Q.tail = P;
    }
}

addressLibrary dequeue(PlayQueue &Q){
    addressQueue P = Q.head;
    addressLibrary hasil = nullptr;

    if (P != nullptr) {
        hasil = P->lagu;
        Q.head = P->next;

        if (Q.head == nullptr) {
            Q.tail = nullptr;
        }

        delete P;
    }

    return hasil;
}

bool isQueueEmpty(PlayQueue Q){
    return (Q.head == nullptr);
}

void showQueue(PlayQueue Q){
    addressQueue P = Q.head;

    cout << "\n=== DAFTAR ANTRIAN LAGU (QUEUE) ===\n";

    if (P == nullptr) {
        cout << "Queue kosong.\n";
    } else {
        int nomor = 1;

        while (P != nullptr) {
            cout << nomor << ". "
                 << P->lagu->info.judul << " - "
                 << P->lagu->info.artis << "\n";

            P = P->next;
            nomor = nomor + 1;
        }
    }

    cout << "====================================\n";
}

// Navigasi Lagu
void playSong(CurrentPlay &cp, addressLibrary L);
void stopSong(CurrentPlay &cp);
void nextSong(Library L, CurrentPlay &cp);
void prevSong(Library L, CurrentPlay &cp);
void playFromPlaylist(Playlist P, CurrentPlay &cp, int id);

// Pencarian
void searchSong(Library L){
    string key;
    int pilihan;

    cout << "PENCARIAN LAGU\n";
    cout << "Cari berdasarkan:\n";
    cout << "1. Judul\n";
    cout << "2. Penyanyi\n";
    cout << "3. Genre\n";
    cout << "Pilih (1-3): ";
    cin >> pilihan;

    cout << "Masukkan kata kunci: ";
    cin >> key;

    addressLibrary P = L.head;
    bool found = false;

    // Penelusuran sequential dari head sampai tail
    while (P != nullptr) {
        // Langsung cek kondisi sesuai pilihan
        if ((pilihan == 1 && P->info.judul == key) ||
            (pilihan == 2 && P->info.penyanyi == key) ||
            (pilihan == 3 && P->info.genre == key))
        {
            if (!found) {
                cout << "\nHASIL PENCARIAN:\n";
            }

            cout << "---------------------------------\n";
            cout << "Judul   : " << P->info.judul << endl;
            cout << "Penyanyi: " << P->info.penyanyi << endl;
            cout << "Genre   : " << P->info.genre << endl;

            found = true;
        }

        P = P->next;   // lanjutkan sampai akhir list
    }

    if (!found) {
        cout << "Lagu tidak ditemukan.\n";
    }
}
