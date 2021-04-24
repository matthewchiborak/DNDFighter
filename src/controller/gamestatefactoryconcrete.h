#ifndef GAMESTATEFACTORYCONCRETE_H
#define GAMESTATEFACTORYCONCRETE_H

#include "gamestatefactoryabstract.h"

class GameStateFactoryConcrete : public GameStateFactoryAbstract
{
public:
    GameStateFactoryConcrete(GameModel * model);

    UserInputState * getUserInputState(std::string key);
    ViewDrawingStrat * getViewDrawingStrat(std::string key);
};

#endif // GAMESTATEFACTORYCONCRETE_H
