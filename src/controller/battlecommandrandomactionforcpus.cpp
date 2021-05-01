#include "battlecommandrandomactionforcpus.h"

#include <chrono>

BattleCommandRandomActionForCPUs::BattleCommandRandomActionForCPUs(GameModel *model, char keyChar, BattleCharacter *myCharacter)
    : ButtonCommand(model, keyChar)
{
    this->myCharacter = myCharacter;
    srand (time(NULL));
}

void BattleCommandRandomActionForCPUs::execute()
{
    int randVal = rand()%10;

    if(randVal == 0)
        myCharacter->punch();
    else if(randVal == 1)
        myCharacter->kick();
    else if(randVal == 2)
        myCharacter->setVertAxis(-1);
    else if(randVal == 3)
        myCharacter->setVertAxis(0);
    else if(randVal == 4)
        myCharacter->jump();
    else if(randVal == 5)
        myCharacter->setHorzAxis(1);
    else if(randVal == 6)
        myCharacter->setHorzAxis(-1);
    else if(randVal == 7)
        myCharacter->setHorzAxis(0);
    else if(randVal == 8)
        myCharacter->special();
    else if(randVal == 9)
        myCharacter->doThrow();
}
