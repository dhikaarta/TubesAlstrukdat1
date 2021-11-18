#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pickup.h"

void pickUpAtloc(LOCATION currentloc, Stack *bag, List *in_progress, List *todo, TIME *t){
    /* KAMUS LOKAL */ 
    Address p; 
    boolean found;
    int i;
    ElTypeTASK newtask;
    ElTypeTASK viptask;
    /* ALGORITMA */
    
    if (IsFullSTACK(*bag)){ /* Tas sudah penuh maka pesanan tidak masuk ke dalam tas */
        printf("Tas sudah penuh. Tidak dapat pickup pesanan lagi\n");
    } else { /* Search apakah ada pesanan dalam qt dengan pickup location currentloc */
        if (isEmptyLINKEDLIST(*todo)){
            printf("Tidak ada pesanan pada Todo List!");
        } else {
            p = *todo;
            found = false;
            i = 0;
            /* Handle untuk VIP Item */
            if (ITEMTASK(p) == 'V'){
                while (ITEMTASK(p) == 'V' && !found){
                    if (INFO(p).pickUpTASK == currentloc.A){
                        found = true;
                    } else {
                        p = NEXT(p);
                        i++;
                    }
                }
                if (!found){
                    printf("Silahkan pick up item VIP terlebih dahulu. Shizuka menunggumu!\n");
                } else {
                    viptask = INFO(p);
                    insertFirstLINKEDLIST(in_progress, viptask);
                    PushBAG(bag, viptask);
                    deleteAtLINKEDLIST(todo, i, &newtask);
                    printf("Pesanan berupa");
                    processItemType(newtask);
                    printf("berhasil diambil!\n");
                    printf("Tujuan Pesanan: %c\n", newtask.dropOffTASK);
                }
            } 
            else { /* Untuk Non VIP Item */
                while (p != NULL && !found){
                    if (INFO(p).pickUpTASK == currentloc.A) {
                        found = true; 
                    } else {
                        p = NEXT(p);
                        i++;
                    }
                } 
                if (!found) {
                    printf("Tidak ada pesanan pada lokasi %c\n", currentloc.A);
                } else {
                    newtask = INFO(p);
                    insertFirstLINKEDLIST(in_progress, newtask); /*Update In-Progress List*/
                    PushBAG(bag, newtask); /* Insert item(task) to bag */
                    deleteAtLINKEDLIST(todo, i, &newtask); /* Detele todo list*/
                    
                    extern int moveFreq;

                    // JIKA PICK UP HEAVY ITEM, INCTIME + 1
                    if (newtask.itemTASK == 'H') {
                        (*t).incTime += 1;
                    }

                    // MENDISAKTIFKAN SPEED BOOST
                    if ((*t).incTime == 0.5 && newtask.itemTASK == 'H') {
                        printf("Ability Speed Boost telah hilang\n");
                        (*t).currentTime = floor((*t).currentTime);
                        (*t).incTime = 1;
                        moveFreq = 0;
                    }
                    
                    printf("Pesanan berupa");
                    processItemType(newtask);
                    printf("berhasil diambil!\n");
                    printf("Tujuan Pesanan: %c\n", newtask.dropOffTASK);
                }
            }
        }
        
    }
        
    
}