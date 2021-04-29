#ifndef SPECIALPROPERTYCOMMANDSTINGER_H
#define SPECIALPROPERTYCOMMANDSTINGER_H

#include "specialpropertycommand.h"

class SpecialPropertyCommandStinger : public SpecialPropertyCommand
{
public:
    SpecialPropertyCommandStinger(BattleCharacter * user);

    void execute();
};

#endif // SPECIALPROPERTYCOMMANDSTINGER_H
