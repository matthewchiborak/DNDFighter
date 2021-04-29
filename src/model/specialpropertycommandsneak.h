#ifndef SPECIALPROPERTYCOMMANDSNEAK_H
#define SPECIALPROPERTYCOMMANDSNEAK_H

#include "specialpropertycommand.h"

class SpecialPropertyCommandSneak : public SpecialPropertyCommand
{
public:
    SpecialPropertyCommandSneak(BattleCharacter * user);

    void execute();
};

#endif // SPECIALPROPERTYCOMMANDSNEAK_H
