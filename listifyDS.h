#ifndef LISTIFYDS_H_INCLUDED
#define LISTIFYDS_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

typedef struct NodeLibrary*        addressLibrary;
typedef struct NodePlaylist*       addressPlaylist;
typedef struct PlaylistNode*       addressPlaylistNode;
typedef struct NodeUser*           addressUser;

typedef struct StackNode*          addressStackNode;
typedef struct QueueNode*          addressQueueNode;

struct Song {
    int id;
    string judul;
    string artis;
    string genre;
    int tahun;
    string durasi;

    int playCount;
    bool favorite;
};

struct NodeLibrary {
    Song info;
    addressLibrary next;
    addressLibrary prev;
};

struct Library {
    addressLibrary head;
    addressLibrary tail;
};

struct NodePlaylist {
    addressLibrary lagu;
    addressPlaylist next;
    addressPlaylist prev;
};

struct Playlist {
    string nama;
    addressPlaylist head;
    addressPlaylist tail;
};

struct PlaylistNode {
    Playlist info;
    addressPlaylistNode next;
    addressPlaylistNode prev;
};

struct NodeUser {
    string username;
    string password;

    addressPlaylistNode firstPlaylist;

    addressUser next;
    addressUser prev;
};

struct StackNode {
    addressLibrary lagu;
    addressStackNode next;
};

struct Stack {
    addressStackNode top;
};

struct QueueNode {
    addressLibrary lagu;
    addressQueueNode next;
};

struct Queue {
    addressQueueNode head;
    addressQueueNode tail;
};

struct CurrentPlay {
    addressLibrary songPtr;
    bool isPlaying;

    bool fromPlaylist;
    addressPlaylist currentPlaylistNode;
};

void clrscr();
void konfirmKeluar();

void createLibrary(Library &L);
addressLibrary allocateLibrary(Song s);
void addSong(Library &L, Song s);
void showAllSongs(Library L);
addressLibrary findSongById(Library L, int id);
void updateSong(Library &L, int id);
void searchSong(Library L);
void deleteSong(Library &L, int id, addressUser userList);

addressUser createUser(string nama, string pw);
void addUser(addressUser &U, addressUser newUser);

addressPlaylistNode createPlaylistNode(string nama);
void addPlaylistToUser(addressUser u, string nama);

void renamePlaylist(addressUser u, string oldName, string newName);
void searchPlaylist(addressUser users, string playlistName);

void createPlaylist(Playlist &P, string nama);
addressPlaylist allocatePlaylist(addressLibrary L);
void addSongToPlaylist(Playlist &P, addressLibrary L);
void removeSongFromPlaylist(Playlist &P, int id);
void showPlaylist(Playlist P);
bool isPlaylistEmpty(Playlist P);

void createStack(Stack &S);
void push(Stack &S, addressLibrary L);
addressLibrary pop(Stack &S);
bool isStackEmpty(Stack S);
void showStack(Stack S);

void createQueue(Queue &Q);
void enqueue(Queue &Q, addressLibrary L);
addressLibrary dequeue(Queue &Q);
bool isQueueEmpty(Queue Q);
void showQueue(Queue Q);

void playSong(CurrentPlay &cp, addressLibrary s, Stack &history);
void playFromPlaylist(CurrentPlay &cp, Playlist &P, int id, Stack &history);
void stopSong(CurrentPlay &cp);
void nextSong(Library L, CurrentPlay &cp, Stack &history);
void prevSong(CurrentPlay &cp, Stack &history);

addressLibrary findSimilarSong(Library L, addressLibrary current);

void deletePlaylist(addressUser u, string namaPlaylist);

void showMostPlayed(Library L);
void markFavoriteById(Library &L, int id);
void unmarkFavoriteById(Library &L, int id);
void showFavoriteSongs(Library L);

addressLibrary getRandomSong(Library L);
void shufflePlayLibrary(Library L, CurrentPlay &cp, Stack &history);
void setUserPassword(addressUser u, string pass);
bool verifyUserPassword(addressUser u, string pass);
addressUser findUser(addressUser U, string username);

#endif // LISTIFYDS_H_INCLUDED
