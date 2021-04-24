#ifndef BUTTONCOMMANDMOVE_H
#define BUTTONCOMMANDMOVE_H

#include "buttoncommand.h"

#include <chrono>

class ButtonCommandMoveForward : public ButtonCommand
{
public:
    ButtonCommandMoveForward(GameModel * model, char keyChar, BattleCharacter * myCharacter, int dir);

    void execute();

private:
    bool buttonIsDown;
    int dir;
    BattleCharacter * myCharacter;

    long long theTimeNow;
    long long timeOfLastButtonEvent;
    double elapsed_millies;

    void handleKeyDown();
    void handleKeyHold();
    void handleKeyUp();
};

#endif // BUTTONCOMMANDMOVE_H
