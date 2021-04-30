#include "specialpropertycommandheal.h"

SpecialPropertyCommandHeal::SpecialPropertyCommandHeal(BattleCharacter *user)
    : SpecialPropertyCommand(user)
{

}

void SpecialPropertyCommandHeal::execute()
{
    user->setDamageMultiplier(-1);
}
