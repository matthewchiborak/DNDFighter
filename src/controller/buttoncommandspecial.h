#ifndef BUTTONCOMMANDSPECIAL_H
#define BUTTONCOMMANDSPECIAL_H

#include "buttoncommand.h"

class ButtonCommandSpecial : public ButtonCommand
{
public:
    ButtonCommandSpecial(GameModel * model, char keyChar, BattleCharacter * myCharacter);

private:
    void execute();

private:
    bool buttonIsDown;
    BattleCharacter * myCharacter;
};

#endif // BUTTONCOMMANDSPECIAL_H
