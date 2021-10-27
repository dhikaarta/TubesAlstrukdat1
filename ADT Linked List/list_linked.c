#include "list_linked.h"
#include <stdio.h>

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateLINKEDLIST(List *l){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;
}
/****************** TEST LIST KOSONG ******************/
boolean isEmptyLINKEDLIST(List l){
/* Mengirim true jika list kosong */
    return (FIRST(l) == NULL); 
}
/****************** GETTER SETTER ******************/
ElType getElmtLINKEDLIST(List l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
/* KAMUS LOKAL */
    Address p; 
    int ctr; 
/* ALGORITMA */ 
    ctr = 0; 
    p = l;
    while (ctr < idx){
        ctr++; 
        p = NEXT(p);
    } /* ctr = idx */
    return (INFO(p));
}

void setElmtLINKEDLIST(List *l, int idx, ElType val){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
/* KAMUS LOKAL */
    Address p; 
    int ctr;
/* ALGORITMA */
    ctr = 0;
    p = *l; 
    while (ctr < idx){
        ctr++;
        p = NEXT(p);
    } /* ctr = idx*/
    INFO(p) = val;

}
int indexOfLINKEDLIST(List l, ElType val){
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
/* KAMUS LOKAL */
    Address p; 
    int idx; 
    boolean found; 
/* ALGORITMA */
    p = l;
    idx = 0; 
    found = false;
    while ((p != NULL) && !found){
        if (INFO(p) == val){
            found = true;
        } else {
            idx++;
            p = NEXT(p);
        }
    } /*p == NULL or found */
    if (found){
        return idx;
    } else {
        return IDX_UNDEF;
    }
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstLINKEDLIST(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
/* KAMUS LOKAL */
    Address p; 
/* ALGORITMA */ 
    p = newNode(val);
    if (p != NULL){
        NEXT(p) = *l; 
        *l = p; 
    }
}
void insertLastLINKEDLIST(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
/* KAMUS LOKAL */
    Address p, last; 
/* ALGORITMA */
    if (isEmptyLINKEDLIST(*l)){
        insertFirstLINKEDLIST(l, val);
    }
    else {
        p = newNode(val);
        if (p != NULL){
            last = *l; 
            while (NEXT(last) != NULL){
                last = NEXT(last);
            }
            /*NEXT(last) = NULL*/
            NEXT(last) = p;
        }
    }
}
void insertAtLINKEDLIST(List *l, ElType val, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
/* KAMUS LOKAL */
    int ctr; 
    Address p, loc; 
/* ALGORITMA */
    if (idx == 0){
        insertFirstLINKEDLIST(l, val);
    } else {
        p = newNode(val);
        ctr = 0;
        loc = *l; 
        while (ctr < idx-1) {
            ctr+=1; 
            loc = NEXT(loc);
        } /*ctr = idx-1 */
        NEXT(p) = NEXT(loc);
        NEXT(loc) = p;
    }

}
/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstLINKEDLIST(List *l, ElType *val){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
/* KAMUS LOKAL */
    Address p; 
/* ALGORITMA */   
    p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
}
void deleteLastLINKEDLIST(List *l, ElType *val){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
/* KAMUS LOKAL */
    Address p, loc; 
/* ALGORITMA */
    p = *l; 
    loc = NULL;
    while (NEXT(p)!= NULL){
        loc = p;
        p = NEXT(p);
    } /* NEXT(p) = NULL */
    if (loc == NULL){ /* Berarti cuman satu node */ 
        *l = NULL;
    }
    else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}
void deleteAtLINKEDLIST(List *l, int idx, ElType *val){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
/* KAMUS LOKAL */
    Address p, loc; 
    int ctr;
/* ALGORITMA */
    if (idx == 0) {
        deleteFirstLINKEDLIST(l, val);
    } else {
        ctr = 0; 
        loc = *l; 
        while (ctr < idx-1) {
            ctr += 1;
            loc = NEXT(loc);
        } /* ctr = idx-1*/
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p); 
        free(p);
    }
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayLINKEDLIST(List l){
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
/* KAMUS LOKAL */
    Address p; 
/* ALGORITMA */
    if (isEmptyLINKEDLIST(l)){
        printf("[]");
    } else {
        p = l;
        printf("[");
        while (NEXT(p) != NULL){
            printf("%d,", INFO(p));
            p = NEXT(p);
        } /* NEXT(p) = NULL*/
        printf("%d]", INFO(p));
    }
}
int lengthLINKEDLIST(List l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
/* KAMUS LOKAL */
    Address p; 
    int ctr; 
/* ALGORITMA */
    if (isEmptyLINKEDLIST(l)){
        return 0; 
    } else {
        p = l;
        ctr = 0; 
        while (NEXT(p) != NULL){
            ctr++; 
            p = NEXT(p);
        } /*NEXT(p) == NULL */
        return ctr; 
    }
}
List concatLINKEDLIST(List l1, List l2){
/* I.S. l1 dan l2 sembarang */
/* F.S. l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
/* KAMUS LOKAL */
    Address p; 
    List l3;
    int ctr; 
/* ALGORITMA */
    CreateLINKEDLIST(&l3);
    p = l1; 
    while (p != NULL){
        insertLastLINKEDLIST(&l3, INFO(p));
        p = NEXT(p);
    } 
    p = l2; 
    while (p != NULL){
        insertLastLINKEDLIST(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3; 
}