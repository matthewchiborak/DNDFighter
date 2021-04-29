#include "specialpropertycommanddp.h"

SpecialPropertyCommandDP::SpecialPropertyCommandDP(BattleCharacter *user)
    : SpecialPropertyCommand(user)
{

}

void SpecialPropertyCommandDP::execute()
{
    user->forceJump(0);
}
