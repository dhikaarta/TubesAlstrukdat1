#ifndef POINT_H
#define POINT_H

#include "../boolean.h"

typedef struct { 
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

typedef struct { 
	char* A;
    POINT B; 
} LOCATION;


#define CHAR(P) (P).A
#define LOC_X(P) (P).B.X
#define LOC_Y(P) (P).B.Y
        
LOCATION MakeLOCATION (char* A, float X, float Y);
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaLOCATION (LOCATION* p); 
void BacaLOCATIONfile (LOCATION* p);
void TulisLOCATION (LOCATION P);   
LOCATION* makeArrayOfLOCATION(int n);
void displaylistLOCATION(LOCATION* Loc, int L);


#endif