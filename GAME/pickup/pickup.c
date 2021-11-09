#include <stdio.h>
#include <stdlib.h>
#include "pickup.h"
#include "../../ADT Stack/bag.h"
#include "../../ADT Linked List/list_linked.h"
#include "../../ADT Linked List/node.h"
#include "../../ADT point/location.h"
#include "../in_progress/in_progress.h"
#include "../ability/ability.h"
void pickUpAtloc(LOCATION currentloc, Stack *bag, List *in_progress, List todo, TIME *t){
    /* KAMUS LOKAL */ 
    Address p; 
    boolean found;
    /* ALGORITMA */
    
    if (IsFullSTACK(*bag)){ /* Tas sudah penuh maka pesanan tidak masuk ke dalam tas */
        printf("Tas sudah penuh. Tidak dapat pickup pesanan lagi\n");
    } else { /* Search apakah ada pesanan dalam qt dengan pickup location currentloc */
        p = FIRST(todo);
        found = false; 
        while (p != NULL && !found){
            if (INFO(todo).pickUpTASK == currentloc.A) {
                found = true; 
            } else {
                p = NEXT(p);
            }
        } 
        if (!found) {
            printf("Tidak ada pesanan pada lokasi\n");
        } else {
            ElTypeTASK newtask; 
            newtask = INFO(p);
            insertFirstLINKEDLIST(in_progress, newtask); /*Update In-Progress List*/
            PushBAG(bag, newtask); /* Insert item(task) to bag */
            
            // MENDISAKTIFKAN SPEED BOOST
            extern int moveFreq;
            if ((*t).incTime == 0.5) {
                moveFreq = 10;
                speedBoost(t, moveFreq);
            }
            
            printf("Pesanan berupa");
            processItemType(newtask);
            printf("berhasil diambil!\n");
            printf("Tujuan Pesanan: %c\n", newtask.dropOffTASK);
        }
    }
    
}