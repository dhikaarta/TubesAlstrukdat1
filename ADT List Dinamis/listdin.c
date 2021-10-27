#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateLISTDIN(ListDin *l, int CAPACITY_LISTDIN){
/* I.S. l sembarang, CAPACITY_LISTDIN > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas CAPACITY_LISTDIN */
      BUFFER_LISTDIN(*l) = (ElType*) malloc(CAPACITY_LISTDIN * sizeof(ElType));
      NEFF_LISTDIN(*l) = 0;
      CAPACITY_LISTDIN(*l) = CAPACITY_LISTDIN;
}

void dealocateLISTDIN(ListDin *l){
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY_LISTDIN(l)=0; NEFF_LISTDIN(l)=0 */
      free(BUFFER_LISTDIN(*l));
      NEFF_LISTDIN(*l) = 0;
      CAPACITY_LISTDIN(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthLISTDIN(ListDin l){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
      return(NEFF_LISTDIN(l));
}

/* *** Selektor INDEKS *** */
IdxType getLastIdxLISTDIN(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
      return(NEFF_LISTDIN(l)-1);
};

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidLISTDIN(ListDin l, int i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
      return i>=0 &&i<CAPACITY_LISTDIN(l); 
};
boolean isIdxEffLISTDIN(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF_LISTDIN(l) */
      return i>=0 &&i<NEFF_LISTDIN(l); 
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyLISTDIN(ListDin l){
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
      return lengthLISTDIN(l) == 0;

}
boolean isFullLISTDIN(ListDin l){
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
      return NEFF_LISTDIN(l) == CAPACITY_LISTDIN(l); 
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListLISTDIN(ListDin *l){
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY_LISTDIN(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY_LISTDIN(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
      int n, i;
      scanf("%d",&n);
      while (n < 0 || n > CAPACITY_LISTDIN(*l)){
            scanf("%d",&n);
      };
      NEFF_LISTDIN(*l) = n;
      for (i=0; i<n; i++){
            scanf("%d", &ELMT_LISTDIN(*l, i));
      }
}
void displayListLISTDIN(ListDin l){
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
      int i;
      if (lengthLISTDIN(l) == 0){
        printf("[]");
      }else{
        printf("[");
        for(i = 0;i<lengthLISTDIN(l);i++){
            if (i!=lengthLISTDIN(l)-1){
                printf("%d,",ELMT_LISTDIN(l,i));
            }else{
                printf("%d]",ELMT_LISTDIN(l,i));
            }
      }
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusListLISTDIN(ListDin l1, ListDin l2, boolean plus){
/* Prekondisi : l1 dan l2 memiliki NEFF_LISTDIN sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
      int i;
      ListDin l;
      CreateLISTDIN(&l,NEFF_LISTDIN(l1));
      NEFF_LISTDIN(l) = NEFF_LISTDIN(l1);
      if (plus){
            for (i=0; i<NEFF_LISTDIN(l1);i++){
                  ELMT_LISTDIN(l,i) = ELMT_LISTDIN(l1, i) + ELMT_LISTDIN(l2,i);
            }
      }else{
            for (i=0; i<NEFF_LISTDIN(l1);i++){
                  ELMT_LISTDIN(l,i) = ELMT_LISTDIN(l1,i) - ELMT_LISTDIN(l2,i);
            }  
      }
      return l;

}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqualLISTDIN(ListDin l1, ListDin l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika NEFF_LISTDIN l1 = l2 dan semua elemennya sama */
      int i;
      if(lengthLISTDIN(l1)==lengthLISTDIN(l2)){
            for (i=0; i<lengthLISTDIN(l1); i++){
                  if (ELMT_LISTDIN(l1, i) != ELMT_LISTDIN(l2, i)){
                        return false;
                  }
            }
            return true;
      }else{
            return false;
      }
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOfLISTDIN(ListDin l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
      int i;
      if (isEmptyLISTDIN(l)){
            return IDX_UNDEF;
      }else{
            for (i = 0; i < lengthLISTDIN(l); i++)
            {
                  if (val == ELMT_LISTDIN(l,i)){
                        return i;
                  }
            }
            return IDX_UNDEF;
      }
};

/* ********** NILAI EKSTREM ********** */
void extremesLISTDIN(ListDin l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
      int i;
      *max = ELMT_LISTDIN(l, 0);
      *min = ELMT_LISTDIN(l, 0);
      for (i = 1; i < lengthLISTDIN(l); i++)
      {     
            if (ELMT_LISTDIN(l,i)>*max){
                  *max = ELMT_LISTDIN(l,i);
            }if (ELMT_LISTDIN(l,i)<*min){
                  *min = ELMT_LISTDIN(l,i);
            }
      }
      
}

/* ********** OPERASI LAIN ********** */
void copyListLISTDIN(ListDin lIn, ListDin *lOut){
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, NEFF_LISTDIN dan CAPACITY_LISTDIN sama) */
/* Proses : Menyalin isi lIn ke lOut */
      int i;
      CreateLISTDIN(lOut,CAPACITY_LISTDIN(lIn));
      NEFF_LISTDIN(*lOut) = NEFF_LISTDIN(lIn);
      for ( i = 0; i<NEFF_LISTDIN(lIn); i++){
            ELMT_LISTDIN(*lOut, i) = ELMT_LISTDIN(lIn, i);
      } 

}
ElType sumListLISTDIN(ListDin l){
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
      int i, x = 0;
      if (NEFF_LISTDIN(l) == 0){
            return 0;
      }else{
            for(i=0; i<NEFF_LISTDIN(l); i++){
                  x = x + ELMT_LISTDIN(l, i);
            }
            return x;
      }
}
int countValLISTDIN(ListDin l, ElType val){
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
      int i, x = 0;
      if (isEmptyLISTDIN(l)){
            return 0;
      }else{
            for(i=0; i<NEFF_LISTDIN(l); i++){
                  if (ELMT_LISTDIN(l,i)==val){
                        x++;
                  }
            }
            return x;
      }
}
boolean isAllEvenLISTDIN(ListDin l){
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
    int i;
    for(i = 0;i<lengthLISTDIN(l);i++){
        if (ELMT_LISTDIN(l,i)%2!=0){
            return false;
        }
    }
    return true;
}

/* ********** SORTING ********** */
void sortLISTDIN(ListDin *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
      int i,temp;
      int unsorted_index = lengthLISTDIN(*l)-1;
      boolean sort = false;
      if (asc){
        while (sort == false){
        sort = true;
        for(i= 0; i<unsorted_index; i++){
            if (ELMT_LISTDIN(*l,i) > ELMT_LISTDIN(*l,i+1)){
                temp = ELMT_LISTDIN(*l,i+1);
                ELMT_LISTDIN(*l,i+1) = ELMT_LISTDIN(*l,i);
                ELMT_LISTDIN(*l,i) = temp;
                sort = false;
                }
            }
        unsorted_index--;
        }
      }else{
        while (sort == false){
        sort = true; 
        for(i= 0; i<unsorted_index; i++){   
            if (ELMT_LISTDIN(*l,i) < ELMT_LISTDIN(*l,i+1)){
                temp = ELMT_LISTDIN(*l,i+1);
                ELMT_LISTDIN(*l,i+1) = ELMT_LISTDIN(*l,i);
                ELMT_LISTDIN(*l,i) = temp;
                sort = false;
                }
            }
        unsorted_index--;
      }
   }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastLISTDIN(ListDin *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
      ELMT_LISTDIN(*l, NEFF_LISTDIN(*l)) = val;
      NEFF_LISTDIN(*l)+=1;
      
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastLISTDIN(ListDin *l, ElType *val){
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
      *val = ELMT_LISTDIN(*l, NEFF_LISTDIN(*l)-1);
      NEFF_LISTDIN(*l)--;
      // ListDin L;
      // NEFF_LISTDIN(L) = NEFF_LISTDIN(*l) - 1; 
      // CreateListDin(&L, CAPACITY_LISTDIN(*l));
      // int i;
      // for (i = 0; i <NEFF_LISTDIN(L); i++)
      // {
      //       ELMT_LISTDIN(L, i) = ELMT_LISTDIN(*l, i);
      // }
      // dealocateLISTDIN(l);
      // *l = L;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growListLISTDIN(ListDin *l, int num){
/* Proses : Menambahkan CAPACITY_LISTDIN l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
      int i;
      ListDin L;
      CreateLISTDIN(&L, CAPACITY_LISTDIN(*l)+ num);
      NEFF_LISTDIN(L) = NEFF_LISTDIN(*l);
      for(i = 0 ;i < NEFF_LISTDIN(L) ; i++){
        ELMT_LISTDIN(L,i) = ELMT_LISTDIN(*l,i);
      }
      dealocateLISTDIN(l);
      *l = L;
}

void shrinkListLISTDIN(ListDin *l, int num){
/* Proses : Mengurangi CAPACITY_LISTDIN sebanyak num */
/* I.S. List sudah terdefinisi, ukuran CAPACITY_LISTDIN > num, dan NEFF_LISTDIN < CAPACITY_LISTDIN - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
      int i;
      ListDin L;
      CreateLISTDIN(&L, CAPACITY_LISTDIN(*l) - num);
      NEFF_LISTDIN(L) = NEFF_LISTDIN(*l);
      for(i = 0 ;i < NEFF_LISTDIN(L) ; i++){
        ELMT_LISTDIN(L,i) = ELMT_LISTDIN(*l,i);
      }
      dealocateLISTDIN(l);
      *l = L;
}

void compactListLISTDIN(ListDin *l){
/* Proses : Mengurangi CAPACITY_LISTDIN sehingga NEFF_LISTDIN = CAPACITY_LISTDIN */
/* I.S. List lidak kosong */
/* F.S. Ukuran NEFF_LISTDIN = CAPACITY_LISTDIN */
      int i;
      ListDin L;
      CreateLISTDIN(&L, NEFF_LISTDIN(*l));
      NEFF_LISTDIN(L) = NEFF_LISTDIN(*l);
      for(i = 0 ;i < NEFF_LISTDIN(L) ; i++){
            ELMT_LISTDIN(L,i) = ELMT_LISTDIN(*l,i);
      }
      dealocateLISTDIN(l);
      *l = L;
}