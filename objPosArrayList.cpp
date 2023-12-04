#include "objPosArrayList.h"


// Check lecture contents on general purpose array list construction,
// and modify it to support objPos array list construction.


objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; //200 elements of type objPos on the heap
    listSize = 0; //No valid elements upon start up
    arrayCapacity = ARRAY_MAX_CAP; //Initiates the size element of the object
}

objPosArrayList::objPosArrayList(int maxArrCap)
{
    aList = new objPos[maxArrCap]; //200 elements of type objPos on the heap
    listSize = 0; //No valid elements upon start up
    arrayCapacity = maxArrCap; //Initiates the size element of the object
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; //Will delete each element of the 1D array
}


int objPosArrayList::getSize()
{
    return listSize;
}


void objPosArrayList::insertHead(objPos thisPos)
{
    //Error check implemented if listSize is at capacity
    for (int i = listSize; i > 0 && i < arrayCapacity; i--)
    {
        aList[i].setObjPos(aList[i-1]); //Sets the postion of the current element postion to the previous element, inorder to crreate room in the front
    }


    //Error check implemented if listSize is at capacity
    if (listSize < arrayCapacity)
    {
        aList[0].setObjPos(thisPos);
        listSize++;
    }
   
}


void objPosArrayList::insertTail(objPos thisPos)
{
    //Error check implemented if listSize is at capacity
    if(listSize < arrayCapacity)
    {
        aList[listSize].setObjPos(thisPos);
        listSize++;
    }
}


void objPosArrayList::removeHead()
{
    //Error check implemented if listSize is at 0
    if(listSize>0)
    {
        for(int i = 0; i < listSize-1; i++) //-1 as last element will already be moved before reaching its iteration
        {
            aList[i].setObjPos(aList[i+1]);
        }
    }

    //Error check implemented if listSize is at 0
    if(listSize>0)
    {
        listSize--;
    }
}


void objPosArrayList::removeTail()
{
    //Error check implemented if listSize is at 0
    if (listSize>0)
    {
        listSize--;
    }
}


void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}


void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize-1]);
}


void objPosArrayList::getElement(objPos &returnPos, int index)
{
    if (index < listSize && index >= 0) // check to prevent invalid index
        returnPos.setObjPos(aList[index]);
}
