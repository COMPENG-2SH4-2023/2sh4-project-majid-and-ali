#include "GameMechs.h"

GameMechs::GameMechs()
{
    this->boardSizeX = 20;
    this->boardSizeY = 40;
    this->boardSymbol = '#';
}

GameMechs::GameMechs(int boardX, int boardY, char boardSymbol)
{
    this->boardSizeX = boardX;
    this->boardSizeY = boardY;
    this->boardSymbol = boardSymbol;
}

// do you need a destructor?

// include destructor if there are heap data members in the program

// GameMechs::~GameMechs()
// {

// }

bool GameMechs::getExitFlagStatus()
{

}

char GameMechs::getInput()
{
    return this->input;
}

int GameMechs::getBoardSizeX()
{
    return this->boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return this->boardSizeY;
}

char GameMechs::getBoardSymbol()
{
    return this->boardSymbol;
}


void GameMechs::setExitTrue()
{

}

void GameMechs::setInput(char this_input)
{
    this->input = this_input;
}

void GameMechs::clearInput()
{

}


