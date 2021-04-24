#include "gamestatefactoryconcrete.h"

#include "../view/viewdrawingstratbattle.h"

GameStateFactoryConcrete::GameStateFactoryConcrete(GameModel *model)
    : GameStateFactoryAbstract(model)
{

}

ViewDrawingStrat *GameStateFactoryConcrete::getViewDrawingStrat(std::string key)
{
    if(key == "Battle")
        return new ViewDrawingStratBattle(model);

    return new ViewDrawingStratBattle(model);
}
