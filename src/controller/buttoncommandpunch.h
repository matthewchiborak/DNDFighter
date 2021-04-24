#ifndef BUTTONCOMMANDPUNCH_H
#define BUTTONCOMMANDPUNCH_H

#include "buttoncommand.h"

class ButtonCommandPunch : public ButtonCommand
{
public:
    ButtonCommandPunch(GameModel * model, char keyChar, BattleCharacter * myCharacter);

    void execute();

private:
    bool buttonIsDown;
    BattleCharacter * myCharacter;
};

#endif // BUTTONCOMMANDPUNCH_H
