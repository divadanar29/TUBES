#ifndef LISTIFYDS_H_INCLUDED
#define LISTIFYDS_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

// ============================================================
//  TYPEDEF POINTER
// ============================================================
typedef struct NodeLibrary*        addressLibrary;
typedef struct NodePlaylist*       addressPlaylist;
typedef struct PlaylistNode*       addressPlaylistNode;
typedef struct NodeUser*           addressUser;

typedef struct StackNode*          addressStackNode;
typedef struct QueueNode*          addressQueueNode;


// ============================================================
//  STRUCT: SONG (UPDATED WITH DURASI)
// ============================================================
struct Song {
    int id;
    string judul;
    string artis;
    string genre;
    int tahun;
    int durasi;     // durasi lagu (detik atau menit)
};


// ============================================================
//  LIBRARY (DOUBLY LINKED LIST)
// ============================================================
struct NodeLibrary {
    Song info;
    addressLibrary next;
    addressLibrary prev;
};

struct Library {
    addressLibrary head;
    addressLibrary tail;
};


// ============================================================
//  PLAYLIST (DLL RELATION, MENAMPUNG POINTER KE LIBRARY)
// ============================================================
struct NodePlaylist {
    addressLibrary lagu;   // pointer ke node library
    addressPlaylist next;
    addressPlaylist prev;
};

struct Playlist {
    string nama;
    addressPlaylist head;
    addressPlaylist tail;
};


// ============================================================
//  USER (MULTIPLE PLAYLISTS) – MLL TIPE A
// ============================================================
struct PlaylistNode {
    Playlist info;                  // satu user bisa punya banyak playlist
    addressPlaylistNode next;
    addressPlaylistNode prev;
};

struct NodeUser {
    string username;
    addressPlaylistNode firstPlaylist;

    addressUser next;
    addressUser prev;
};


// ============================================================
//  STACK (RIWAYAT LAGU DIPUTAR) – LIFO
// ============================================================
struct StackNode {
    addressLibrary lagu;
    addressStackNode next;
};

struct Stack {
    addressStackNode top;
};


// ============================================================
//  QUEUE (ANTRIAN LAGU) – FIFO
// ============================================================
struct QueueNode {
    addressLibrary lagu;
    addressQueueNode next;
};

struct Queue {
    addressQueueNode head;
    addressQueueNode tail;
};


// ============================================================
//  CURRENT PLAY (STATUS PLAYER SAAT INI)
// ============================================================
struct CurrentPlay {
    addressLibrary songPtr;
    bool isPlaying;

    bool fromPlaylist;
    addressPlaylist currentPlaylistNode;
};


// ============================================================
//  FUNGSI LIBRARY
// ============================================================
void createLibrary(Library &L);
addressLibrary allocateLibrary(Song s);
void addSong(Library &L, Song s);
void showAllSongs(Library L);
addressLibrary findSongById(Library L, int id);
void updateSong(Library &L, int id, Song newData);
void searchSong(Library L);
void deleteSong(Library &L, int id, addressUser userList);


// ============================================================
//  USER & PLAYLIST MANAGEMENT (MLL TIPE A)
// ============================================================
addressUser createUser(string nama);
void addUser(addressUser &U, addressUser newUser);

addressPlaylistNode createPlaylistNode(string nama);
void addPlaylistToUser(addressUser u, string nama);


// ============================================================
//  PLAYLIST (DLL RELATION)
// ============================================================
void createPlaylist(Playlist &P, string nama);
addressPlaylist allocatePlaylist(addressLibrary L);
void addSongToPlaylist(Playlist &P, addressLibrary L);
void removeSongFromPlaylist(Playlist &P, int id);
void showPlaylist(Playlist P);
bool isPlaylistEmpty(Playlist P);


// ============================================================
//  STACK
// ============================================================
void createStack(Stack &S);
void push(Stack &S, addressLibrary L);
addressLibrary pop(Stack &S);
bool isStackEmpty(Stack S);
void showStack(Stack S);


// ============================================================
//  QUEUE
// ============================================================
void createQueue(Queue &Q);
void enqueue(Queue &Q, addressLibrary L);
addressLibrary dequeue(Queue &Q);
bool isQueueEmpty(Queue Q);
void showQueue(Queue Q);


// ============================================================
//  PLAY CONTROL (MENGATUR PEMUTARAN LAGU)
// ============================================================
void playSong(CurrentPlay &cp, addressLibrary s);
void playFromPlaylist(CurrentPlay &cp, Playlist &P, int id);
void stopSong(CurrentPlay &cp);
void nextSong(Library L, CurrentPlay &cp);
void prevSong(CurrentPlay &cp, Stack &history);

addressLibrary findSimilarSong(Library L, addressLibrary current);

#endif
