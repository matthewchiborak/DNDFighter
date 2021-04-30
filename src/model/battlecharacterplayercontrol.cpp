#include "battlecharacterplayercontrol.h"

#include <QDebug>

BattleCharacterPlayerControl::BattleCharacterPlayerControl(std::string spriteKeyPrefix, MusicControllerAbstract *musicController)
    : BattleCharacter(spriteKeyPrefix, musicController)
{
    this->currentSpriteKeySuffix = "Idle";
}

void BattleCharacterPlayerControl::framePassed()
{
    if(recovery > 0)
    {
        recovery--;
        hitstun--;

        if(isForceMoving)
        {
            positionX += (forceMoveSpeed);
        }

        return;
    }

    if(isForceMoving)
        isForceMoving = false;
    if(damageMultiplier < 1 || damageMultiplier > 1)
        damageMultiplier = 1;

    if(axisVert < 0)
    {
        this->currentSpriteKeySuffix = "CrouchIdle";
        return;
    }

    if(axisHorz != 0 && positionY <= 0)
    {
        walkCount++;
        if(walkCount > framesPerWalk)
        {
            if(walkState)
                this->currentSpriteKeySuffix = "Idle";
            else if(!walkState)
                this->currentSpriteKeySuffix = "Walk";

            walkState = !walkState;
            walkCount = 0;
        }
        positionX += (walkSpeed * axisHorz);
        return;
    }

    this->currentSpriteKeySuffix = "Idle";
}

void BattleCharacterPlayerControl::setHorzAxis(int value)
{
    axisHorz = value;
}

void BattleCharacterPlayerControl::setVertAxis(int value)
{
    axisVert = value;
}

void BattleCharacterPlayerControl::punch()
{
    if(recovery > 0)
        return;

    if(axisVert >= 0)
    {
        currentSpriteKeySuffix = "Punch";
        addHitBox(punchModel->applyAttack(positionX, positionY, axisHorz));
    }
    else
    {
        currentSpriteKeySuffix = "CrouchPunch";
        addHitBox(crouchPunchModel->applyAttack(positionX, positionY, axisHorz));
    }
}

void BattleCharacterPlayerControl::kick()
{
    if(recovery > 0)
        return;

    if(axisVert >= 0)
    {
        currentSpriteKeySuffix = "Kick";
        addHitBox(kickModel->applyAttack(positionX, positionY, axisHorz));
    }
    else
    {
        currentSpriteKeySuffix = "CrouchKick";
        addHitBox(crouchKickModel->applyAttack(positionX, positionY, axisHorz));
    }
}

void BattleCharacterPlayerControl::special()
{
    if(recovery > 0)
        return;

    if(positionY > 0)
        return;

    if(axisVert < 0)
    {
        currentSpriteKeySuffix = "DownSpecial";
        addHitBox(downSpecialModel->applyAttack(positionX, positionY, axisHorz));
    }
    else if(axisHorz != 0)
    {
        currentSpriteKeySuffix = "ForwardSpecial";
        addHitBox(forwardSpecialModel->applyAttack(positionX, positionY, axisHorz));
    }
    else if(axisHorz == 0 && axisVert == 0)
    {
        currentSpriteKeySuffix = "NeutralSpecial";
        addHitBox(neutralSpecialModel->applyAttack(positionX, positionY, axisHorz));
    }
}

void BattleCharacterPlayerControl::jump()
{
    if(recovery > 0)
        return;

    if(positionY > 0)
        return;

    lockedDir = axisHorz;
    jumpStartingHeight = positionY;
    framesSinceLastJump = 0;
}

bool BattleCharacterPlayerControl::forceJump(int dir)
{
    if(hitstun > 0)
        return false;

    if(positionY > 0)
        return false;

    lockedDir = dir;
    jumpStartingHeight = positionY;
    framesSinceLastJump = 0;
    return true;
}

void BattleCharacterPlayerControl::doThrow()
{
    if(recovery > 0)
        return;

    if(positionY > 0)
        return;

    currentSpriteKeySuffix = "Throw";

    if(isFacingRight)
    {
        if(axisHorz == 0)
            addHitBox(throwModel->applyAttack(positionX, positionY, 1));
        else
            addHitBox(throwModel->applyAttack(positionX, positionY, axisHorz));
    }
    else
    {
        if(axisHorz == 0)
            addHitBox(throwModel->applyAttack(positionX, positionY, -1));
        else
            addHitBox(throwModel->applyAttack(positionX, positionY, axisHorz));
    }
}

void BattleCharacterPlayerControl::forceMove(float moveSpeed)
{
    forceMoveSpeed = moveSpeed;
    isForceMoving = true;
}

void BattleCharacterPlayerControl::applyGravity()
{
    //x = x0 + v0t + 0.5at^2
    framesSinceLastJump++;

    potentialJumpPos = jumpStartingHeight + (jumpVelo*framesSinceLastJump) + (0.5f * gravity * (framesSinceLastJump*framesSinceLastJump));

    if(potentialJumpPos > 0)
    {
        positionX += (horzJumpSpeed * lockedDir);
        setPositionY(potentialJumpPos);
    }
    else
        setPositionY(0);

}

void BattleCharacterPlayerControl::doDamage(int amount, int hitStun, int blockStun, bool unblockable, int blockHeight)
{
    //If blocking dont go farther
    //Cant block if you're recovering
    //Cant block in air
    if(positionY <= 0)
    {
        if(!unblockable)
        {
            if(recovery <= 0)
            {
                if(isFacingRight && axisHorz < 0)
                {
                    if(blockHeight == 1 || (blockHeight == 0 && axisVert < 0) || (blockHeight == 2 && axisVert == 0))
                    {
                        musicController->playSoundEffect("Block");
                        return;
                    }
                }
                if(!isFacingRight && axisHorz > 0)
                {
                    if(blockHeight == 1 || (blockHeight == 0 && axisVert < 0) || (blockHeight == 2 && axisVert == 0))
                    {
                        musicController->playSoundEffect("Block");
                        return;
                    }
                }
            }
        }
    }

    currentHealth -= (amount * damageMultiplier);

     if(currentHealth > maxHealth)
         currentHealth = maxHealth;
     if(currentHealth < 0)
         currentHealth = 0;

     if(damageMultiplier > 0)
     {
         musicController->playSoundEffect("Hit");
         recovery = hitStun;
         this->hitstun = hitStun;
         currentSpriteKeySuffix = "Hit";
     }

     //If in the air, fly backwards
     if(positionY > 0)
     {
         if(isFacingRight)
             forceJumpFromMidAirHit(-1);
         else
             forceJumpFromMidAirHit(1);
     }
}

bool BattleCharacterPlayerControl::wouldBlockThis(bool unblockable, int blockHeight)
{
    //If blocking dont go farther
    //Cant block if you're recovering
    //Cant block in air
    if(positionY <= 0)
    {
        if(!unblockable)
        {
            if(recovery <= 0)
            {
                if(isFacingRight && axisHorz < 0)
                {
                    if(blockHeight == 1 || (blockHeight == 0 && axisVert < 0) || (blockHeight == 2 && axisVert == 0))
                        return true;
                }
                if(!isFacingRight && axisHorz > 0)
                {
                    if(blockHeight == 1 || (blockHeight == 0 && axisVert < 0) || (blockHeight == 2 && axisVert == 0))
                        return true;
                }
            }
        }
    }

    return false;
}

void BattleCharacterPlayerControl::forceJumpFromMidAirHit(int dir)
{
    lockedDir = dir;
    jumpStartingHeight = positionY;
    framesSinceLastJump = 0;
}

void BattleCharacterPlayerControl::setHurtBox(float posx, float posy, float w, float h)
{
    this->hurtBoxPosX = posx;
    this->hurtBoxPosY = posy;
    this->hurtBoxWidth = w;
    this->hurtBoxHeight = h;
}

void BattleCharacterPlayerControl::setHurtBoxCrouch(float posx, float posy, float w, float h)
{
    this->hurtBoxPosXCrouch = posx;
    this->hurtBoxPosYCrouch = posy;
    this->hurtBoxWidthCrouch = w;
    this->hurtBoxHeightCrouch = h;
}

void BattleCharacterPlayerControl::advanceHitBoxes()
{
    std::vector<HitBox*> toKeep;
    std::vector<HitBox*> toTrash;

    for(int i = 0; i < activeHitBoxes.size(); i++)
    {
        if(activeHitBoxes.at(i)->getisFixedToCharacter())
        {
            activeHitBoxes.at(i)->setPos(positionX, positionY);
        }

        activeHitBoxes.at(i)->advance();

        if(activeHitBoxes.at(i)->isDone())
        {
            toTrash.push_back(activeHitBoxes.at(i));
        }
        else
        {
            toKeep.push_back(activeHitBoxes.at(i));
        }
    }

    activeHitBoxes.clear();
    for(int i = 0; i < toKeep.size(); i++)
    {
        activeHitBoxes.push_back(toKeep.at(i));
    }
    for(int i = 0; i < toTrash.size(); i++)
    {
        delete toTrash.at(i);
    }
}

void BattleCharacterPlayerControl::setIsFaceRight(bool isRight)
{
    if(recovery > 0)
        return;

    isFacingRight = isRight;
}

std::vector<std::string> *BattleCharacterPlayerControl::getAllSprites()
{
    std::vector<std::string> * allSprites = new std::vector<std::string>();

    allSprites->push_back("\\CharacterSprites\\" + spriteKeyPrefix + "\\Idle.png");
    allSprites->push_back("\\CharacterSprites\\" + spriteKeyPrefix + "\\Punch.png");
    allSprites->push_back("\\CharacterSprites\\" + spriteKeyPrefix + "\\Kick.png");
    allSprites->push_back("\\CharacterSprites\\" + spriteKeyPrefix + "\\Walk.png");
    allSprites->push_back("\\CharacterSprites\\" + spriteKeyPrefix + "\\CrouchIdle.png");
    allSprites->push_back("\\CharacterSprites\\" + spriteKeyPrefix + "\\CrouchPunch.png");
    allSprites->push_back("\\CharacterSprites\\" + spriteKeyPrefix + "\\CrouchKick.png");
    allSprites->push_back("\\CharacterSprites\\" + spriteKeyPrefix + "\\Hit.png");
    allSprites->push_back("\\CharacterSprites\\" + spriteKeyPrefix + "\\DownSpecial.png");
    allSprites->push_back("\\CharacterSprites\\" + spriteKeyPrefix + "\\ForwardSpecial.png");
    allSprites->push_back("\\CharacterSprites\\" + spriteKeyPrefix + "\\NeutralSpecial.png");
    allSprites->push_back("\\CharacterSprites\\" + spriteKeyPrefix + "\\Throw.png");

    allSprites->push_back("\\CharacterSprites\\" + spriteKeyPrefix + "\\" +
                          neutralSpecialModel->getHitBoxSprite() + ".png");
    allSprites->push_back("\\CharacterSprites\\" + spriteKeyPrefix + "\\" +
                          downSpecialModel->getHitBoxSprite() + ".png");
    allSprites->push_back("\\CharacterSprites\\" + spriteKeyPrefix + "\\" +
                          forwardSpecialModel->getHitBoxSprite() + ".png");


    return allSprites;
}

