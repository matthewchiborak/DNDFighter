#ifndef USERINPUTSTATEBATTLE_H
#define USERINPUTSTATEBATTLE_H

#include "userinputstate.h"

class UserInputStateBattle : public UserInputState
{
public:
    UserInputStateBattle(GameModel * model);

    void handleUserInput();
};

#endif // USERINPUTSTATEBATTLE_H
