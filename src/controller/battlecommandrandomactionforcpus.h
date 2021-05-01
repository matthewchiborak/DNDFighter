#ifndef BATTLECOMMANDRANDOMACTIONFORCPUS_H
#define BATTLECOMMANDRANDOMACTIONFORCPUS_H

#include "buttoncommand.h"

class BattleCommandRandomActionForCPUs : public ButtonCommand
{
public:
    BattleCommandRandomActionForCPUs(GameModel * model, char keyChar, BattleCharacter * myCharacter);

    void execute();

private:
    bool buttonIsDown;
    BattleCharacter * myCharacter;
};

#endif // BATTLECOMMANDRANDOMACTIONFORCPUS_H
