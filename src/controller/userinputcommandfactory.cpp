#include "userinputcommandfactory.h"

UserInputCommandFactory::UserInputCommandFactory(GameModel *model)
{
    this->model = model;
}

UserInputHandler *UserInputCommandFactory::makeUserInputHandler(std::string key)
{
    return nullptr;
}
