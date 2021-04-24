#ifndef GAMESTATEFACTORYABSTRACT_H
#define GAMESTATEFACTORYABSTRACT_H

#include <string>

#include "userinputstate.h"
#include "../view/viewdrawingstrat.h"
#include "../model/gamemodel.h"

class GameStateFactoryAbstract
{
public:
    GameStateFactoryAbstract(GameModel * model);

    virtual UserInputState * getUserInputState(std::string key);
    virtual ViewDrawingStrat * getViewDrawingStrat(std::string key);

protected:
    GameModel * model;
};

#endif // GAMESTATEFACTORYABSTRACT_H
