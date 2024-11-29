#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPosArrayList.h"
#define FOODNUUM 5

using namespace std;

class Food
{
    private:
        //objPos foodPos;
        objPosArrayList* foodPos; 
    
    public:
        Food();
        ~Food();
        Food(const Food &f);
        Food& operator=(const Food &f);
        void generateFood(objPosArrayList* blockOff, int getx, int gety);
        objPosArrayList* getFoodPos() const;
};

#endif