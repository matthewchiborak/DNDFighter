#include "gamemodelconcrete.h"

#include <QDebug>

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
        //If collisde w/ p2 hurtbox or hitbox. do action;
        if(!character1->getActiveHitBoxes()->at(i)->isDone() && HitBox::boxCollisions(
                    character2->gethurtBoxPosX(),
                    character2->gethurtBoxPosY(),
                    character2->gethurtBoxWidth(),
                    character2->gethurtBoxHeight(),
                    character1->getActiveHitBoxes()->at(i)->getPosX(),
                    character1->getActiveHitBoxes()->at(i)->getPosY(),
                    character1->getActiveHitBoxes()->at(i)->getwidth(),
                    character1->getActiveHitBoxes()->at(i)->getheight()
                                 ))
        {
            //character2->doDamage(character1->getActiveHitBoxes()->at(i)->getdamage());
            //character2->applyHitStun(character1->getActiveHitBoxes()->at(i)->gethitstun());

            if(character1->getActiveHitBoxes()->at(i)->getforceAJumpSelf())
            {
                character1->forceJump(character1->getActiveHitBoxes()->at(i)->getforceJumpDir());
            }
            if(character1->getActiveHitBoxes()->at(i)->getforceAJumpEnemy())
            {
                if(character2->forceJump(character1->getActiveHitBoxes()->at(i)->getforceJumpDir()))
                {
                    character2->doDamage(character1->getActiveHitBoxes()->at(i)->getdamage());
                    character2->applyHitStun(character1->getActiveHitBoxes()->at(i)->gethitstun());
                }
            }
            else
            {
                character2->doDamage(character1->getActiveHitBoxes()->at(i)->getdamage());
                character2->applyHitStun(character1->getActiveHitBoxes()->at(i)->gethitstun());
            }

            character1->getActiveHitBoxes()->at(i)->makeDone();
        }
    }
    for(int i = 0; i < character2->getActiveHitBoxes()->size(); i++)
    {
        if(!character2->getActiveHitBoxes()->at(i)->isDone() && HitBox::boxCollisions(
                    character1->gethurtBoxPosX(),
                    character1->gethurtBoxPosY(),
                    character1->gethurtBoxWidth(),
                    character1->gethurtBoxHeight(),
                    character2->getActiveHitBoxes()->at(i)->getPosX(),
                    character2->getActiveHitBoxes()->at(i)->getPosY(),
                    character2->getActiveHitBoxes()->at(i)->getwidth(),
                    character2->getActiveHitBoxes()->at(i)->getheight()
                                 ))
        {
            if(character2->getActiveHitBoxes()->at(i)->getforceAJumpSelf())
            {
                character2->forceJump(character2->getActiveHitBoxes()->at(i)->getforceJumpDir());
            }
            if(character2->getActiveHitBoxes()->at(i)->getforceAJumpEnemy())
            {
                if(character1->forceJump(character2->getActiveHitBoxes()->at(i)->getforceJumpDir()))
                {
                    character1->doDamage(character2->getActiveHitBoxes()->at(i)->getdamage());
                    character1->applyHitStun(character2->getActiveHitBoxes()->at(i)->gethitstun());
                }
            }
            else
            {
                character1->doDamage(character2->getActiveHitBoxes()->at(i)->getdamage());
                character1->applyHitStun(character2->getActiveHitBoxes()->at(i)->gethitstun());
            }

            character2->getActiveHitBoxes()->at(i)->makeDone();
        }
    }
}
