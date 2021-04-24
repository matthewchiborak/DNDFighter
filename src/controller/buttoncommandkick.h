#ifndef BUTTONCOMMANDKICK_H
#define BUTTONCOMMANDKICK_H

#include "buttoncommand.h"

class ButtonCommandKick : public ButtonCommand
{
public:
    ButtonCommandKick(GameModel * model, char keyChar, BattleCharacter * myCharacter);

    void execute();

private:
    bool buttonIsDown;
    BattleCharacter * myCharacter;
};

#endif // BUTTONCOMMANDKICK_H
