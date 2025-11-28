#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

using namespace std;

// ======================
//  DATA LAGU
// ======================
struct Song {
    int id;
    string judul;
    string artis;
    string genre;
    int tahun;
};

// ======================
//  DOUBLY LINKED LIST (LIBRARY LAGU UTAMA)
// ======================
typedef struct NodeLibrary* addressLibrary;

struct NodeLibrary {
    Song info;
    addressLibrary next;
    addressLibrary prev;
};

struct Library {
    addressLibrary head;
    addressLibrary tail;
};

// ======================
//  PLAYLIST (SINGLY LINKED LIST RELASI KE LIBRARY)
// ======================
typedef struct NodePlaylist* addressPlaylist;

struct NodePlaylist {
    addressLibrary lagu;     // pointer menuju node lagu di library
    addressPlaylist next;
};

struct Playlist {
    string nama;
    addressPlaylist head;
    addressPlaylist tail;
};

// ======================
//  USER (MLL Tipe A)
//  User → punya banyak playlist
// ======================
struct NodeUser {
    string username;
    NodeUser* nextUser;
    Playlist* listPlaylist;   // pointer ke array/LL playlist (bebas versi kamu)
};

// ======================
//  STACK RIWAYAT PEMUTARAN
// ======================
typedef struct NodeHistory* addressHistory;

struct NodeHistory {
    addressLibrary lagu;     // menyimpan pointer ke lagu yang diputar
    NodeHistory* next;
};

struct HistoryStack {
    addressHistory top;
};

// ======================
//  QUEUE ANTRIAN PEMUTARAN
// ======================
typedef struct NodeQueue* addressQueue;

struct NodeQueue {
    addressLibrary lagu;
    NodeQueue* next;
};

struct PlayQueue {
    addressQueue front;
    addressQueue rear;
};

// ======================
// INFORMASI PEMUTARAN LAGU
// ======================
struct CurrentPlay {
    addressLibrary currentLibraryNode;     // untuk navigasi next/prev di library
    addressPlaylist currentPlaylistNode;   // untuk navigasi next/prev di playlist

    bool isPlaying;
    bool fromPlaylist;                     // true = sedang memutar dari playlist

    Song info;                             // salinan data lagu (opsional)
};

// ==============================
//  PROTOTYPE FUNGSI & PROSEDUR
// ==============================

// Library (DLL)
void createLibrary(Library &L);
addressLibrary allocateLibrary(Song s);
void addSong(Library &L, Song s);
void showAllSongs(Library L);
addressLibrary findSongById(Library L, int id);
void updateSong(Library &L, int id, Song newData);
void deleteSong(Library &L, int id);

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

#endif // TUBES_H_INCLUDED
