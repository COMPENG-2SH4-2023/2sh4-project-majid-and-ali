#include "Food.h"

Food::Food(GameMechs* thisGMRef)
{
    gameMechsRef = thisGMRef;
    foodPos.setObjPos(-1, -1, 'o'); // initializing it outside of the board so it is not visible in the beginning
    srand(time(NULL) * 3.14);
}

void Food::getFoodPos(objPos &returnObjPos)
{
    foodPos.getObjPos(returnObjPos);
}

void Food::generateFood(objPosArrayList* blockOff)
{
    // generate random x and y coords, make sure that they are not at border or blockOff pos
    bool cond = true;
    int xCoord, yCoord;
 
    while (cond)
    {
        xCoord = rand() % (gameMechsRef->getBoardSizeX() - 2) + 1; // this does not allow the xCoord to be on the border or exceed it
        yCoord = rand() % (gameMechsRef->getBoardSizeY() - 2) + 1; // this does not allow the x\yCoord to be on the border or exceed it

        foodPos.setObjPos(xCoord, yCoord, '.');
        objPos temp; // temp variable for evaluation in the following for loop

        for (int i = 0; i < blockOff->getSize(); i++)
        {
            // Stores the position of the body part of the snake in the
            // temp variable.
            blockOff->getElement(temp, i);

            // If any part of the body's position is the same as the food
            // position, the condition will evaluate to true, and will break
            // out of the for loop to find a new position for the food.
            cond = foodPos.isPosEqual(&temp)? true : false;
            if (cond==true)
                break;
        }
    }
}