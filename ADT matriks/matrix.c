#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


void CreateMatrix(int nRow, int nCol, Matrix *m)
{
    ROWS(*m) = nRow;
    COLS(*m) = nCol;

}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
    {
        return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
    }
/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m)
/* Mengirimkan Index baris terbesar m */
{
    return(ROWS(m)-1);
}
Index getLastIdxCol(Matrix m)
{
    return(COLS(m)-1);
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, Index i, Index j)
{
    return i < ROWS(m)  && j < COLS(m) && i>=0 && j >= 0;
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, Index i)

{
    return ELMT(m,i,i);
}
/* Mengirimkan elemen m(i,i) */



/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes)
/* Melakukan assignment MRes = MIn */
{
    int i,j;
    CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
    for(i= 0; i <ROWS(mIn); i++){
        for (j = 0; j<COLS(mIn); j++){
            ELMT(*mRes,i,j) = ELMT(mIn,i,j);
        }
    } 
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
{
    if (isIdxValid(nRow,nCol)){
        int i,j;
        CreateMatrix(nRow,nCol,m);
        for (i=0; i < ROWS(*m); i++){
            for(j=0;j<COLS(*m);j++){
                scanf("%d", &ELMT(*m,i,j));
        }

        }
    }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m)
{
    int i,j;
    for(i= 0; i <ROWS(m); i++){
        for (j = 0; j<COLS(m); j++){
            if (j == getLastIdxRow(m)){
                printf("%d", ELMT(m,i,j));
            }else {
                printf("%d ", ELMT(m,i,j));
            }
        }

         if (i < getLastIdxRow(m)){
            printf("\n");
    } 
}
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
{
    /* KAMUS */
    int i, j;
    Matrix m;

    /* ALGORITMA */
    CreateMatrix(ROWS(m1), COLS(m1), &m);

    for (i = 0; i < ROWS(m); i++) {
        for (j = 0; j < COLS(m); j++) {
            ELMT(m, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    
    return m;
}
Matrix subtractMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
{
    /* KAMUS */
    int i, j;
    Matrix m;

    /* ALGORITMA */
    CreateMatrix(ROWS(m1), COLS(m1), &m);

    for (i = 0; i < ROWS(m); i++) {
        for (j = 0; j < COLS(m); j++) {
            ELMT(m, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    
    return m;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
{
    /* KAMUS */
    int i, j, k;
    Matrix m;

    /* ALGORITMA */
    CreateMatrix(ROWS(m1), COLS(m2), &m);

    for (i = 0; i < ROWS(m1); i++) {
        for (j = 0; j < COLS(m1); j++) {
            ELMT(m,i,j) = 0;
            for(k=0; k< COLS(m1); k++){
                ELMT(m,i,j) += ELMT(m1,i,k) * ELMT(m2,k,j);
            }
        }
    }
    
    return m;
}
Matrix multiplyConst(Matrix m, ElType x)
{
    int i,j;
    for (i = 0; i < ROWS(m); i++) {
        for (j = 0; j < COLS(m); j++) {
            ELMT(m, i, j) = x * ELMT(m,i,j);
        }
    }
    
    return m;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyConst(Matrix *m, ElType k)
{
    copyMatrix(multiplyConst(*m,k), m);
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2)
{
    int i,j;
    i = 0;
    boolean flag = true;
    if (!isSizeEqual(m1,m2)){
        flag = false;
    }else{
        while ((i<ROWS(m1)) && flag){
            j = 0;
            while((j<COLS(m1))&&flag){
                if (ELMT(m1, i, j) != ELMT(m2, i, j)){
                    flag = false;
                }
                j++;
            }
            i++;
        }
    }
    return flag;
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isNotEqual(Matrix m1, Matrix m2)
{
    return !isEqual(m1,m2);
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */

boolean isSizeEqual(Matrix m1, Matrix m2)
{
    return COLS(m1) == COLS(m2) && ROWS(m1) == ROWS(m2);
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */

/* ********** Operasi lain ********** */
int count(Matrix m)
{
    return COLS(m)*ROWS(m);
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
{
    return ROWS(m) == COLS(m);
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m)
{
    boolean flag = true;
    int i,j;
    i = 0; 
    while ((i<ROWS(m)) && flag){
        j= 0;
        while((j<COLS(m))&&flag){
            if (ELMT(m, i, j) != ELMT(m, j, i))
            {
                flag = false;
            }
            j++;
            }
            i++;
        }
    return flag && isSquare(m);
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m)
{
    boolean flag = true;
    int i,j;
  
    if(!isSquare(m)){
        flag = false;
    }
    else {
        i = 0;
        while ((i<ROWS(m)) && flag){
            j = 0;
            while((j<COLS(m))&&flag){
                if (i == j){
                    if (ELMT(m,i,j)!=1){
                        flag = false;
                    }
                }
                else{
                    if(ELMT(m,i,j) != 0){
                        flag = false;
                        }
                    }
                j++; 

                }

            i++;    
            }

        }

    return flag;
 }
    

/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m)
{
    double num = 0;
    int i,j;
    double max = count(m) * 0.05;
    for (i = 0; i < ROWS(m); i++) {
        for (j = 0; j < COLS(m); j++) {
            if (ELMT(m,i,j) != 0){
                num += 1;
            }
        }
    }
        return (num <= max);
}

/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix inverse1(Matrix m){

    return multiplyConst(m, -1);
}
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
void pInverse1(Matrix *m){

    pMultiplyConst(m, -1);
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
float determinant(Matrix m)
{
    int i,j,k;
    float det =1;
    float per;
    float a[ROWS(m)][COLS(m)];
    for(i=0;i< COLS(m);i++)
	 {
		  for(j=0;j< COLS(m);j++)
		  {
			   
			   a[i][j] =  (float)ELMT(m,i,j);
		  }
	 }
    
    for(i=0;i< COLS(m);i++)
	 {	 
         if (a[i][i] == 0.0){
             return 0;
         }
		  for(j=i+1;j< COLS(m);j++)
		  {
			   per = a[j][i]/a[i][i];

			   for(k=0;k< COLS(m);k++)
			   {
			  		a[j][k] = a[j][k]  - (per * a[i][k]);
			   }
		  }
	 }
    for(i=0;i< COLS(m);i++)
     {
         det = det * a[i][i];
     }
    return det;
}


/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
void transpose(Matrix *m)
{
    /* KAMUS */
    int i, j, temp;
   

    /* ALGORITMA */

    for (i = 0; i < ROWS(*m); i++) { 
        for (j = i; j <= COLS(*m); j++) {
            temp = ELMT(*m, i, j);
            ELMT(*m, i, j) = ELMT(*m, j, i);
            ELMT(*m, j, i) = temp;
        }
    }
}
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */