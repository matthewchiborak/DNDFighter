#include "gamemodelconcrete.h"

#include <QDebug>

GameModelConcrete::GameModelConcrete(std::string characterListFile, MusicControllerAbstract * musicController)
    : GameModel(characterListFile, musicController)
{

}

void GameModelConcrete::framePassed()
{
    character1->framePassed();
    character2->framePassed();

    handleSideSwitch();
    applyPhysics();
    advanceHitBoxes();
    handleHitBoxOnHitBoxCollisions();
    handleCollisions();
    handleHurtBoxRestrictions();
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
                if(!character2->wouldBlockThis(character1->getActiveHitBoxes()->at(i)->getIsUnblockable(),
                                               character1->getActiveHitBoxes()->at(i)->getheightForBlocking()))
                {
                    if(character2->forceJump(character1->getActiveHitBoxes()->at(i)->getforceJumpDir()))
                    {
                        character2->doDamage(character1->getActiveHitBoxes()->at(i)->getdamage(),
                                             character1->getActiveHitBoxes()->at(i)->gethitstun(), 0,
                                             character1->getActiveHitBoxes()->at(i)->getIsUnblockable(),
                                             character1->getActiveHitBoxes()->at(i)->getheightForBlocking());
                    }
                }
            }
            else
            {
                character2->doDamage(character1->getActiveHitBoxes()->at(i)->getdamage(),
                                     character1->getActiveHitBoxes()->at(i)->gethitstun(), 0,
                                     character1->getActiveHitBoxes()->at(i)->getIsUnblockable(),
                                     character1->getActiveHitBoxes()->at(i)->getheightForBlocking());
            }

            //Pushback
            if(character1->getPositionX() < character2->getPositionX())
            {
                if(!character1->getActiveHitBoxes()->at(i)->isAProjectile())
                    character1->pushBack(-0.05f);

                character2->pushBack(0.05f);
            }
            else
            {
                if(!character1->getActiveHitBoxes()->at(i)->isAProjectile())
                    character1->pushBack(0.05f);

                character2->pushBack(-0.05f);
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
                if(!character1->wouldBlockThis(character2->getActiveHitBoxes()->at(i)->getIsUnblockable(),
                                               character2->getActiveHitBoxes()->at(i)->getheightForBlocking()))
                {
                    if(character1->forceJump(character2->getActiveHitBoxes()->at(i)->getforceJumpDir()))
                    {
                        character1->doDamage(character2->getActiveHitBoxes()->at(i)->getdamage(),
                                             character2->getActiveHitBoxes()->at(i)->gethitstun(), 0,
                                             character2->getActiveHitBoxes()->at(i)->getIsUnblockable(),
                                             character2->getActiveHitBoxes()->at(i)->getheightForBlocking());
                    }
                }
            }
            else
            {
                character1->doDamage(character2->getActiveHitBoxes()->at(i)->getdamage(),
                                     character2->getActiveHitBoxes()->at(i)->gethitstun(), 0,
                                     character2->getActiveHitBoxes()->at(i)->getIsUnblockable(),
                                     character2->getActiveHitBoxes()->at(i)->getheightForBlocking());
            }

            //Pushback
            if(character1->getPositionX() < character2->getPositionX())
            {
                character1->pushBack(-0.05f);
                if(!character2->getActiveHitBoxes()->at(i)->isAProjectile())
                    character2->pushBack(0.05f);
            }
            else
            {
                character1->pushBack(0.05f);
                if(!character2->getActiveHitBoxes()->at(i)->isAProjectile())
                    character2->pushBack(-0.05f);
            }

            character2->getActiveHitBoxes()->at(i)->makeDone();
        }
    }
}

void GameModelConcrete::handleHitBoxOnHitBoxCollisions()
{
    for(int i = 0; i < character1->getActiveHitBoxes()->size(); i++)
    {
        if(character1->getActiveHitBoxes()->at(i)->isDone())
            continue;

        for(int j = 0; j < character2->getActiveHitBoxes()->size(); j++)
        {
            if(character2->getActiveHitBoxes()->at(j)->isDone())
                continue;

            if(character1->getActiveHitBoxes()->at(i)->isAProjectile() && character2->getActiveHitBoxes()->at(j)->isAProjectile())
            {
                if(HitBox::boxCollisions(
                            character1->getActiveHitBoxes()->at(i)->getPosX(),
                            character1->getActiveHitBoxes()->at(i)->getPosY(),
                            character1->getActiveHitBoxes()->at(i)->getwidth(),
                            character1->getActiveHitBoxes()->at(i)->getheight(),
                            character2->getActiveHitBoxes()->at(j)->getPosX(),
                            character2->getActiveHitBoxes()->at(j)->getPosY(),
                            character2->getActiveHitBoxes()->at(j)->getwidth(),
                            character2->getActiveHitBoxes()->at(j)->getheight()
                            ))
                {
                    //Cancel them
                    character1->getActiveHitBoxes()->at(i)->makeDone();
                    character2->getActiveHitBoxes()->at(j)->makeDone();
                }
            }
        }
    }
}

void GameModelConcrete::handleHurtBoxRestrictions()
{
    if(character1->getHurtBoxLeft() < -1.77f)
        character1->setPositionHurtBoxLeftRelative(-1.77f);
    if(character2->getHurtBoxLeft() < -1.77f)
        character2->setPositionHurtBoxLeftRelative(-1.77f);

    if(character1->getHurtBoxRight() > 1.77f)
        character1->setPositionHurtBoxRightRelative(1.77f);
    if(character2->getHurtBoxRight() > 1.77f)
        character2->setPositionHurtBoxRightRelative(1.77f);

    //if(character1->getPositionY() < (character2->getPositionY() + character2->getHeight()) || character2->getPositionY() < (character1->getPositionY() + character1->getHeight()))
    //If over the head
    if(character1->getPositionY() > character2->getPositionY() + character2->gethurtBoxHeight())
    {
        //If in the corner swap
        //If 2 is in corner and 1 is jumping over him, push p2 slightly forward
        if(character1->getHurtBoxLeft() <= -1.77f && character2->getHurtBoxLeft() <= -1.77f)
        {
            character2->setPositionHurtBoxLeftRelative(-1.75f);
        }
        else if(character1->getHurtBoxRight() >= 1.77f && character2->getHurtBoxRight() >= 1.77f)
        {
            character2->setPositionHurtBoxRightRelative(1.75f);
        }

        return;
    }
    if(character2->getPositionY() > character1->getPositionY() + character1->gethurtBoxHeight())
    {
        //If in the corner swap
        //If 1 is in corner and 2 is jumping over him, push p1 slightly forward
        if(character2->getHurtBoxLeft() <= -1.77f && character1->getHurtBoxLeft() <= -1.77f)
        {
            character1->setPositionHurtBoxLeftRelative(-1.75f);
        }
        else if(character2->getHurtBoxRight() >= 1.77f && character1->getHurtBoxRight() >= 1.77f)
        {
            character1->setPositionHurtBoxRightRelative(1.75f);
        }

        return;
    }


    if(character1->getPositionX() < character2->getPositionX())
    {
        if(character1->getHurtBoxRight() > character2->getHurtBoxLeft())
        {
            if((character2->getHorzAxis() < 0 && character1->getHorzAxis() == 0) || (character1->getPositionY() > 0 && character2->getPositionY() <= 0))
            {
                character1->setPositionHurtBoxRightRelative(character2->getHurtBoxLeft());
                //If pushoffscreenfixit
                if(character1->getHurtBoxLeft() < -1.77f)
                {
                    character1->setPositionHurtBoxLeftRelative(-1.77f);
                    character2->setPositionHurtBoxLeftRelative(-1.77f + character1->gethurtBoxWidth());
                }
            }
            else if((character1->getHorzAxis() > 0 && character2->getHorzAxis() == 0) || (character2->getPositionY() > 0 && character1->getPositionY() <= 0))
            {
                character2->setPositionHurtBoxLeftRelative(character1->getHurtBoxRight());
                //If pushoffscreenfixit
                if(character2->getHurtBoxRight() > 1.77f)
                {
                    character2->setPositionHurtBoxRightRelative(1.77f);
                    character1->setPositionHurtBoxRightRelative(1.77f - character2->gethurtBoxWidth());
                }
            }
            else
            {
                float midX = (character1->getHurtBoxRight() + character2->getHurtBoxLeft()) / 2;
                character1->setPositionHurtBoxRightRelative(midX);
                character2->setPositionHurtBoxLeftRelative(midX);
            }
        }
    }
    else
    {
        if(character2->getHurtBoxRight() > character1->getHurtBoxLeft())
        {
            if((character1->getHorzAxis() < 0 && character2->getHorzAxis() == 0) || (character2->getPositionY() > 0 && character1->getPositionY() <= 0))
            {
                character2->setPositionHurtBoxRightRelative(character1->getHurtBoxLeft());
                //If pushoffscreenfixit
                if(character2->getHurtBoxLeft() < -1.77f)
                {
                    character2->setPositionHurtBoxLeftRelative(-1.77f);
                    character1->setPositionHurtBoxLeftRelative(-1.77f + character2->gethurtBoxWidth());
                }
            }
            else if((character2->getHorzAxis() > 0 && character1->getHorzAxis() == 0) || (character1->getPositionY() > 0 && character2->getPositionY() <= 0))
            {
                character1->setPositionHurtBoxLeftRelative(character2->getHurtBoxRight());
                //If pushoffscreenfixit
                if(character1->getHurtBoxRight() > 1.77f)
                {
                    character1->setPositionHurtBoxRightRelative(1.77f);
                    character2->setPositionHurtBoxRightRelative(1.77f - character1->gethurtBoxWidth());
                }
            }
            else
            {
                float midX = (character2->getHurtBoxRight() + character1->getHurtBoxLeft()) / 2;
                character2->setPositionHurtBoxRightRelative(midX);
                character1->setPositionHurtBoxLeftRelative(midX);
            }
        }
    }




}

void GameModelConcrete::handleSideSwitch()
{
    if(character1->getPositionX() < character2->getPositionX())
    {
        character1->setIsFaceRight(true);
        character2->setIsFaceRight(false);
    }
    else
    {
        character1->setIsFaceRight(false);
        character2->setIsFaceRight(true);
    }
}




