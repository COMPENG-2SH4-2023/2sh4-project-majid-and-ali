#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "objPosArrayList.h"

using namespace std;
#define DELAY_CONST 100000

//Global variables
GameMechs* myGM;
Player* myPlayer;
Food* foodInst; // food instance variable
objPosArrayList* playerBody;
objPos foodPos; // will store position object of food item
objPos tempBody; //used to temporarily store the body part position information

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


int main(void)
{
    Initialize();
    while(myGM->getExitFlagStatus() == false)  
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


    myGM = new GameMechs(26, 13, '#'); // make the board size 26x13 on the heap
    foodInst = new Food(myGM);
    myPlayer = new Player(myGM, foodInst); // makes new player object on the heap
   
}


void GetInput(void)
{
    if (MacUILib_hasChar())
        myGM->setInput(MacUILib_getChar());
}


void RunLogic(void)
{
   
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myPlayer->checkSelfCollision();

    myGM ->clearInput(); // Can clear as myDirection will remain the same as previous input until new input is take in

}


void DrawScreen(void)
{
   bool drawn; //used as check to make sure contents after the third if statement don't get printed out once a player character is printed


   playerBody = myPlayer->getPlayerPos(); //gets the information of the body part
   
   foodInst->getFoodPos(foodPos); //gets the food position

    MacUILib_clearScreen();
    for (int i = 0; i<myGM->getBoardSizeY(); i++)
    {
        for(int j = 0; j<myGM->getBoardSizeX(); j++)
        {
            //Printing snake
            drawn = false;
            for (int k=0; k < (playerBody->getSize()); k++)
            {
                playerBody -> getElement(tempBody, k);
                if(tempBody.x == j && tempBody.y == i) //Checks to see if the body parts specified locations match that of x and y. If so then it will be printed out
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break; //Needs to move onto the next body part thus j and i values need to be iterated through to check if x and y values match position of next element
                }
            }
            if(drawn) continue; //We don't want the printed out character to be over-written. When evaluated to false will print out default map characters and food
           
            //if player body was drawn, don't draw anything below
            if (i==0 || i == myGM->getBoardSizeY()-1 || j == myGM->getBoardSizeX()-1 || j==0)
                MacUILib_printf("%c", myGM->getBoardSymbol());
            else if (i == foodPos.y && j == foodPos.x) //food position check and print
                MacUILib_printf("%c", foodPos.symbol);
            else
                MacUILib_printf("%c", ' ');
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Score: %d\n", myGM->getScore());

    if (myGM->getLooseFlagStatus())
    {
        MacUILib_printf("\nYou have lost the game!\n");
    }
}


void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
   //Removes heap instances
   delete myGM;
   delete myPlayer;
   delete foodInst;

   MacUILib_uninit();
}
