#ifndef BUTTONCOMMANDMENUCANCEL_H
#define BUTTONCOMMANDMENUCANCEL_H

#include "buttoncommand.h"

class ButtonCommandMenuCancel : public ButtonCommand
{
public:
    ButtonCommandMenuCancel(GameModel * model, char keyChar);

    void execute();

private:
    bool buttonIsDown;
};

#endif // BUTTONCOMMANDMENUCANCEL_H
