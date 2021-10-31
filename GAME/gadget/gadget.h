#ifndef GADGET_H
#define GADGET_H

/* Waktu dari perishable item teratas dalam tas kembali ke durasi semula */
/*
  Required:
  - spek tas
*/
void KainPembungkusWaktu();
/* Memperbesar kapasitas tas menjadi dua kali lipat, tidak melebihi batas maksimum
kapasitas tas */
/*
  Required:
  - spek tas
*/
void SenterPembesar();
/* Berpindah ke lokasi yang diinginkan tanpa menambahkan unit waktu */
void PintuKemanaSaja();
/* Mengurangi waktu sebanyak 50 unit */
/*
  ** Pesanan yang masuk dalam jangka waktu 50 unit tersebut tidak akan hilang/kembali ke To Do List
  ** Tidak akan muncul kembali ke To Do List ketika waktu masuknya dilampaui lagi
*/
void MesinWaktu();

#endif