#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

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

    while(myGM -> getExitFlagStatus() == false)  
    {
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

    objPos playerPos = myPlayer->getPlayerPos()->getHeadElement();

    int i,j;

    int boardX = myGM->getBoardSizeX();
    int boardY = myGM->getBoardSizeY();

    //objPos foodPos = getFoodPos();

    for (i=0;i<10;i++)
    {
        for (j=0;j<20;j++)
        {
            if(i==0 || i==9)
                MacUILib_printf("#");
            else
            {
                if (j==0||j==19)
                    MacUILib_printf("#");
                else if(playerPos.pos->x == j && playerPos.pos->y == i)
                    MacUILib_printf("%c", playerPos.symbol);
                else if (j == myGM->getFoods()->getFoodPos()->getElement(i).pos->x && i == myGM->getFoods()->getFoodPos()->getElement(i).pos->y)
                {
                    MacUILib_printf("%c", myGM->getFoods()->getFoodPos()->getElement(i).getSymbol());
                }
                else
                    MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    } 

    MacUILib_printf("%c ", playerPos.symbol);

    MacUILib_printf("%d ", (myPlayer->getPlayerPos()->getElement(0).pos->x));
    MacUILib_printf("%d\n", (myPlayer->getPlayerPos()->getElement(0).pos->y));
    MacUILib_printf("%d\n", boardX);
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
