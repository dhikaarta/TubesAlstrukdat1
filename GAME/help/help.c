#include <stdio.h>
#include <stdlib.h>
void printHelp(){
    printf("1.  MOVE         -> Untuk berpindah ke lokasi selanjutnya\n");
    printf("2.  PICK_UP      -> Untuk mengambil item di lokasi sekarang\n");
    printf("3.  DROP_OFF     -> Untuk mengantar item di lokasi sekarang\n");
    printf("4.  MAP          -> Untuk memunculkan peta\n");
    printf("5.  TO_DO        -> Untuk menampilkan pesanan yang masuk ke To Do List\n");
    printf("6.  IN_PROGRESS  -> Untuk menampilkan pesanan yang sedang dikerjakan\n");
    printf("7.  BUY          -> Untuk menampilkan gadget yang dapat dibeli lalu membelinya (hanya dapat di headquarter)\n");
    printf("8.  INVENTORY    -> Untuk menampilkan list isi inventory\n");
    printf("9.  HELP         -> Untuk menampilkan seluruh command beserta deskripsi\n");
    printf("10. SAVE_GAME    -> Untuk melakukan save state permainan yang sedang dijalankan\n");
    printf("11. RETURN       -> Untuk mengembalikan item di tumpukan teratas pada tas kembali ke lokasi pick up jika Mobita memiliki ability Return To Sender.\n");
}