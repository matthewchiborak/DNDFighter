#ifndef SPECIALPROPERTYCOMMANDDP_H
#define SPECIALPROPERTYCOMMANDDP_H

#include "specialpropertycommand.h"

class SpecialPropertyCommandDP : public SpecialPropertyCommand
{
public:
    SpecialPropertyCommandDP(BattleCharacter * user);

    void execute();
};

#endif // SPECIALPROPERTYCOMMANDDP_H
