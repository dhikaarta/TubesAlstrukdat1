// Modul definisi fungsi dan prosedur untuk Gadget dan Inventory
#ifndef GADGET_INVENTORY_H
#define GADGET_INVENTORY_H

#include "../../ADT List Statis/listgadget.h"
#include "../gadget/gadget.h"
#include <stdio.h>
#include <stdlib.h>

ListGADGET initialGadgetStore();
/* Fungsi untuk membentuk List yang berisi gadget-gadget
   yang dijual pada Gadget Store */

void gadgetStore(ListGADGET listGadgetStore, ListGADGET *listInventory, long *money);
/* Proses: Menampilkan gadget dan harga yang dijual dari listGadgetStore
           Meminta pengguna memasukan input id Gadget yang akan dibeli hingga
           sesuai ketentuan (uang cukup, 0 > id Gadget < 5)
           Menambahkan gadget yang dibeli ke listInventory, atau tidak menambah apapun
           jika pengguna membatalkan pembelian (id Gadget = 0)
   I.S. listGadgetStore, listInventory, money terdefinisi
   F.S. listInventory dapat bertambah satu elemen atau tidak
        Jumlah money akan berkurang sesuai dengan harga gadget yang dibeli*/

void useInventory(ListGADGET *listInventory, Stack *b,TIME *t);
/* Proses: Menampilkan inventory user dari listInventory
           Meminta pengguna memasukkan id Inventory yang ingin digunakan sesuai
           ketentuan (id Inventory harus berisi gadget)
           Memanggil fungsi/prosedur untuk aktivasi gadget
    I.S. listInventory terdefinisi, boleh kosong
    F.S. listInventory dapat kosong (jika semua gadget telah digunakan)
         Memanggil fungsi untuk aktivasi gadget*/

#endif