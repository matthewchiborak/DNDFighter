#include "gamestatefactoryconcrete.h"

#include "../view/viewdrawingstratbattle.h"
#include "../view/viewdrawingstratcharacterselect.h"

GameStateFactoryConcrete::GameStateFactoryConcrete(GameModel *model)
    : GameStateFactoryAbstract(model)
{

}

ViewDrawingStrat *GameStateFactoryConcrete::getViewDrawingStrat(std::string key)
{
    if(key == "Battle")
        return new ViewDrawingStratBattle(model);
    if(key == "CharacterSelect")
        return new ViewDrawingStratCharacterSelect(model);

    return new ViewDrawingStratBattle(model);
}
