#ifndef BUTTONCOMMANDMENUMOVE_H
#define BUTTONCOMMANDMENUMOVE_H

#include "buttoncommand.h"

class ButtonCommandMenuMove : public ButtonCommand
{
public:
    ButtonCommandMenuMove(GameModel * model, char keyUp, char keyDown, char keyLeft, char keyRight);

    void execute();

private:
    bool buttonIsDown;
    char keyUp, keyDown, keyLeft, keyRight;
};

#endif // BUTTONCOMMANDMENUMOVE_H
