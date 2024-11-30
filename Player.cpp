#include "Player.h"
#include "objPos.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPosList = new objPosArrayList();

    /*
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;
    playerPos.symbol = '*';//*/

    objPos headPos(thisGMRef->getBoardSizeX()/2,thisGMRef->getBoardSizeY()/2,'*');

    playerPosList->insertHead(headPos);
}


Player::~Player()
{
    //delete any heap members here
    delete playerPosList;
}

objPosArrayList*  Player:: getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic   
    char input = mainGameMechsRef -> getInput();

    mainGameMechsRef ->clearInput();

    switch(input)
    {                      
        case 'W':
        case 'w':
            if (myDir != UP && myDir != DOWN)
                myDir = UP;
            
            break;

        case 'A':
        case 'a':
            if (myDir != LEFT && myDir != RIGHT)
                myDir = LEFT;
            break;

        case 'S':
        case 's':
            if (myDir != DOWN && myDir != UP)
                myDir = DOWN;
            
            break;

        case 'D':
        case 'd':
            if (myDir != RIGHT && myDir != LEFT)
                myDir = RIGHT;
                
            break;
            
        default:
            break;
    }       
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
   // MacUILib_printf("move player called");
    objPos playerPos = playerPosList->getHeadElement();
    switch(myDir)
    {
        case LEFT:
        
            playerPos.pos->x--;
            if (playerPos.pos->x < 1)
                playerPos.pos->x=mainGameMechsRef->getBoardSizeX()-2;
            
            break;

        case RIGHT:
            playerPos.pos->x++;
            if (playerPos.pos->x > mainGameMechsRef->getBoardSizeX()-2)
                playerPos.pos->x=1;
            break;
        
        case UP:
            playerPos.pos->y--;
            if (playerPos.pos->y < 1)
                playerPos.pos->y = mainGameMechsRef->getBoardSizeY()-2;
            break;
        
        case DOWN:
            playerPos.pos->y++;
            if (playerPos.pos->y  > mainGameMechsRef->getBoardSizeY()-2)
                playerPos.pos->y =1;
        default:
            break;     
    }

    playerPosList->insertHead(playerPos);
    
    
    
    //check if new temp obj overlaps food pos 


    //checking overlap and use isPosEqual
    if(checkEat()==1)
        mainGameMechsRef->incrementScore(1);

    else   
        playerPosList->removeTail();

    //check is snake collides with itself and show lose screen
    if(checkCrash())
    {
        mainGameMechsRef->setLoseFlag();
        myDir = STOP;
    }
    
   

   //if overlapped, food consumed, do not remove snake tail
   //take respective action to add to score

   //if no overlap, remove tail, complete movement
    

}

// More methods to be added

int Player::checkEat() 
{
    for (int p = 0;p<FOODNUUM;p++)
    {
        Food* foodCurrent = mainGameMechsRef->getFoods();
        if (playerPosList->getHeadElement().isPosEqual(foodCurrent->getFoodPos()->getElement(p)))
        {
            if (foodCurrent->getFoodPos()->getElement(p).getSymbol() == '$')
            {
                mainGameMechsRef->getFoods()->generateFood(playerPosList, mainGameMechsRef->getBoardSizeX(), mainGameMechsRef->getBoardSizeY());
                return 1;
            }
            else if(foodCurrent->getFoodPos()->getElement(p).getSymbol() == '@')// if collides with special food
            {
                mainGameMechsRef->getFoods()->generateFood(playerPosList, mainGameMechsRef->getBoardSizeX(), mainGameMechsRef->getBoardSizeY());
              //  MacUILib_printf("Special Food");
                mainGameMechsRef->incrementScore(5); //increment score by 5 and don't return 1 so it doesn't gain length
                return 2;

            }
        }

    }
    return 0;
}

bool Player:: checkCrash()
{
    for (int i = 1; i < playerPosList->getSize(); i++)
    {
        if(playerPosList->getHeadElement().isPosEqual(playerPosList->getElement(i)))
        {
            return true;
        }
    }

    return false;
}