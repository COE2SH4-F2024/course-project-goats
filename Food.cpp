#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class Food
{
    private:
        objPos foodPos;
    
    public:
        Food();
        ~Food();
        void generateFood(objPos blockOff);
        objPos getFoodPos() const;
};

Food::Food()
{
    foodPos.pos->x =0;
}

Food::~Food()
{

}

void Food::generateFood(objPos blockOff)
{

}

objPos Food::getFoodPos() const
{
    return foodPos;
}

#endif