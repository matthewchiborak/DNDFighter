#ifndef BUTTONCOMMAND_H
#define BUTTONCOMMAND_H

#include "../model/gamemodel.h"

class ButtonCommand
{
public:
    ButtonCommand(GameModel * model, char keyChar);
    virtual ~ButtonCommand() = 0;

    virtual void execute();

protected:
    GameModel * model;
    char keyChar;
};

#endif // BUTTONCOMMAND_H
