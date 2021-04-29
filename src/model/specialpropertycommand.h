#ifndef SPECIALPROPERTYCOMMAND_H
#define SPECIALPROPERTYCOMMAND_H

#include "battlecharacter.h"

class SpecialPropertyCommand
{
public:
    SpecialPropertyCommand(BattleCharacter * user);

    virtual void execute();

protected:
    BattleCharacter * user;
};

#endif // SPECIALPROPERTYCOMMAND_H
