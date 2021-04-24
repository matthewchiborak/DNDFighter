#include "gamestatefactoryabstract.h"

GameStateFactoryAbstract::GameStateFactoryAbstract(GameModel * model)
{
    this->model = model;
}

UserInputState *GameStateFactoryAbstract::getUserInputState(std::string key)
{
    return nullptr;
}

ViewDrawingStrat *GameStateFactoryAbstract::getViewDrawingStrat(std::string key)
{
    return nullptr;
}
