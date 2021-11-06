#include <stdio.h>
#include <stdlib.h>
#include "pickup.h"
#include "../../ADT Stack/bag.c"
#include "../../ADT Linked List/list_linked.c"
#include "../../ADT Linked List/node.c"

void pickUpAtloc(LOCATION currentloc, Stack *bag, List *in_progress, ListTASK todo){
    /* KAMUS LOKAL */ 
    int i;
    boolean found;
    /* ALGORITMA */
    
    if (IsFullSTACK(*bag)){ /* Tas sudah penuh maka pesanan tidak masuk ke dalam tas */
        printf("Tas sudah penuh. Tidak dapat pickup pesanan lagi\n");
    } else { /* Search apakah ada pesanan dalam qt dengan pickup location currentloc */
        i = 0;
        found = false; 
        while (i < lengthLISTTASK(todo) && !found){
            if (todo.contents[i].pickUpTASK == currentloc.A) {
                found = true; 
            } else {
                i++;
            }
        } 
        if (!found) {
            printf("Tidak ada pesanan pada lokasi");
        } else {
            ElTypeTASK newtask; 
            newtask = todo.contents[i];
            insertFirstLINKEDLIST(in_progress, newtask); /*Update In-Progress List*/
            PushBAG(bag, newtask); /* Insert item(task) to bag */
        }
    }
    
}