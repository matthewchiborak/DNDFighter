#ifndef GAMEMODELCONCRETE_H
#define GAMEMODELCONCRETE_H

#include "gamemodel.h"

class GameModelConcrete : public GameModel
{
public:
    GameModelConcrete(std::string characterListFile, MusicControllerAbstract * musicController);

    void framePassed();

    bool gameIsDone();



private:
    void applyPhysics();
    void advanceHitBoxes();
    void handleCollisions();
    void handleHitBoxOnHitBoxCollisions();
    void handleHurtBoxRestrictions();
    void handleSideSwitch();
    void checkForWin();

};

#endif // GAMEMODELCONCRETE_H
