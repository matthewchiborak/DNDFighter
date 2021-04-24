#ifndef USERINPUTHANDLER_H
#define USERINPUTHANDLER_H

#include <vector>

#include "../model/gamemodel.h"
#include "buttoncommand.h"

class UserInputHandler
{
public:
    UserInputHandler(GameModel * model);
    ~UserInputHandler();

    void addCommand(ButtonCommand * command);
    void handleUserInput();

protected:
    GameModel * model;

    std::vector<ButtonCommand*> buttonCommands;
};

#endif // USERINPUTHANDLER_H
