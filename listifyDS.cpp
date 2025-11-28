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

    while (P != NULL) {
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
            L.head->prev = NULL;

        } else if (isTail) {
            L.tail = P->prev;
            L.tail->next = NULL;

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
void createQueue(PlayQueue &Q);
void enqueue(PlayQueue &Q, addressLibrary L);
addressLibrary dequeue(PlayQueue &Q);
bool isQueueEmpty(PlayQueue Q);
void showQueue(PlayQueue Q);

// Navigasi Lagu
void playSong(CurrentPlay &cp, addressLibrary L);
void stopSong(CurrentPlay &cp);
void nextSong(Library L, CurrentPlay &cp);
void prevSong(Library L, CurrentPlay &cp);
void playFromPlaylist(Playlist P, CurrentPlay &cp, int id);

// Pencarian
void searchSong(Library L);
