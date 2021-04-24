#include "gamemodelconcrete.h"

GameModelConcrete::GameModelConcrete()
    : GameModel()
{

}

void GameModelConcrete::framePassed()
{
    character1->framePassed();
    character2->framePassed();

    character1->applyGravity();
    character2->applyGravity();
}
