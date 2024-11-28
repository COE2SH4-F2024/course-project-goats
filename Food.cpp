#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#define FOODNUUM 5

using namespace std;

class Food
{
    private:
        objPos* foodPos;
    
    public:
        Food();
        ~Food();
        Food(const Food &f);
        Food& operator=(const Food &f);
        void generateFood(objPos blockOff, int getx, int gety);
        objPos getFoodPos() const;
};

Food::Food()//default constructor
{
    foodPos= new objPos[FOODNUUM];
}

Food::Food(const Food &f){// copy constructor
    foodPos= new objPos[FOODNUUM];
    for (int i=0;i<FOODNUUM;i++){//deep copy
        foodPos[i]=f.foodPos[i];
    }
}

Food& Food::operator=(const Food &f){//copy assignment constructor
    if (this!=&f){
        this->foodPos=new objPos[FOODNUUM]; 
        for (int i=0;i<FOODNUUM;i++){//deep copy
            this->foodPos[i]=f.foodPos[i];
        }
    }
    return *this;
}

Food::~Food()//destructor
{
    delete[] foodPos;
}

void Food::generateFood(objPos blockOff,int getx, int gety)
{
    srand(time(NULL));
    int open[getx][gety]={0}; // list of open spots
    open[blockOff.pos->x][blockOff.pos->y]=1; // do not spawn on player NOT SURE IF WORKS
    for (int i=0; i<FOODNUUM; i++){
        do{ // got to make a random variable before checking
            int chance = rand()%20;//bonus variable
            foodPos[i].pos->x=(rand()%(getx-2)+1);//doesnt include border
            foodPos[i].pos->y=(rand()%(gety-2)+1);
            if (chance==0){// 5% chance
                foodPos[i].symbol='@'; 
            }else{ // normal
                foodPos[i].symbol='$';  
            }
        }while(open[foodPos[i].pos->x][foodPos[i].pos->y]!=0);//if its taken then keep redoing
        open[foodPos[i].pos->x][foodPos[i].pos->y]=1;
    }
}

objPos Food::getFoodPos() const
{
    return *foodPos; // idk if this is what its asking for
}

#endif