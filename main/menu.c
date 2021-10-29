#include <stdio.h>
#include <stdlib.h>
#include "../ADT mesin karakter & kata/wordmachine.h"
#include "../ADT mesin karakter & kata/wordmachine.c"
#include "../ADT mesin karakter & kata/charmachine.h"
#include "../ADT mesin karakter & kata/charmachine.c"

Word kataNewGame = {"NEWGAME", 7};  Word kataExit = {"EXIT", 4};
Word kataMove = {"MOVE", 4};    Word kataPickUp = {"PICK_UP", 7};    Word kataDropOff = {"DROP_OFF", 8};
Word kataMap = {"MAP", 3};    Word kataToDo = {"TO_DO", 5};    Word kataInProgress = {"IN_PROGRESS", 11};
Word kataBuy = {"BUY", 3};    Word kataInventory = {"INVENTORY", 9};    Word kataHelp = {"HELP", 4};

Word getInput()
{
    startWORD();
        Word kataInput;
        //printf("%s\n", currentWord.contents);
        kataInput.length = currentWord.length;
        for (int i =0; i < currentWord.length; i++)
        {
            kataInput.contents[i] = currentWord.contents[i];
        }
        //printf("%s\n", currentWord.contents);
        advWORD();
        while (!endWord)
        {
            
            for (int j = 0; j<currentWord.length; j++)
            {
                kataInput.contents[j + kataInput.length] = currentWord.contents[j];
            }
            kataInput.length += currentWord.length;
            advWORD();
        }
    return kataInput;
}
/* fungsi buat dapetin input dari user pake mesin kata*/


int main()
{
    boolean flag = true;

    while (flag)
    {
        //printf("%c\n", currentChar);
        printf("this is start\n");
        Word kataInput = getInput();
        printf("%s\n", kataInput.contents);
        //printf("%s\n", currentWord.contents);

        if(isKataEqual(kataInput, kataNewGame))
        {
            printf("ENTER COMMAND : ");
            while (true)
            {
                kataInput = getInput();
                if (isKataEqual(kataInput,kataMove))
                {
                    printf("placeholder move \n");
                }
                else if (isKataEqual(kataInput,kataPickUp))
                {
                    printf("placeholder pick up\n");
                }
                else if (isKataEqual(kataInput,kataDropOff))
                {
                    printf("placeholder drop off\n");
                }
                else if (isKataEqual(kataInput,kataMap))
                {
                    printf("placeholder map\n");
                }
                else if (isKataEqual(kataInput,kataToDo))
                {
                    printf("placeholder todo\n");
                }
                else if (isKataEqual(kataInput,kataInProgress))
                {
                    printf("placeholder in progress\n");
                }
                else if (isKataEqual(kataInput,kataBuy))
                {
                    printf("placeholder buy\n");
                }
                else if (isKataEqual(kataInput,kataInventory))
                {
                    printf("placeholder inventory\n");
                }
                else if (isKataEqual(kataInput,kataHelp))
                {
                    printf("placeholder help\n");
                }
                else
                {
                    printf("command tidak valid ! kembali ke menu awal");
                }
                
            }
        }
        else if(isKataEqual(kataInput, kataExit))
        {
            printf("EXIT GAME");
            flag = false;
        }
        else
        {
            printf("INPUT TIDAK VALID, TERMINASI PROGRAM");
            flag = false;
        }
    }
}