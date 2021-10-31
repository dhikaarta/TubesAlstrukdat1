#include <stdio.h>
#include <stdlib.h>
#include "../ADT list statis/listtask.h"
#include "../ADT list statis/listtask.c"


Word kataNewGame = {"NEWGAME", 7};  Word kataExit = {"EXIT", 4};
Word kataMove = {"MOVE", 4};    Word kataPickUp = {"PICK_UP", 7};    Word kataDropOff = {"DROP_OFF", 8};
Word kataMap = {"MAP", 3};    Word kataToDo = {"TO_DO", 5};    Word kataInProgress = {"IN_PROGRESS", 11};
Word kataBuy = {"BUY", 3};    Word kataInventory = {"INVENTORY", 9};    Word kataHelp = {"HELP", 4};

Word getInput()
{
    startWORD();
    Word kataInput = currentWord;
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
    int N,M,i_headquarters,j_headquarters,L,P;

    while (flag)
    {
     
        printf("this is start\n");
        Word kataInput = getInput();


        if(isKataEqual(kataInput, kataNewGame))
        {
            printf("Silahkan masukkan file konfigurasi : ");
            kataInput = getInput();

            startWORDfile(kataInput.contents);
            printf("%s\n", currentWordfile.contents);
            N = atoi(currentWordfile.contents);
            advWORDfile();
            printf("%s\n", currentWordfile.contents);
            M = atoi(currentWordfile.contents);
            advWORDfile();
            i_headquarters = atoi(currentWordfile.contents);
            advWORDfile();
            j_headquarters = atoi(currentWordfile.contents);
            advWORDfile();
            L = atoi(currentWordfile.contents);
            printf("%i %i %i %i %i \n",N,M,i_headquarters,j_headquarters,L);
            LOCATION* arrayLoc = makeArrayOfLOCATION(L,i_headquarters,j_headquarters);
            displaylistLOCATION(arrayLoc, L);
            Matrix Madj = makeMatrixAdj(L);
            displayMATRIX(Madj); printf("\n");
            advWORDfile();
            P = atoi(currentWordfile.contents);
            ListTASK lTask;
            ReadLISTTASKfile(&lTask,P);
            lTask = sortLISTTASK(lTask);
            displayLISTTASK(lTask); printf("\n");

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