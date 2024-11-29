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

    playerPosList->insertHead(objPos(10,4,'*'));
}


Player::~Player()
{
    //delete any heap members here
    //nothing on heap yet
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
        default:
            playerPos.pos->x--;
            if (playerPos.pos->x < 1)
                playerPos.pos->x=18;
            
            break;

        case RIGHT:
            playerPos.pos->x++;
            if (playerPos.pos->x > 18)
                playerPos.pos->x=1;
            break;
        
        case UP:
            playerPos.pos->y--;
            if (playerPos.pos->y < 1)
                playerPos.pos->y =8;
            break;
        
        case DOWN:
            playerPos.pos->y++;
            if (playerPos.pos->y  > 8)
                playerPos.pos->y =1;
            break;     
    }

    playerPosList->insertHead(playerPos);
    
    

    
   
}

// More methods to be added