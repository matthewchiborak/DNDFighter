#include "specialpropertycommandsneak.h"

SpecialPropertyCommandSneak::SpecialPropertyCommandSneak(BattleCharacter *user)
    : SpecialPropertyCommand(user)
{

}

void SpecialPropertyCommandSneak::execute()
{
    if(user->getIsFaceRight())
    {
        user->setPositionX(user->getPositionX() + 2);
    }
    else
    {
        user->setPositionX(user->getPositionX() - 2);
    }
}
