#include <stdio.h>
#include <stdlib.h>
#include "pickup.h"
#include "../../ADT Stack/bag.h"
#include "../../ADT Linked List/list_linked.h"
#include "../../ADT Linked List/node.h"
#include "../../ADT point/location.h"
#include "../in_progress/in_progress.h"
void pickUpAtloc(LOCATION currentloc, Stack *bag, List *in_progress, List *todo){
    /* KAMUS LOKAL */ 
    Address p; 
    boolean found;
    /* ALGORITMA */
    
    if (IsFullSTACK(*bag)){ /* Tas sudah penuh maka pesanan tidak masuk ke dalam tas */
        printf("Tas sudah penuh. Tidak dapat pickup pesanan lagi\n");
    } else { /* Search apakah ada pesanan dalam qt dengan pickup location currentloc */
        p = FIRST(*todo);
        found = false; 
        while (p != NULL && !found){
            if (INFO(p).pickUpTASK == currentloc.A) {
                found = true; 
            } else {
                p = NEXT(p);
            }
        } 
        if (!found) {
            printf("Tidak ada pesanan pada lokasi %c\n", currentloc.A);
        } else {
            ElTypeTASK newtask; 
            newtask = INFO(p);
            insertFirstLINKEDLIST(in_progress, newtask); /*Update In-Progress List*/
            PushBAG(bag, newtask); /* Insert item(task) to bag */
            deleteAtLINKEDLIST(todo, indexOfLINKEDLIST(*todo, newtask), &newtask);
            printf("Pesanan berupa");
            processItemType(newtask);
            printf("berhasil diambil!\n");
            printf("Tujuan Pesanan: %c\n", newtask.dropOffTASK);
        }
    }
    
}