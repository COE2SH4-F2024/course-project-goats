#ifndef GAMEMECHS_H
#define GAMEMECHS_H


#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

using namespace std;

class GameMechs
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;

        int boardSizeX;
        int boardSizeY;

        Food* food;
        //objPos foodPos;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // is this one needed at all? Why or why not?
        GameMechs(const GameMechs &g); //copy
        GameMechs& operator=(const GameMechs &g); // copy assignment
        
        
        bool getExitFlagStatus() const; 
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX() const;
        int getBoardSizeY() const;
        
        int getScore() const;
        void incrementScore(int inc);
        
        // More methods should be added here
        void collectAsyncInput();

        //void generateFood(objPos blockOff);
        Food* getFoods() const;
};

#endif