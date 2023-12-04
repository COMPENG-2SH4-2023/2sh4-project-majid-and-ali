#ifndef FOOD_h
#define FOOD_h

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

class Food
{
    private:
        objPos foodPos;
        GameMechs* gameMechsRef;
    public:
        Food(GameMechs* thisGMRef);
        void generateFood(objPosArrayList* blockOff); 
        void getFoodPos(objPos &returnPos);
};

#endif