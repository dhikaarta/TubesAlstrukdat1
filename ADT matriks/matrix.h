/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef Matrix_H
#define Matrix_H

#include "..\boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define ROW_CAP_MATRIX 100
#define COL_CAP_MATRIX 100

typedef int Index; /* Index baris, kolom */
typedef int ElType;
typedef struct
{
   ElType contents[ROW_CAP_MATRIX][COL_CAP_MATRIX];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP_MATRIX-1][0..COL_CAP_MATRIX-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMATRIX(int nRow, int nCol, Matrix *m);
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROWSMATRIX(M) (M).rowEff
#define COLSMATRIX(M) (M).colEff
#define ELMTMATRIX(M, i, j) (M).contents[(i)][(j)]

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValidMATRIX(int i, int j);
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRowMATRIX(Matrix m);
/* Mengirimkan Index baris terbesar m */
Index getLastIdxColMATRIX(Matrix m);
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEffMATRIX(Matrix m, Index i, Index j);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonalMATRIX(Matrix m, Index i);
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMATRIX(Matrix mIn, Matrix *mRes);
/* Melakukan assignment MRes = MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMATRIX(Matrix *m, int nRow, int nCol);
/* I.S. isIdxValidMATRIX(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMATRIX(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMATRIX(Matrix m);
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
Matrix addMATRIX(Matrix m1, Matrix m2);
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMATRIX(Matrix m1, Matrix m2);
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMATRIX(Matrix m1, Matrix m2);
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyConstMATRIX(Matrix m, ElType x);
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyConstMATRIX(Matrix *m, ElType k);
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqualMATRIX(Matrix m1, Matrix m2);
/* Mengirimkan true jika m1 = m2, yaitu countMATRIX(m1) = countMATRIX(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxColMATRIX(m1) = getLastIdxColMATRIX(m2) */
boolean isNotEqualMATRIX(Matrix m1, Matrix m2);
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isSizeEqualMATRIX(Matrix m1, Matrix m2);
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */

/* ********** Operasi lain ********** */
int countMATRIX(Matrix m);
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquareMATRIX(Matrix m);
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetricMATRIX(Matrix m);
/* Mengirimkan true jika m adalah matriks simetri : isSquareMATRIX(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentityMATRIX(Matrix m);
/* Mengirimkan true jika m adalah matriks satuan: isSquareMATRIX(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparseMATRIX(Matrix m);
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix inverse1MATRIX(Matrix m);
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
void pInverse1MATRIX(Matrix *m);
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
float determinantMATRIX(Matrix m);
/* Prekondisi: isSquareMATRIX(m) */
/* Menghitung nilai determinan m */
void transposeMATRIX(Matrix *m);
/* I.S. m terdefinisi dan isSquareMATRIX(m) */
/* F.S. m "di-transposeMATRIX", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

#endif