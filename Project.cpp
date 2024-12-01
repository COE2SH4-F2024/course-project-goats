#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"

using namespace std;

#define DELAY_CONST 100000
#define TARGET 50

Player* myPlayer; //global pointer to put player on heap
GameMechs* myGM;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

     
    while(myGM -> getExitFlagStatus() == false){// && !myGM->getLoseFlagStatus()) 
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();


    myGM = new GameMechs(20,10);

    myPlayer = new Player (myGM);

    myGM->getFoods()->generateFood(myPlayer->getPlayerPos(), 20, 10);

}

void GetInput(void)
{
    //gets input from method in games mech
    myGM->collectAsyncInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();

    myPlayer->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    objPosArrayList* snakePos = myPlayer-> getPlayerPos();

    objPos playerPos = myPlayer->getPlayerPos()->getHeadElement();

    int snakeSize = snakePos->getSize();

    bool printedSnake = false;
    bool printedFood = false;

    int i,j;

    int boardX = myGM->getBoardSizeX();
    int boardY = myGM->getBoardSizeY();

    //objPos foodPos = getFoodPos();
    if (!myGM->getLoseFlagStatus() && myGM->getScore()<TARGET)
    {
        for (i=0;i<boardY;i++)
        {
            for (j=0;j<boardX;j++)
            {

                printedFood = false;
                printedSnake = false;

                for (int k = 0; k <snakeSize; k++)
                {
                    
                    objPos thisSeg = snakePos -> getElement(k);

                    if (thisSeg.getObjPos().pos->x == j && i == thisSeg.getObjPos().pos->y)
                        {
                            MacUILib_printf("%c", thisSeg.getObjPos().getSymbol());
                            printedSnake = true;
                        }
                }

                if (printedSnake)
                {
                    continue;
                }

                for (int l = 0; l <FOODNUUM; l++)
                {
                    
                    Food* thisFood = myGM->getFoods();

                    if (thisFood->getFoodPos()->getElement(l).pos->x == j && i == thisFood->getFoodPos()->getElement(l).pos->y)
                        {
                            MacUILib_printf("%c", thisFood->getFoodPos()->getElement(l).getSymbol());
                            printedFood = true;
                        }
                }

                if (printedFood)
                {
                    continue;
                }

                if(i==0 || i == boardY-1 || j ==0 || j == boardX-1)
                    MacUILib_printf("%c", '#');
                
                else
                    MacUILib_printf("%c", ' ');
            }
            MacUILib_printf("\n");
        } 

        MacUILib_printf("\"%c\" ", playerPos.symbol);

        MacUILib_printf("[%d ", (myPlayer->getPlayerPos()->getElement(0).pos->x));
        MacUILib_printf("%d]\n", (myPlayer->getPlayerPos()->getElement(0).pos->y));
        MacUILib_printf("Score: %d\n", myGM->getScore());
        MacUILib_printf("Obtain a score of %d to win!\n", TARGET);
        /*MacUILib_printf("%d\n", boardX);
        MacUILib_printf("%c", myGM->getFoods()->getFoodPos()->getElement(0).getSymbol());*/
    }
    else if (myGM->getLoseFlagStatus())
    {
        MacUILib_clearScreen(); 
        MacUILib_printf("YOU LOSE\tGAME OVER\nScore: %d\nPress the Spacebar to exit", myGM->getScore());
    }

    else if (myGM->getExitFlagStatus())
    {
        MacUILib_clearScreen(); 
        MacUILib_printf("Game Exitted");
    }
    else if (myGM->getScore()>=TARGET)
    {
        MacUILib_clearScreen(); 
        MacUILib_printf("YOU WIN!!!!!!!!!!\tGAME OVER\nScore: %d\nPress the Spacebar to exit", myGM->getScore());
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete myPlayer;
    delete myGM;

    MacUILib_uninit();
}
