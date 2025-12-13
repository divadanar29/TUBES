🎵 Listify.DS

📌DESKRIPSI PROYEK

Listify.DS adalah aplikasi pemutar musik berbasis terminal yang dikembangkan menggunakan bahasa pemrograman C++. Aplikasi ini dirancang sebagai simulasi sistem pemutar musik yang memungkinkan pengguna mengelola lagu, memutar musik, membuat dan mengatur playlist, mencari lagu, menggunakan antrian lagu, hingga melihat daftar favorit. Sistem ini juga menyediakan fitur admin untuk menambah, mengubah, dan menghapus lagu pada library utama.

Aplikasi ini cocok untuk mahasiswa yang mempelajari struktur data seperti Pointer, Doubly Linked List, Multi Linked List, Queue, dan Stack, atau siapa saja yang ingin memahami simulasi dasar aplikasi musik.

✨ FITUR – FITUR PROGRAM

📚 1. Library Lagu

Library adalah pusat data seluruh lagu yang disimpan menggunakan Doubly Linked List (DLL).

Struktur Data:
Doubly Linked List (DLL), digunakan untuk menyimpan seluruh lagu dalam library.

Setiap node (NodeLibrary) menyimpan:

1. Data lagu (Song)

2. Pointer next

3. Pointer prev

Library memudahkan traversal maju-mundur dan manajemen data yang dinamis.

Fitur yang ditampilkan:

a. ID Lagu

b. Judul

c. Artis

d. Genre

e. Tahun

f. Durasi

Fungsi terkait:
showAllSongs()

Proses Input:
Menu User → Menu Library → Lihat Semua Lagu

🔍 2. Cari Lagu

Struktur Data:
Doubly Linked List (Library)

Pencarian menggunakan Sequential Search, karena data berbentuk DLL yang tidak terurut sehingga pencarian paling efektif dilakukan secara linear.

Mode pencarian:

1. Berdasarkan ID

2. Berdasarkan Judul

3. Berdasarkan Artis

4. Berdasarkan Genre

5. Berdasarkan Tahun

Fungsi terkait:
searchSong()

Proses Input:
Menu Library → Cari Lagu → Pilih mode → Masukkan kata kunci

▶️ 3. Play Lagu

Struktur Data:
Pointer ke node lagu yang sedang aktif (CurrentPlay → songPtr).

Yang ditampilkan:

1. Judul lagu

2. Artis

3. playCount bertambah

Fungsi terkait:

a. playSong() – memutar dari library

b. playFromPlaylist() – memutar dari playlist

Proses Input:
Menu Library → Play Lagu → Masukkan ID

⏹️ 4. Stop Lagu

Menghentikan lagu yang sedang berjalan dengan mengatur status isPlaying menjadi false.

Fungsi terkait:
stopSong()

Proses Input:
Menu Library → Stop

⏭️ 5. Next Lagu

Perpindahan lagu dilakukan melalui:

1. Jika dari playlist:
Menggunakan struktur Playlist (DLL) sehingga langsung berpindah ke node playlist berikutnya.

2. Jika dari library:
Mencari lagu dengan artis atau genre yang sama melalui traversal DLL Library.

Fungsi terkait:
nextSong(), findSimilarSong()

Proses Input:
Menu Library → Next Lagu

⏮️ 6. Previous Lagu

Menggunakan Stack (LIFO) sebagai riwayat pemutaran. Setiap lagu yang diputar akan disimpan ke stack, lalu ketika memilih prev akan dilakukan operasi pop.

Fungsi terkait:
prevSong(), push(), pop()

Proses Input:
Menu Library → Prev Lagu

🎼 7. Playlist

Struktur Data:

a. Multi Linked List (MLL) untuk menyimpan banyak playlist dalam satu user

Satu user → banyak playlist (MLL tipe A)

b. Doubly Linked List (DLL) untuk isi playlist

Setiap node playlist (NodePlaylist) menyimpan pointer ke node library (tanpa duplikasi data lagu)

Playlist memungkinkan manajemen koleksi lagu yang dinamis dan fleksibel.

📂 7.1. Show Semua Playlist

Struktur Data: Traversal MLL untuk menampilkan seluruh playlist user.

Fungsi terkait: Traversal firstPlaylist

➕ 7.2. Create Playlist

Deskripsi: Menambah playlist baru ke MLL pengguna (insert node playlist baru)

Fungsi terkait: addPlaylistToUser()

Proses Input: Menu Playlist → Create Playlist → Masukkan nama

📃 7.3. Show Playlist

Deskripsi: Menampilkan isi playlist (DLL pointer ke Library) 

Fungsi terkait: showPlaylist()

🎶 7.4. Add Lagu ke Playlist

Deskripsi: Menambahkan node playlist baru berisi pointer ke node Library.

Fungsi terkait: addSongToPlaylist()

Proses Input: Pilih playlist → Masukkan ID lagu

🎛️ 7.5. Playlist Controls

Meliputi: Play, Stop, Next, Prev

Menggunakan:

a. Pointer currentPlaylist → untuk tracking posisi pemutaran

b. Pointer ke DLL Library → untuk memutar lagu

Fungsi terkait: playFromPlaylist(), nextSong()

✏️ 7.6. Rename Playlist

Deskripsi: Mengubah nama playlist via MLL traversal.

Fungsi terkait: renamePlaylist()

🗑️ 7.7. Hapus Playlist

Deskripsi: Menghapus node playlist dari MLL user, DLL playlist terhapus otomatis (relasi pointer dilepas)

Fungsi terkait: deletePlaylist()

❌ 7.8. Remove Lagu dari Playlist

Deskripsi: Menghapus node dalam DLL playlist.

Fungsi terkait: removeSongFromPlaylist()


📥 8. Antrian Lagu
   
Struktur Data: Queue (FIFO), implementasi dengan linked list (QueueNode). Digunakan untuk menjalankan lagu berdasarkan urutan penambahan.

Fitur:
1. Menambahkan lagu ke antrian
2. Menampilkan antrian
3. Memutar lagu dari antrian

Fungsi terkait:
enqueue(), dequeue(), showQueue()

Proses Input:
Menu Antrian Lagu → Tambah Lagu → Putar

⭐ 9. Favorite Lagu
   
Setiap lagu memiliki atribut favorite (boolean) pada node DLL Library, sehingga penandaan favorit hanya mengubah status pada node tanpa membuat struktur baru.

9.1. Tandai Lagu sebagai Favorit

Deskripsi: Mengubah favorite = true pada node lagu tertentu.

Fungsi terkait: markFavoriteById()

Proses input: Menu User → Pilih “Favorite Lagu” → Pilih 1. Tandai Lagu Favorit → Masukkan ID lagu

9.2. Hapus Tanda Favorit

Deskripsi: Mengubah favorite = false pada node lagu tertentu.

Fungsi terkait: unmarkFavoriteById()

Proses input: Menu User → Favorite Lagu → Pilih 2. Hapus Favorite → Masukkan ID lagu

9.3. Lihat Semua Lagu Favorit

Deskipsi: Menampilkan seluruh lagu yang memiliki favorite = true (dilakukan lewat traversal pada DLL Library).

Fungsi terkait: showFavoriteSongs()

Proses input: Menu User → Favorite Lagu → Pilih 3. Lihat Daftar Favorite



🔀 10. Shuffle Mode

Struktur Data: Doubly Linked List (Library) untuk mengambil satu lagu secara acak, lalu langsung memutarnya sebagai CurrentPlay. 

Fungsi terkait:

a. getRandomSong() – mengambil satu node lagu secara acak

b. shufflePlayLibrary() – memutar lagu hasil shuffle

Proses Input: Menu User → Pilih Shuffle Play



🔥 11. Top Played

Menampilkan lagu dengan jumlah playCount tertinggi.

Fungsi terkait:
showMostPlayed()

Proses input: Menu User → Pilih Top Played

🛠️ 12. Admin Mode

Struktur Data: Admin melakukan manipulasi langsung pada DLL Library.

Fitur:
a. Tambah Lagu → addSong()

b. Update Lagu → updateSong()

c. Hapus Lagu → deleteSong()

d. Lihat Semua Lagu → showAllSongs()


🔐 13. Login User

Struktur Data: 
Semua user disimpan dalam MLL tipe A:
a. User disimpan dalam DLL
b. Setiap user menyimpan MLL playlist

Fungsi terkait: findUser(), verifyUserPassword(), setUserPassword()

Proses input: Halaman Awal → Masukkan username → Masukkan password

🚪 14. Exit

Menutup aplikasi.

Proses Input:
Menu Utama → Pilih 0
