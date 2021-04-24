#include "userinputcommandfactoryconcrete.h"

UserInputCommandFactoryConcrete::UserInputCommandFactoryConcrete(GameModel *model)
    : UserInputCommandFactory(model)
{

}

UserInputHandler *UserInputCommandFactoryConcrete::makeUserInputHandler(std::string key)
{
    return new UserInputHandler(model);
}
