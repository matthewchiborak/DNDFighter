#ifndef USERINPUTCOMMANDFACTORY_H
#define USERINPUTCOMMANDFACTORY_H

#include <string>

#include "userinputhandler.h"

class UserInputCommandFactory
{
public:
    UserInputCommandFactory(GameModel * model);

    virtual UserInputHandler * makeUserInputHandler(std::string key);

protected:
    GameModel * model;
};

#endif // USERINPUTCOMMANDFACTORY_H
