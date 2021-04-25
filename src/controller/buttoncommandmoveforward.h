#ifndef BUTTONCOMMANDMOVE_H
#define BUTTONCOMMANDMOVE_H

#include "buttoncommand.h"

#include <chrono>

class ButtonCommandMoveForward : public ButtonCommand
{
public:
    ButtonCommandMoveForward(GameModel * model, char keyChar, BattleCharacter * myCharacter, char oppositeKeyChar);

    void execute();

private:
    char oppositeKeyChar;
    BattleCharacter * myCharacter;
};

#endif // BUTTONCOMMANDMOVE_H
