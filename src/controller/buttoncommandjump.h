#ifndef BUTTONCOMMANDJUMP_H
#define BUTTONCOMMANDJUMP_H

#include "buttoncommand.h"

class ButtonCommandJump : public ButtonCommand
{
public:
    ButtonCommandJump(GameModel * model, char keyChar, BattleCharacter * myCharacter);

    void execute();

private:
    bool buttonIsDown;
    BattleCharacter * myCharacter;
};

#endif // BUTTONCOMMANDJUMP_H
