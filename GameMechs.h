#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib> // provides srand() and rand()
#include <time.h> // provides time()

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs
{
    // Construct the remaining declaration from the project manual.
    // Only some sample members are included here
    // You will include more data members and member functions to complete your design.
    private:
        char input;
        bool exitFlag;
        bool looseFlag;
        int score;

        int boardSizeX;
        int boardSizeY;
        int boardSymbol;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY, char this_boardSymbol);
        bool getExitFlagStatus();
        void setExitTrue();

        bool getLooseFlagStatus();
        void setLooseFlagTrue();

        int getScore();
        void incrementScore();
        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();
        char getBoardSymbol();
};

#endif
