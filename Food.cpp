#include "Food.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;


Food::Food()//default constructor
{
    foodPos= new objPosArrayList[FOODNUUM];

    for(int i=0; i<FOODNUUM; i++) {
        objPos foodPosition(5, i+3, '$');
        foodPos->insertHead(foodPosition);
    }

}

Food::Food(const Food &f){// copy constructor
    foodPos= new objPosArrayList[FOODNUUM];
    for (int i=0;i<FOODNUUM;i++){//deep copy
        foodPos[i]=f.foodPos[i];
    }
}

Food& Food::operator=(const Food &f){//copy assignment constructor
    if (this!=&f){
        this->foodPos=new objPosArrayList[FOODNUUM]; 
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

void Food::generateFood(objPosArrayList* blockOff,int getx, int gety)
{
    srand(time(NULL));
    int open[gety][getx]={0}; // list of open spots

    open[blockOff->getHeadElement().pos->y][blockOff->getHeadElement().pos->x]=1;

    int snakeSize = blockOff->getSize();

    for (int i = 0; i<snakeSize ; i++)    
    {
        open[blockOff->getElement(i).pos->y][blockOff->getElement(i).pos->x]=5; // do not spawn on player 
    }

    for (int i=0; i<FOODNUUM; i++){
        do{ // got to make a random variable before checking


            int chance = rand()%25;//bonus variable
            
            int randXPos = (rand()%(getx-2)+1);
            int randYPos = (rand()%(gety-2)+1);

            foodPos->getElement(i).pos->x=randXPos;//doesnt include border
            foodPos->getElement(i).pos->y=randYPos;
            if (chance==0){// 5% chance
                //foodPos[i]->symbol='@'; 
                objPos foodPosition(randXPos, randYPos, '@');
                foodPos->removeHead();
                foodPos->insertTail(foodPosition);
            }
            else{ // normal
                //foodPos[i].symbol='$';  
                objPos foodPosition(randXPos, randYPos, '$');
                foodPos->removeHead();
                foodPos->insertTail(foodPosition);
            }
        }while(open[foodPos->getElement(i).pos->y][foodPos->getElement(i).pos->x]!=0);//if its taken then keep redoing

        open[foodPos->getElement(i).pos->y][foodPos->getElement(i).pos->x]=1;
    }
}

objPosArrayList* Food::getFoodPos() const
{
    return foodPos; // idk if this is what its asking for
}