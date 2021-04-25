#ifndef BUTTONCOMMANDTHROW_H
#define BUTTONCOMMANDTHROW_H

#include "buttoncommand.h"

class ButtonCommandThrow : public ButtonCommand
{
public:
    ButtonCommandThrow(GameModel * model, char keyChar, BattleCharacter * myCharacter);

    void execute();

private:
    bool buttonIsDown;
    BattleCharacter * myCharacter;
};

#endif // BUTTONCOMMANDTHROW_H
