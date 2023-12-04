#include "Player.h"

Player::Player(GameMechs* thisGMRef, Food* thisFoodInst)
{
    mainGameMechsRef = thisGMRef;  //pointer
    foodInst = thisFoodInst;
    input = STOP;
    mySpeed = MEDIUM;


    //Temporary variable with location of the body part to store on list
    currentHead.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'o');
   
    //creates list

    // Create a new heap member, with access to array list elements,
    // like double pointer lists.
    playerPosList = new objPosArrayList();
   
    //Stores body part on to list by storing it from the head
    playerPosList->insertHead(currentHead);


    //Generates food
    foodInst->generateFood(playerPosList);
}


Player::~Player()
{
    // delete any heap members here
    //Will call destructor of arraylist, thus deleting all array members
    delete playerPosList;
}


objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList; //Accesses function from objPos class
}


void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    input = mainGameMechsRef->getInput();    
    switch(input)


    //Updates position
    {
        case UP:
            if (myDir != UP && myDir != DOWN)
            {
                myDir = UP;
            }
            break;
        case RIGHT:
            if (myDir != LEFT && myDir != RIGHT)
            {
                myDir = LEFT;
            }
            break;
        case DOWN:
            if (myDir != UP && myDir != DOWN)
            {
                myDir = DOWN;
            }
            break;
        case LEFT:
            if (myDir != LEFT && myDir != RIGHT)
            {
                myDir = RIGHT;
            }
            break;
       
        case STOP:
            break;




        default:
            break;
    }
}


bool Player::checkFoodConsumption()
{
    //foodPos will obtain the position of the food
    foodInst->getFoodPos(foodPos);


    // If coordinates match meaning snake collides with food,
    // then statement will evaluate to true.
    if (foodPos.x == currentHead.x && foodPos.y == currentHead.y)
        return true;
    else
        return false;
}


void Player::increasePlayerLength()
{
    // currentHead will become new head, should be inserted to the
    // head of the list as we have update its coordinates.
    playerPosList->insertHead(currentHead);


   
    // Tail removal. We added the above element, thus we must take away the extra
    // element at the end. This creates the illusion of the snake movement.
    if (this->checkFoodConsumption())
    {
        foodInst->generateFood(playerPosList);
        mainGameMechsRef->incrementScore(); //Increases score, when food is eaten
    }
    else
    {
        // Only remove if the head does not collide with the food object.
        // Thus creating the illusion of the snake growing in size and
        // generates another random location for the food.
        playerPosList->removeTail();
    }
}

bool Player::checkSelfCollision()
{
    int i;
    objPos tempPos; // will be used in for loop to hold the value of an objPos element in playerPosList
    objPos headPos; // will hold the head element of playerPosList
    playerPosList->getHeadElement(headPos);

    for (i = 1; i < playerPosList->getSize(); i++) // index 0 is not taken into account because
    // it is the index of the head element which we are trying to compare
    {
        playerPosList->getElement(tempPos, i);
        if (tempPos.isPosEqual(&headPos)) // i.e. if the head collides with the snake body
        {
            mainGameMechsRef->setExitTrue();
            mainGameMechsRef->setLooseFlagTrue();
            return true;
        }
    }
    return false;
}


void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    //stores the head element info into currentHead variable
    playerPosList->getHeadElement(currentHead);

    //Board dimensions
    sizeX = mainGameMechsRef->getBoardSizeX();
    sizeY = mainGameMechsRef->getBoardSizeY();

    //Movement
    switch(myDir)
    {
        case LEFT:
            currentHead.x++;
            break;


        case RIGHT:
            currentHead.x--;
            break;


        case UP:
            currentHead.y--;
            break;


        case DOWN:
            currentHead.y++;
            break;


        default:
            break;
    }

    //if hits boundry of y direction, then implements wrap around
    if (currentHead.y == sizeY-1)
        currentHead.y = 1;
    if (currentHead.y == 0)
        currentHead.y = sizeY-2;
   
    //if hits boundry of x direction, then implements wrap around
    if (currentHead.x == sizeX-1)
        currentHead.x = 1;
    if (currentHead.x == 0)
        currentHead.x = sizeX-2;


    // Increases the length of the snake by just adding a new head,
    // if food is consumed. If not then it just moves the snake by
    // adding a new head and removing the tail.
    this->increasePlayerLength();
}
