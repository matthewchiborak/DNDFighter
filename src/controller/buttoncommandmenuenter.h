#ifndef BUTTONCOMMANDMENUENTER_H
#define BUTTONCOMMANDMENUENTER_H

#include "buttoncommand.h"

class ButtonCommandMenuEnter : public ButtonCommand
{
public:
    ButtonCommandMenuEnter(GameModel * model, char keyChar);

    void execute();

private:
    bool buttonIsDown;
};

#endif // BUTTONCOMMANDMENUENTER_H
