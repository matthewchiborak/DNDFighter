#ifndef BUTTONCOMMANDCROUCH_H
#define BUTTONCOMMANDCROUCH_H

#include "buttoncommand.h"

class ButtonCommandCrouch : public ButtonCommand
{
public:
    ButtonCommandCrouch(GameModel * model, char keyChar, BattleCharacter * myCharacter);

    void execute();

private:
    BattleCharacter * myCharacter;
};

#endif // BUTTONCOMMANDCROUCH_H
