#ifndef USERINPUTCOMMANDFACTORYCONCRETE_H
#define USERINPUTCOMMANDFACTORYCONCRETE_H

#include "userinputcommandfactory.h"

class UserInputCommandFactoryConcrete : public UserInputCommandFactory
{
public:
    UserInputCommandFactoryConcrete(GameModel * model);

    UserInputHandler * makeUserInputHandler(std::string key);
};

#endif // USERINPUTCOMMANDFACTORYCONCRETE_H
