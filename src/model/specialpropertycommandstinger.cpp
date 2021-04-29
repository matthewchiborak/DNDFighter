#include "specialpropertycommandstinger.h"

SpecialPropertyCommandStinger::SpecialPropertyCommandStinger(BattleCharacter *user)
    : SpecialPropertyCommand(user)
{

}

void SpecialPropertyCommandStinger::execute()
{
    if(user->getIsFaceRight())
        user->forceMove(user->getWalkSpeed() * 4);
    else
        user->forceMove(user->getWalkSpeed() * -4);
}
