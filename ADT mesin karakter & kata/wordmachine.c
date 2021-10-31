#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordmachine.h"


boolean endWord;
Word currentWord;
boolean endWordfile;
Word currentWordfile;



void ignoreBlankWORD()
{
    while(currentChar == BLANK){
        adv();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void ignoreBlankWORDfile()
{
    while(currentCharfile == BLANK)  {
        advFile();
    }
}

void startWORD(){
    Word currentWord = {0, 0};
    start();
    ignoreBlankWORD();
    if (currentChar == MARK){
        endWord = true;
    } else
    {   
        endWord = false;
        copyWORD();
    }
}
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void startWORDfile(char filename[]){

    startfile(filename);
    ignoreBlankWORDfile();
    if (currentCharfile == MARK){
        endWordfile = true;
    } else
    {   
        endWordfile = false;
        copyWORDfile();
    }
}


void advWORD(){
    Word currentWord = {0, 0};
    ignoreBlankWORD();
    if (currentChar == MARK){
        endWord  = true;
    } else {
        copyWORD();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWORD */

void advWORDfile(){
    Word currentWordfile = {0, 0};
    ignoreBlankWORDfile();
    if (currentCharfile == MARK){
        endWordfile  = true;
    } else {
        copyWORDfile();
    }
}
void copyWORD()
{
    if (currentWord.length != 0)
    {
        memset (currentWord.contents, 0, strlen(currentWord.contents));
    }
    int count = 0;
    while((currentChar != MARK) && (currentChar != BLANK)){
        currentWord.contents[count] = currentChar;
        adv();
        count += 1;
    }
    if (count > CAPACITYWORD){
        currentWord.length = CAPACITYWORD;
    } else{
        currentWord.length = count;
    }
}

void copyWORDfile()
{
    if (currentWordfile.length != 0)
    {
        memset (currentWordfile.contents, 0, strlen(currentWordfile.contents));
    }
    int count = 0;
    while((currentCharfile != MARK) && (currentCharfile != BLANK)){
        currentWordfile.contents[count] = currentCharfile;
        advFile();
        count += 1;
    }
    if (count > CAPACITYWORD){
        currentWordfile.length = CAPACITYWORD;
    } else{
        currentWordfile.length = count;
    }
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

boolean isKataEqual(Word W1, Word W2)
{
    int i = 0;
    boolean flag = true;
    if (W1.length != W2.length)
    {
        flag = false;
    }
    else
    {
        while ((flag) && i < W1.length)
        {

            if (W1.contents[i] != W2.contents[i]) 
            {
                    flag = false;
            }
            i++;
        }
    }
    return flag;
}
