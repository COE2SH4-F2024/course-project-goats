#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 20;
    boardSizeY = 10;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;

    food = new Food();
}

// do you need a destructor? nah
GameMechs::~GameMechs()
{

}

GameMechs::GameMechs(const GameMechs &g){//copy 
    input=0;
    exitFlag=false;
    loseFlag=false;
    score=0;
    boardSizeX=g.boardSizeX;
    boardSizeY=g.boardSizeY;
}

GameMechs& GameMechs::operator=(const GameMechs &g){//copy assignment
    if (this!=&g){
        this->input=0;
        this->exitFlag=false;
        this->loseFlag=false;
        this->score=0;
        this->boardSizeX=g.boardSizeX;
        this->boardSizeY=g.boardSizeY;
    }
    return *this;
}


bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}

void GameMechs :: collectAsyncInput()
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }  
    
    if (input == ' ')
    {
        setExitTrue();
    }
}
    

char GameMechs::getInput()
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore(int inc)//how many points shouuld be incremented
{
    score+=inc;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input=this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here

Food* GameMechs::getFoods() const
{
    return food;
}
