#include "list_linked.h"
#include "../ADT mesin karakter & kata/wordmachine.h"
#include <stdio.h>

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateLINKEDLIST(List *l)
{
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;
}
/****************** TEST LIST KOSONG ******************/
boolean isEmptyLINKEDLIST(List l)
{
    /* Mengirim true jika list kosong */
    return (FIRST(l) == NULL);
}
/****************** GETTER SETTER ******************/
ElTypeTASK getTASKLINKEDLIST(List l, int idx)
{
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengembalikan nilai pesanan l pada indeks idx */
    /* KAMUS LOKAL */
    Address p;
    int ctr;
    /* ALGORITMA */
    ctr = 0;
    p = l;
    while (ctr < idx)
    {
        ctr++;
        p = NEXT(p);
    } /* ctr = idx */
    return (INFO(p));
}

void setTASKLINKEDLIST(List *l, int idx, ElTypeTASK task)
{
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengubah pesanan pada indeks ke-idx menjadi task */
    /* KAMUS LOKAL */
    Address p;
    int ctr;
    /* ALGORITMA */
    ctr = 0;
    p = *l;
    while (ctr < idx)
    {
        ctr++;
        p = NEXT(p);
    } /* ctr = idx*/
    INFO(p) = task;
}
int indexOfLINKEDLIST(List l, ElTypeTASK task)
{
    /* I.S. l, task terdefinisi */
    /* F.S. Mencari apakah ada pesanan list l yang bernilai task */
    /* Jika ada, mengembalikan indeks pesanan pertama l yang bernilai task */
    /* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    /* KAMUS LOKAL */
    Address p;
    int idx;
    boolean found;
    /* ALGORITMA */
    p = l;
    idx = 0;
    found = false;
    while ((p != NULL) && !found)
    {
        if (TIMETASK(l) == task.timeTASK && PICKUPTASK(l) == task.pickUpTASK && DROPOFFTASK(l) == task.dropOffTASK && ITEMTASK(l) == task.itemTASK && TIMEEXPTASK(l) == task.timeExpTASK)
        {
            found = true;
        }
        else
        {
            idx++;
            p = NEXT(p);
        }
    } /*p == NULL or found */
    if (found)
    {
        return idx;
    }
    else
    {
        return IDX_UNDEF;
    }
}
void ReadLINKEDLISTTASKfile(List *l)
{
    /* BACA 1 pesanan TYPE DARI FILE */
    ElTypeTASK task;
    advWORDfile();
    task.timeTASK = atoi(currentWordfile.contents);
    advWORDfile();
    task.pickUpTASK = currentWordfile.contents[0];
    advWORDfile();
    task.dropOffTASK = currentWordfile.contents[0];
    advWORDfile();
    task.itemTASK = currentWordfile.contents[0];
    if (task.itemTASK == 'P')
    {
        advWORDfile();
        task.timeExpTASK = atoi(currentWordfile.contents);
    }
    insertLastLINKEDLIST(l, task);
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN pesanan ***/
void insertFirstLINKEDLIST(List *l, ElTypeTASK task)
{
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah pesanan dan */
    /* menambahkan pesanan pertama dengan pesanan jika alokasi berhasil. */
    /* Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS LOKAL */
    Address p;
    /* ALGORITMA */
    p = newNode(task);
    if (p != NULL)
    {
        NEXT(p) = *l;
        *l = p;
    }
}
void insertLastLINKEDLIST(List *l, ElTypeTASK task)
{
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah pesanan dan */
    /* menambahkan pesanan list di akhir: pesanan terakhir yang baru */
    /* bernilai task jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS LOKAL */
    Address p, last;
    /* ALGORITMA */
    if (isEmptyLINKEDLIST(*l))
    {
        insertFirstLINKEDLIST(l, task);
    }
    else
    {
        p = newNode(task);
        if (p != NULL)
        {
            last = *l;
            while (NEXT(last) != NULL)
            {
                last = NEXT(last);
            }
            /*NEXT(last) = NULL*/
            NEXT(last) = p;
        }
    }
}
void insertAtLINKEDLIST(List *l, ElTypeTASK task, int idx)
{
    /* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Melakukan alokasi sebuah pesanan dan */
    /* menyisipkan pesanan dalam list pada indeks ke-idx (bukan menimpa pesanan di i) */
    /* yang bernilai task jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS LOKAL */
    int ctr;
    Address p, loc;
    /* ALGORITMA */
    if (idx == 0)
    {
        insertFirstLINKEDLIST(l, task);
    }
    else
    {
        p = newNode(task);
        ctr = 0;
        loc = *l;
        while (ctr < idx - 1)
        {
            ctr += 1;
            loc = NEXT(loc);
        } /*ctr = idx-1 */
        NEXT(p) = NEXT(loc);
        NEXT(loc) = p;
    }
}
/*** PENGHAPUSAN PESANAN ***/
void deleteFirstLINKEDLIST(List *l, ElTypeTASK *task)
{
    /* I.S. List l tidak kosong  */
    /* F.S. Pesanan pertama list dihapus: nilai info disimpan pada x */
    /*      dan alamat pesanan pertama di-dealokasi */
    /* KAMUS LOKAL */
    Address p;
    /* ALGORITMA */
    p = *l;
    *task = INFO(p);
    *l = NEXT(p);
    free(p);
}
void deleteLastLINKEDLIST(List *l, ElTypeTASK *task)
{
    /* I.S. list tidak kosong */
    /* F.S. Pesanan terakhir list dihapus: nilai info disimpan pada x */
    /*      dan alamat pesanan terakhir di-dealokasi */
    /* KAMUS LOKAL */
    Address p, loc;
    /* ALGORITMA */
    p = *l;
    loc = NULL;
    while (NEXT(p) != NULL)
    {
        loc = p;
        p = NEXT(p);
    } /* NEXT(p) = NULL */
    if (loc == NULL)
    { /* Berarti cuman satu node */
        *l = NULL;
    }
    else
    {
        NEXT(loc) = NULL;
    }
    *task = INFO(p);
    free(p);
}
void deleteAtLINKEDLIST(List *l, int idx, ElTypeTASK *task)
{
    /* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. task diset dengan pesanan l pada indeks ke-idx. */
    /*      Pesanan l pada indeks ke-idx dihapus dari l */
    /* KAMUS LOKAL */
    Address p, loc;
    int ctr;
    /* ALGORITMA */
    if (idx == 0)
    {
        deleteFirstLINKEDLIST(l, task);
    }
    else
    {
        ctr = 0;
        loc = *l;
        while (ctr < idx - 1)
        {
            ctr += 1;
            loc = NEXT(loc);
        } /* ctr = idx-1*/
        p = NEXT(loc);
        *task = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}
/****************** PROSES SEMUA PESANAN LIST ******************/
void displayLINKEDLIST(List l)
{
    // void printInfo(List l);
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga pesanan bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    /* KAMUS LOKAL */
    Address p;
    int i;
    /* ALGORITMA */
    if (isEmptyLINKEDLIST(l))
    {
        printf("Tidak ada pesanan!\n");
    }
    else
    {
        p = FIRST(l);
        i = 0;
        while (p != NULL)
        {
            printf("%d. Time Task = %d\n", i + 1, TIMETASK(p));
            printf("   Pick Up Point = %c\n", PICKUPTASK(p));
            printf("   Drop Off Point = %c\n", DROPOFFTASK(p));
            printf("   Item Task = %c\n", ITEMTASK(p));
            if (ITEMTASK(p) == 'P')
            {
                printf("   Expired Time = %d\n", TIMEEXPTASK(p));
            }
            i++;
            p = NEXT(p);
        } /* p = NULL*/
    }
}

void displayToDoList(List l)
{
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, akan mencetak tempat pick up, drop off, dan
            jenis item yang harus diambil pada to do list */
    /* KAMUS LOKAL */
    Address p;
    int i;
    /* ALGORITMA */
    if (isEmptyLINKEDLIST(l))
    {
        printf("Tidak ada pesanan yang harus diambil!\n");
    }
    else
    {
        p = FIRST(l);
        i = 0;
        printf("Pesanan pada To Do List:\n");
        while (p != NULL)
        {
            printf("%d. %c -> %c ", i + 1, PICKUPTASK(p), DROPOFFTASK(p));
            if (ITEMTASK(p) == 'N')
            {
                printf("(Normal Item)");
            }
            if (ITEMTASK(p) == 'H')
            {
                printf("(Heavy Item)");
            }
            if (ITEMTASK(p) == 'P')
            {
                printf("(Perishable Item, sisa waktu %.1f)", TIMEEXPTASK(p));
            }
            if (ITEMTASK(p) == 'V')
            {
                printf("(VIP Item, Harus Segera Dilayani)");
            }
            printf("\n");
            i++;
            p = NEXT(p);
        } /* p = NULL*/
    }
}

int lengthLINKEDLIST(List l)
{
    /* Mengirimkan banyaknya pesanan list; mengirimkan 0 jika list kosong */
    /* KAMUS LOKAL */
    Address p;
    int ctr;
    /* ALGORITMA */
    if (isEmptyLINKEDLIST(l))
    {
        return 0;
    }
    else
    {
        p = l;
        ctr = 1;
        while (NEXT(p) != NULL)
        {
            ctr++;
            p = NEXT(p);
        } /*NEXT(p) == NULL */
        return ctr;
    }
}
List concatLINKEDLIST(List l1, List l2)
{
    /* I.S. l1 dan l2 sembarang */
    /* F.S. l3 adalah hasil konkatenasi l1 & l2 */
    /* Konkatenasi dua buah list : l1 dan l2    */
    /* menghasilkan l3 yang baru (dengan pesanan list l1 dan l2 secara berurutan). */
    /* Tidak ada alokasi/dealokasi pada prosedur ini */
    /* KAMUS LOKAL */
    Address p;
    List l3;
    int ctr;
    /* ALGORITMA */
    CreateLINKEDLIST(&l3);
    p = l1;
    while (p != NULL)
    {
        insertLastLINKEDLIST(&l3, INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while (p != NULL)
    {
        insertLastLINKEDLIST(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}
