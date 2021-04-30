#include "specialpropertycommanddp.h"

SpecialPropertyCommandDP::SpecialPropertyCommandDP(BattleCharacter *user)
    : SpecialPropertyCommand(user)
{

}

void SpecialPropertyCommandDP::execute()
{
    user->setDamageMultiplier(0);
    user->forceJump(0);
}
