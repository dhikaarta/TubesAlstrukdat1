/* File: charmachine.c */
/* Implementasi Character Engine */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
char currentCharfile;
boolean eot;

static FILE * tape;
static FILE * tapefile;
static int retval;
static int retvalfile;

void start() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	tape = stdin;
	adv();
}

void startfile(char fileName[])
{
   tapefile = fopen(fileName, "r");
   if(tapefile == NULL)
   {
      printf("ERROR ! FILE YANG DIMASUKKAN TIDAK DAPAT DITEMUKAN, MOHON CEK LAGI NAMA FILE DAN JANGAN LUPA DIAKHIRI DENGAN .txt\n");
      printf("TERMINASI PROGRAM !\n");
      exit(0);
      
   }
   advFile();
}


void adv() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
		      Jika  currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(tape,"%c",&currentChar);
	eot = (currentChar == MARK);

}

void advFile()
{
   retvalfile = fscanf(tapefile,"%c",&currentCharfile);
   
	if(retvalfile == EOF)
   {
      fclose(tapefile);
   }
   else
   {
      if(currentCharfile == '\n')
      {
         currentCharfile = ' ';
      }
   }
}