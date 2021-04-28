#ifndef GAMEMODELCONCRETE_H
#define GAMEMODELCONCRETE_H

#include "gamemodel.h"

class GameModelConcrete : public GameModel
{
public:
    GameModelConcrete();

    void framePassed();

private:
    void applyPhysics();
    void advanceHitBoxes();
    void handleCollisions();
    void handleHurtBoxRestrictions();
    void handleSideSwitch();
};

#endif // GAMEMODELCONCRETE_H
