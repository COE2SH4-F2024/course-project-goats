#include "objPosArrayList.h"
#include "objPos.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.

objPosArrayList:: objPosArrayList()
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;

    aList = new objPos[arrayCapacity];
    
    for(int i = 0; i < ARRAY_MAX_CAP - 1; i++)
    {
        aList[i] = objPos();
    }
}
//copy
objPosArrayList::objPosArrayList(const objPosArrayList &o)
{
    arrayCapacity=ARRAY_MAX_CAP;
    listSize=o.getSize();
    aList= new objPos[ARRAY_MAX_CAP];

    for (int i = 0; i < listSize; i++){//deep copy
        aList[i]=o.aList[i];
    }
}

//copy assignment
objPosArrayList& objPosArrayList::operator=(const objPosArrayList &o)
{
    if (this!=&o){
        this->listSize=o.getSize();
        this->arrayCapacity=ARRAY_MAX_CAP;
        this->aList=new objPos[ARRAY_MAX_CAP];

        for (int i = 0; i < this->listSize; i++){//deep copy
            this->aList[i]=o.aList[i];
        }
    }
    return *this;
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
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}
