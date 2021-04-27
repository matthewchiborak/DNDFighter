#include "gamemodelconcrete.h"

GameModelConcrete::GameModelConcrete()
    : GameModel()
{

}

void GameModelConcrete::framePassed()
{
    character1->framePassed();
    character2->framePassed();

    applyPhysics();
    advanceHitBoxes();
    handleCollisions();
}

void GameModelConcrete::applyPhysics()
{
    character1->applyGravity();
    character2->applyGravity();
}

void GameModelConcrete::advanceHitBoxes()
{
    character1->advanceHitBoxes();
    character2->advanceHitBoxes();
}

void GameModelConcrete::handleCollisions()
{
    for(int i = 0; i < character1->getActiveHitBoxes()->size(); i++)
    {

    }
    for(int i = 0; i < character2->getActiveHitBoxes()->size(); i++)
    {

    }
}
