#ifndef PLAYER_H
#define PLAYER_H


#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"


class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd', STOP};  // This is the direction state
        enum speed {VERY_SLOW, SLOW, MEDIUM, FAST, VERY_FAST}; // Player speed

        Player(GameMechs* thisGMRef, Food* thisFoodInst);
        ~Player(); 

        objPosArrayList* getPlayerPos();
        void updatePlayerDir();
        void movePlayer();


        bool checkFoodConsumption();
        void increasePlayerLength();

        bool checkSelfCollision();

    private:
        objPosArrayList* playerPosList;     
        enum Dir myDir;
        enum speed mySpeed;
        char input; //access input updated in gameMechs
        int sizeX;
        int sizeY;

        objPos currentHead; //Holds the position info of the current head, so algorithm of snake movement can be implemented
        objPos foodPos;
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        Food* foodInst;
};

#endif
