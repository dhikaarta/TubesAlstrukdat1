#include "listpos.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateLISTPOS(ListPos *l){
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
    int i;
    for(i = 0;i<CAPACITY_LISTPOS;i++){
        ELMT_LISTPOS(*l,i) = VAL_UNDEF;
    }
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthLISTPOS(ListPos l){
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
    int i = 0;
    while (ELMT_LISTPOS(l,i) != VAL_UNDEF && i<CAPACITY_LISTPOS){
        i++;
    }
    return i;
}


/* ********** Test Indeks yang valid ********** */
boolean isIdxValidLISTPOS(ListPos l, int i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i<CAPACITY_LISTPOS && i>=0);
}
boolean isIdxEffLISTPOS(ListPos l, int i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..lengthLISTPOS(l)-1 */
    return i>=0 && i<lengthLISTPOS(l);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyLISTPOS(ListPos l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
    return lengthLISTPOS(l) == 0;
}
boolean isFullLISTPOS(ListPos l){;
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return lengthLISTPOS(l) == CAPACITY_LISTPOS;
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListLISTPOS(ListPos *l){
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
    CreateLISTPOS(l);
    int n,i;
    scanf("%d",&n);
    while (n<0 || n>CAPACITY_LISTPOS){
       scanf("%d",&n); 
    }
    for(i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        ELMT_LISTPOS(*l,i) = x;
    }
}
void displayListLISTPOS(ListPos l){
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
    int i;
    if (lengthLISTPOS(l) == 0){
        printf("[]");
    }else{
        printf("[");
        for(i = 0;i<lengthLISTPOS(l);i++){
            if (i!=lengthLISTPOS(l)-1){
                printf("%d,",ELMT_LISTPOS(l,i));
            }else{
                printf("%d]",ELMT_LISTPOS(l,i));
            }
        }
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTabLISTPOS(ListPos l1, ListPos l2, boolean plus){
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
       int i;
       ListPos l;
       CreateLISTPOS(&l);
       if (plus){
        for(i = 0;i<lengthLISTPOS(l1);i++){
            ELMT_LISTPOS(l,i) = ELMT_LISTPOS(l1,i)+ELMT_LISTPOS(l2,i);
           }
        }else{
        for(i = 0;i<lengthLISTPOS(l1);i++){
        ELMT_LISTPOS(l,i) = ELMT_LISTPOS(l1,i)-ELMT_LISTPOS(l2,i);
        }
    }
    return l;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqualLISTPOS(ListPos l1, ListPos l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
   int i;
   if(lengthLISTPOS(l1)==lengthLISTPOS(l2)){
       for (i=0; i<lengthLISTPOS(l1); i++){
           if (ELMT_LISTPOS(l1, i) != ELMT_LISTPOS(l2, i)){
               return false;
           }
       }
       return true;
   }else{
       return false;
   }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfLISTPOS(ListPos l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    int i;
    if (lengthLISTPOS(l)==0){
        return IDX_UNDEF;
    }else{
        for(i = 0;i<lengthLISTPOS(l);i++){
            if (val == ELMT_LISTPOS(l,i)){
                return i;
            }
        }
        return IDX_UNDEF;
    }
}

/* ********** NILAI EKSTREM ********** */
void extremesLISTPOS(ListPos l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
    int i;
    *max= ELMT_LISTPOS(l,0);
    *min= ELMT_LISTPOS(l,0);
    for(i = 0;i<lengthLISTPOS(l);i++){
        if (*max<ELMT_LISTPOS(l,i)){
            *max=ELMT_LISTPOS(l,i);
        }
        if (*min>ELMT_LISTPOS(l,i)){
            *min=ELMT_LISTPOS(l,i);
        }
    }

}

/* ********** OPERASI LAIN ********** */
boolean isAllEvenLISTPOS(ListPos l){
/* Menghailkan true jika semua elemen l genap */
    int i;
    for(i = 0;i<lengthLISTPOS(l);i++){
        if (ELMT_LISTPOS(l,i)%2!=0){
            return false;
        }
    }
    return true;
}

/* ********** SORTING ********** */
void sortLISTPOS(ListPos *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
    int i,temp;
    int unsorted_index = lengthLISTPOS(*l)-1;
    boolean sort = false;
    if (asc){
        while (sort == false){
        sort = true;
        for(i= 0; i<unsorted_index; i++){
            if (ELMT_LISTPOS(*l,i) > ELMT_LISTPOS(*l,i+1)){
                temp = ELMT_LISTPOS(*l,i+1);
                ELMT_LISTPOS(*l,i+1) = ELMT_LISTPOS(*l,i);
                ELMT_LISTPOS(*l,i) = temp;
                sort = false;
                }
            }
        unsorted_index--;
        }
    }else{
        while (sort == false){
        sort = true; 
        for(i= 0; i<unsorted_index; i++){   
            if (ELMT_LISTPOS(*l,i) < ELMT_LISTPOS(*l,i+1)){
                temp = ELMT_LISTPOS(*l,i+1);
                ELMT_LISTPOS(*l,i+1) = ELMT_LISTPOS(*l,i);
                ELMT_LISTPOS(*l,i) = temp;
                sort = false;
                }
            }
        unsorted_index--;
        }
   }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastLISTPOS(ListPos *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
        ELMT_LISTPOS(*l, lengthLISTPOS(*l)) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastLISTPOS(ListPos *l, ElType *val){
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = ELMT_LISTPOS(*l, lengthLISTPOS(*l)-1);
    ELMT_LISTPOS(*l, lengthLISTPOS(*l)-1) = VAL_UNDEF;
}
