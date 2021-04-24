#include "gamestatefactoryconcrete.h"

#include "userinputstatebattle.h"
#include "../view/viewdrawingstratbattle.h"

GameStateFactoryConcrete::GameStateFactoryConcrete(GameModel *model)
    : GameStateFactoryAbstract(model)
{

}

UserInputState *GameStateFactoryConcrete::getUserInputState(std::string key)
{
    return new UserInputStateBattle(model);
}

ViewDrawingStrat *GameStateFactoryConcrete::getViewDrawingStrat(std::string key)
{
    return new ViewDrawingStratBattle(model);
}
