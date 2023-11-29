#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;
GameMechs board(20, 40, '#');
objPos** border;
char user_input; // will hold user input



void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    // allocating memory for the board:
    border = new objPos*[board.getBoardSizeX()]; 
    int i, j;
    for (i = 0; i < board.getBoardSizeX(); i++) {
        border[i] = new objPos[board.getBoardSizeY()];
    }

    // initializing elements of the board
    for (i = 0; i < board.getBoardSizeX(); i++) {
        for (j = 0; j < board.getBoardSizeY(); j++) {
            if (i == board.getBoardSizeX() - 1 || i == 0 || j == board.getBoardSizeY() - 1 || j == 0) 
                border[i][j] = objPos(i, j, board.getBoardSymbol());
            else
                border[i][j] = objPos(i, j, ' ');
        }
    }

    exitFlag = false;
}

void GetInput(void)
{
   if (MacUILib_hasChar())
    user_input = MacUILib_getChar();
}

void RunLogic(void)
{
    if (user_input == ' ')
        exitFlag = true;
    else
        exitFlag = false;
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    int i, j;
    
    for (i = 0; i < board.getBoardSizeX(); i++) {
        for (j = 0; j < board.getBoardSizeY(); j++)
        {
            MacUILib_printf("%c", border[i][j].getSymbol());
        }
        MacUILib_printf("\n");
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    int i;
    for (i = 0; i < board.getBoardSizeX(); i++) {
        delete[] border[i];
    }
    delete[] border;
    MacUILib_uninit();
}
