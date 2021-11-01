#include <stdio.h>
#include <stdlib.h>
#include "../GAME/map/map.c"
#include "../ADT list statis/listtask.c"
#include "../ADT list statis/listtask.h"
#include "../GAME/pcolor/pcolor.c"
#include "../GAME/help/help.c"



Word kataNewGame = {"NEWGAME", 7};  Word kataExit = {"EXIT", 4};
Word kataMove = {"MOVE", 4};    Word kataPickUp = {"PICK_UP", 7};    Word kataDropOff = {"DROP_OFF", 8};
Word kataMap = {"MAP", 3};    Word kataToDo = {"TO_DO", 5};    Word kataInProgress = {"IN_PROGRESS", 11};
Word kataBuy = {"BUY", 3};    Word kataInventory = {"INVENTORY", 9};    Word kataHelp = {"HELP", 4};

LOCATION nobita; LOCATION pickUp; LOCATION dropOff;

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
            
            
            LOCATION* arrayLoc = makeArrayOfLOCATION(L,i_headquarters,j_headquarters);
            displaylistLOCATION(arrayLoc, L);
            Matrix MAP;
            CreateMAP(N,M,&MAP);
            readMAPConfiguration(&MAP, arrayLoc, L);

    
            Matrix Madj = makeMatrixAdj(L);
            displayMATRIX(Madj); printf("\n");
            
            nobita = getLocHQ(arrayLoc);

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
                    int i;
                    int lokasiDipilih;
                    do{
                        int nPossibleMoves;
                        LOCATION* arrayPosMove;
                        arrayPosMove = makeArrayOfPossibleMoves(Madj, arrayLoc, nobita, L, &nPossibleMoves);
                        printf("\nPosisi yang dapat dicapai:\n");
                        for (i=0;i<nPossibleMoves;i++){
                            printf("%d. %c (%d,%d)\n", i+1, CHAR(arrayPosMove[i]), LOC_X(arrayPosMove[i]), LOC_Y(arrayPosMove[i]));
                        }
                        displayMAPColor(MAP,nobita, arrayPosMove, nPossibleMoves);
                        printf("\nPosisi yang dipilih? (ketik 0 jika ingin kembali) ");
                        scanf("%d", &lokasiDipilih);
                        LOCATION prevNobita = nobita;
                        nobita = arrayPosMove[lokasiDipilih-1];
                        
            
                        printf("\nMobita sekarang berada di titik ");
                        TulisLOCATION(nobita);
                        printf("!");
                        printf("\n");
                    }while (lokasiDipilih !=0 );
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
                    int nPossibleMoves;
                    LOCATION* arrayPosMove;
                    arrayPosMove = makeArrayOfPossibleMoves(Madj, arrayLoc, nobita, L, &nPossibleMoves);
                    displayMAPColor(MAP,nobita, arrayPosMove, nPossibleMoves);
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
                   printHelp();
                }
                else
                {
                    printf("command tidak valid ! kembali ke menu awal\n");
                }
                printf("ENTER COMMAND : ");
                
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