#include "GameMechs.h"

GameMechs::GameMechs()
{
    boardSizeX = 20;
    boardSizeY = 40;
    boardSymbol = '#';
    score = 0;
    exitFlag = false;
    looseFlag = false;
    input = 0;
}

GameMechs::GameMechs(int boardX, int boardY, char this_boardSymbol)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    boardSymbol = this_boardSymbol;
    score = 0;
    exitFlag = false;
    looseFlag = false;
    input = 0;
}

// do you need a destructor?

// include destructor if there are heap data members in the program


// GameMechs::~GameMechs()
// {

// }


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}


char GameMechs::getInput()
{
    return input;
}


int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}


int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


char GameMechs::getBoardSymbol()
{
    return boardSymbol;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}


void GameMechs::setInput(char this_input)
{
    if (this_input == 27) // escape key triggers the exit flag
    {
        exitFlag = true;
    }
    input = this_input;
}


void GameMechs::clearInput()
{
    input = 0;
}


bool GameMechs::getLooseFlagStatus()
{
    return looseFlag;
}


void GameMechs::setLooseFlagTrue()
{
    looseFlag = true;
}


int GameMechs::getScore()
{
    return score;
}


void GameMechs::incrementScore()
{
    score++;
}






