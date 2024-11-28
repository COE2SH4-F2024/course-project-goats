#include "objPosArrayList.h"
#include <iostream>

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.

objPosArrayList:: objPosArrayList()
{
    listSize = 0;
    arrayCapacity = 100;

    aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList()
{
    delete [] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList:: insertHead(objPos thisPos)
{
    for(int i = listSize;i>0;i--)
        aList[i] = aList[i-1];
    
    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    aList[listSize++] = thisPos;
}

void objPosArrayList::removeHead()
{
    for(int i=0; i<listSize-1; i++)
    {
        aList[i] = aList[i+1];  // Shifting towards the head, element i replaced by element i+1
    }
    listSize--; 
}

void objPosArrayList::removeTail()
{
    listSize--;
}
        
objPos objPosArrayList::getHeadElement() const
{
    if (listSize < 0) 
    {
        throw std::out_of_range("List is empty.");
    }
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    if (listSize < 0) 
    {
        throw std::out_of_range("List is empty.");
    }
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    if (index < 0 || index >= listSize) 
    {
        throw std::out_of_range("Index out of bounds.");
    }
    return aList[index];
}