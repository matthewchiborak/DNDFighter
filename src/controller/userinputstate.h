#ifndef USERINPUTSTATE_H
#define USERINPUTSTATE_H

#include "../model/gamemodel.h"

class UserInputState
{
public:
    UserInputState(GameModel * model);

    virtual void handleUserInput();

protected:
    GameModel * model;
};

#endif // USERINPUTSTATE_H
