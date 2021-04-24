#include "gamestatefactoryabstract.h"

GameStateFactoryAbstract::GameStateFactoryAbstract(GameModel * model)
{
    this->model = model;
}

ViewDrawingStrat *GameStateFactoryAbstract::getViewDrawingStrat(std::string key)
{
    return nullptr;
}
