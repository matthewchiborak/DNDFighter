#ifndef BUTTONCOMMANDMENUENTER_H
#define BUTTONCOMMANDMENUENTER_H

#include "buttoncommand.h"

class ButtonCommandMenuEnter : public ButtonCommand
{
public:
    ButtonCommandMenuEnter(GameModel * model, char keyChar, std::string key);

    void execute();

private:
    bool buttonIsDown;
    std::string key;
};

#endif // BUTTONCOMMANDMENUENTER_H
