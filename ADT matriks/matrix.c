#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "../ADT point/location.h"
#include "../ADT point/location.c"

void CreateMATRIX(int nRow, int nCol, Matrix *m)
{
    ROWSMATRIX(*m) = nRow;
    COLSMATRIX(*m) = nCol;

}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValidMATRIX(int i, int j)
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
    {
        return (i >= 0 && i < ROW_CAP_MATRIX && j >= 0 && j < COL_CAP_MATRIX);
    }
/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRowMATRIX(Matrix m)
/* Mengirimkan Index baris terbesar m */
{
    return(ROWSMATRIX(m)-1);
}
Index getLastIdxColMATRIX(Matrix m)
{
    return(COLSMATRIX(m)-1);
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEffMATRIX(Matrix m, Index i, Index j)
{
    return i < ROWSMATRIX(m)  && j < COLSMATRIX(m) && i>=0 && j >= 0;
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonalMATRIX(Matrix m, Index i)

{
    return ELMTMATRIX(m,i,i);
}
/* Mengirimkan elemen m(i,i) */



/* ********** Assignment  Matrix ********** */
void copyMATRIX(Matrix mIn, Matrix *mRes)
/* Melakukan assignment MRes = MIn */
{
    int i,j;
    CreateMATRIX(ROWSMATRIX(mIn), COLSMATRIX(mIn), mRes);
    for(i= 0; i <ROWSMATRIX(mIn); i++){
        for (j = 0; j<COLSMATRIX(mIn); j++){
            ELMTMATRIX(*mRes,i,j) = ELMTMATRIX(mIn,i,j);
        }
    } 
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMATRIX(Matrix *m, int nRow, int nCol)
{
    if (isIdxValidMATRIX(nRow,nCol)){
        int i,j;
        CreateMATRIX(nRow,nCol,m);
        for (i=0; i < ROWSMATRIX(*m); i++){
            for(j=0;j<COLSMATRIX(*m);j++){
                scanf("%d", &ELMTMATRIX(*m,i,j));
        }

        }
    }
}
/* I.S. isIdxValidMATRIX(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMATRIX(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMATRIX(Matrix m)
{
    int i,j;
    for(i= 0; i <ROWSMATRIX(m); i++){
        for (j = 0; j<COLSMATRIX(m); j++){
            if (j == getLastIdxRowMATRIX(m)){
                printf("%d", ELMTMATRIX(m,i,j));
            }else {
                printf("%d ", ELMTMATRIX(m,i,j));
            }
        }

         if (i < getLastIdxRowMATRIX(m)){
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
Matrix addMATRIX(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
{
    /* KAMUS */
    int i, j;
    Matrix m;

    /* ALGORITMA */
    CreateMATRIX(ROWSMATRIX(m1), COLSMATRIX(m1), &m);

    for (i = 0; i < ROWSMATRIX(m); i++) {
        for (j = 0; j < COLSMATRIX(m); j++) {
            ELMTMATRIX(m, i, j) = ELMTMATRIX(m1, i, j) + ELMTMATRIX(m2, i, j);
        }
    }
    
    return m;
}
Matrix subtractMATRIX(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
{
    /* KAMUS */
    int i, j;
    Matrix m;

    /* ALGORITMA */
    CreateMATRIX(ROWSMATRIX(m1), COLSMATRIX(m1), &m);

    for (i = 0; i < ROWSMATRIX(m); i++) {
        for (j = 0; j < COLSMATRIX(m); j++) {
            ELMTMATRIX(m, i, j) = ELMTMATRIX(m1, i, j) - ELMTMATRIX(m2, i, j);
        }
    }
    
    return m;
}
Matrix multiplyMATRIX(Matrix m1, Matrix m2)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
{
    /* KAMUS */
    int i, j, k;
    Matrix m;

    /* ALGORITMA */
    CreateMATRIX(ROWSMATRIX(m1), COLSMATRIX(m2), &m);

    for (i = 0; i < ROWSMATRIX(m1); i++) {
        for (j = 0; j < COLSMATRIX(m1); j++) {
            ELMTMATRIX(m,i,j) = 0;
            for(k=0; k< COLSMATRIX(m1); k++){
                ELMTMATRIX(m,i,j) += ELMTMATRIX(m1,i,k) * ELMTMATRIX(m2,k,j);
            }
        }
    }
    
    return m;
}
Matrix multiplyConstMATRIX(Matrix m, ElType x)
{
    int i,j;
    for (i = 0; i < ROWSMATRIX(m); i++) {
        for (j = 0; j < COLSMATRIX(m); j++) {
            ELMTMATRIX(m, i, j) = x * ELMTMATRIX(m,i,j);
        }
    }
    
    return m;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyConstMATRIX(Matrix *m, ElType k)
{
    copyMATRIX(multiplyConstMATRIX(*m,k), m);
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqualMATRIX(Matrix m1, Matrix m2)
{
    int i,j;
    i = 0;
    boolean flag = true;
    if (!isSizeEqualMATRIX(m1,m2)){
        flag = false;
    }else{
        while ((i<ROWSMATRIX(m1)) && flag){
            j = 0;
            while((j<COLSMATRIX(m1))&&flag){
                if (ELMTMATRIX(m1, i, j) != ELMTMATRIX(m2, i, j)){
                    flag = false;
                }
                j++;
            }
            i++;
        }
    }
    return flag;
}
/* Mengirimkan true jika m1 = m2, yaitu countMATRIX(m1) = countMATRIX(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxColMATRIX(m1) = getLastIdxColMATRIX(m2) */
boolean isNotEqualMATRIX(Matrix m1, Matrix m2)
{
    return !isEqualMATRIX(m1,m2);
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */

boolean isSizeEqualMATRIX(Matrix m1, Matrix m2)
{
    return COLSMATRIX(m1) == COLSMATRIX(m2) && ROWSMATRIX(m1) == ROWSMATRIX(m2);
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */

/* ********** Operasi lain ********** */
int countMATRIX(Matrix m)
{
    return COLSMATRIX(m)*ROWSMATRIX(m);
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquareMATRIX(Matrix m)
{
    return ROWSMATRIX(m) == COLSMATRIX(m);
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetricMATRIX(Matrix m)
{
    boolean flag = true;
    int i,j;
    i = 0; 
    while ((i<ROWSMATRIX(m)) && flag){
        j= 0;
        while((j<COLSMATRIX(m))&&flag){
            if (ELMTMATRIX(m, i, j) != ELMTMATRIX(m, j, i))
            {
                flag = false;
            }
            j++;
            }
            i++;
        }
    return flag && isSquareMATRIX(m);
}
/* Mengirimkan true jika m adalah matriks simetri : isSquareMATRIX(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentityMATRIX(Matrix m)
{
    boolean flag = true;
    int i,j;
  
    if(!isSquareMATRIX(m)){
        flag = false;
    }
    else {
        i = 0;
        while ((i<ROWSMATRIX(m)) && flag){
            j = 0;
            while((j<COLSMATRIX(m))&&flag){
                if (i == j){
                    if (ELMTMATRIX(m,i,j)!=1){
                        flag = false;
                    }
                }
                else{
                    if(ELMTMATRIX(m,i,j) != 0){
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
    

/* Mengirimkan true jika m adalah matriks satuan: isSquareMATRIX(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparseMATRIX(Matrix m)
{
    double num = 0;
    int i,j;
    double max = countMATRIX(m) * 0.05;
    for (i = 0; i < ROWSMATRIX(m); i++) {
        for (j = 0; j < COLSMATRIX(m); j++) {
            if (ELMTMATRIX(m,i,j) != 0){
                num += 1;
            }
        }
    }
    return (num <= max);
}

/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix inverse1MATRIX(Matrix m){

    return multiplyConstMATRIX(m, -1);
}
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
void pInverse1MATRIX(Matrix *m){

    pMultiplyConstMATRIX(m, -1);
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
float determinantMATRIX(Matrix m)
{
    int i,j,k;
    float det =1;
    float per;
    float a[ROWSMATRIX(m)][COLSMATRIX(m)];
    for(i=0;i< COLSMATRIX(m);i++)
	 {
		  for(j=0;j< COLSMATRIX(m);j++)
		  {
			   
			   a[i][j] =  (float)ELMTMATRIX(m,i,j);
		  }
	 }
    
    for(i=0;i< COLSMATRIX(m);i++)
	 {	 
         if (a[i][i] == 0.0){
             return 0;
         }
		  for(j=i+1;j< COLSMATRIX(m);j++)
		  {
			   per = a[j][i]/a[i][i];

			   for(k=0;k< COLSMATRIX(m);k++)
			   {
			  		a[j][k] = a[j][k]  - (per * a[i][k]);
			   }
		  }
	 }
    for(i=0;i< COLSMATRIX(m);i++)
     {
         det = det * a[i][i];
     }
    return det;
}


/* Prekondisi: isSquareMATRIX(m) */
/* Menghitung nilai determinan m */
void transposeMATRIX(Matrix *m)
{
    /* KAMUS */
    int i, j, temp;
   

    /* ALGORITMA */

    for (i = 0; i < ROWSMATRIX(*m); i++) { 
        for (j = i; j <= COLSMATRIX(*m); j++) {
            temp = ELMTMATRIX(*m, i, j);
            ELMTMATRIX(*m, i, j) = ELMTMATRIX(*m, j, i);
            ELMTMATRIX(*m, j, i) = temp;
        }
    }
}
/* I.S. m terdefinisi dan isSquareMATRIX(m) */
/* F.S. m "di-transposeMATRIX", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

Matrix makeMatrixAdj(int L)
{
    Matrix Madj; int nRow = L + 1; int nCol = L + 1;
    int val;
    CreateMATRIX(nRow,nCol, &Madj);
    for(int i = 0;i < nRow;i++)
    {
        for(int j = 0; j< nCol;j++)
        {
            advWORDfile();
            val = atoi(currentWordfile.contents);
            ELMTMATRIX(Madj,i,j) = val;
        }
    }
   
    return Madj;
}