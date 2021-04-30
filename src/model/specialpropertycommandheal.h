#ifndef SPECIALPROPERTYCOMMANDHEAL_H
#define SPECIALPROPERTYCOMMANDHEAL_H

#include "specialpropertycommand.h"

class SpecialPropertyCommandHeal: public SpecialPropertyCommand
{
public:
    SpecialPropertyCommandHeal(BattleCharacter * user);

    void execute();
};

#endif // SPECIALPROPERTYCOMMANDHEAL_H
