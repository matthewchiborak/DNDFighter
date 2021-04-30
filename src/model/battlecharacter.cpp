#include "battlecharacter.h"

#include <QDebug>

BattleCharacter::BattleCharacter(std::string spriteKeyPrefix, MusicControllerAbstract *musicController)
{
    this->spriteKeyPrefix = spriteKeyPrefix;
    this->musicController = musicController;

    recovery = 0;
    hitstun = 0;
    height = 1.f;
    width = 1.4f;
    axisHorz = 0;
    axisVert = 0;
}

void BattleCharacter::setHorzAxis(int value)
{

}

void BattleCharacter::setVertAxis(int value)
{

}


void BattleCharacter::framePassed()
{

}

void BattleCharacter::punch()
{

}

void BattleCharacter::kick()
{

}

void BattleCharacter::special()
{

}

void BattleCharacter::jump()
{

}

bool BattleCharacter::forceJump(int dir)
{
    return false;
}

void BattleCharacter::doThrow()
{

}

void BattleCharacter::forceMove(float moveSpeed)
{

}

float BattleCharacter::getPositionX()
{
    return positionX;
}

void BattleCharacter::setPositionX(float value)
{
    positionX = value;
}

float BattleCharacter::getPositionY()
{
    return positionY;
}

void BattleCharacter::setPositionY(float value)
{
    positionY = value;
}

float BattleCharacter::getWidth()
{
    return width;
}

void BattleCharacter::setWidth(float value)
{
    this->width = value;
}

float BattleCharacter::getHeight()
{
    return height;
}

void BattleCharacter::setHeight(float value)
{
    this->height = value;
}

std::string BattleCharacter::getCurrentSprite()
{
    return "\\CharacterSprites\\" + spriteKeyPrefix + "\\" + currentSpriteKeySuffix + ".png";
}

std::string BattleCharacter::getSpriteKeyPrefix()
{
    return spriteKeyPrefix;
}

void BattleCharacter::applyGravity()
{

}

void BattleCharacter::doDamage(int amount, int hitStun, int blockStun, bool unblockable, int blockHeight)
{

}


float BattleCharacter::getHealthPercentage()
{
    return (float)currentHealth / float(maxHealth);
}

void BattleCharacter::setRecovery(int value)
{
    recovery = value;
}

void BattleCharacter::addHitBox(HitBox *value)
{
    if(value != nullptr)
    {
        activeHitBoxes.push_back(value);
        musicController->playSoundEffect("Attack");
    }
}

void BattleCharacter::setMaxHealth(int value)
{
    maxHealth = value;
}

void BattleCharacter::refillHealth()
{
    currentHealth = maxHealth;
}

void BattleCharacter::setWalkSpeed(float value)
{
    walkSpeed = value;
}

void BattleCharacter::setHorzJumpSpeed(float value)
{
    horzJumpSpeed = value;
}

void BattleCharacter::setPunchModel(AttackModel *model)
{
    this->punchModel = model;
}

void BattleCharacter::setKickModel(AttackModel *model)
{
    this->kickModel = model;
}

void BattleCharacter::setCrouchPunchModel(AttackModel *model)
{
    this->crouchPunchModel = model;
}

void BattleCharacter::setCrouchKickModel(AttackModel *model)
{
    this->crouchKickModel = model;
}

void BattleCharacter::setThrowModel(AttackModel *model)
{
    this->throwModel = model;
}

void BattleCharacter::setNeutralSpecialModel(AttackModel *model)
{
    this->neutralSpecialModel = model;
}

void BattleCharacter::setForwardSpecialModel(AttackModel *model)
{
    this->forwardSpecialModel = model;
}

void BattleCharacter::setDownSpecialModel(AttackModel *model)
{
    this->downSpecialModel = model;
}

void BattleCharacter::setHurtBox(float posx, float posy, float w, float h)
{

}

void BattleCharacter::setHurtBoxCrouch(float posx, float posy, float w, float h)
{

}

void BattleCharacter::advanceHitBoxes()
{

}

std::vector<HitBox *> *BattleCharacter::getActiveHitBoxes()
{
    return &activeHitBoxes;
}

float BattleCharacter::gethurtBoxPosX()
{
    if(axisVert < 0)
        return positionX + hurtBoxPosXCrouch;

    return positionX + hurtBoxPosX;
}

float BattleCharacter::gethurtBoxPosY()
{
    if(axisVert < 0)
        return positionY + hurtBoxPosYCrouch;

    return positionY + hurtBoxPosY;
}

float BattleCharacter::gethurtBoxHeight()
{
    if(axisVert < 0)
        return hurtBoxHeightCrouch;

    return hurtBoxHeight;
}

float BattleCharacter::gethurtBoxWidth()
{
    if(axisVert < 0)
        return hurtBoxWidthCrouch;

    return hurtBoxWidth;
}

void BattleCharacter::setIsFaceRight(bool isRight)
{

}

bool BattleCharacter::getIsFaceRight()
{
    return isFacingRight;
}

float BattleCharacter::getHurtBoxLeft()
{
    if(axisVert < 0)
        return positionX + hurtBoxPosXCrouch;

    return positionX + hurtBoxPosX;
}

float BattleCharacter::getHurtBoxRight()
{
    if(axisVert < 0)
        return positionX + hurtBoxPosXCrouch + hurtBoxWidthCrouch;

    return positionX + hurtBoxPosX + hurtBoxWidth;
}

void BattleCharacter::setPositionHurtBoxLeftRelative(float pos)
{
    if(axisVert < 0)
        positionX = pos - hurtBoxPosXCrouch;
    else
        positionX = pos - hurtBoxPosX;
}

void BattleCharacter::setPositionHurtBoxRightRelative(float pos)
{
    if(axisVert < 0)
        positionX = pos - hurtBoxPosXCrouch - hurtBoxWidthCrouch;
    else
        positionX = pos - hurtBoxPosX - hurtBoxWidth;
}

int BattleCharacter::getHorzAxis()
{
    return axisHorz;
}

float BattleCharacter::getWalkSpeed()
{
    return walkSpeed;
}

void BattleCharacter::setDamageMultiplier(float value)
{
    damageMultiplier = value;
}

void BattleCharacter::pushBack(float value)
{
    positionX += value;
}

bool BattleCharacter::wouldBlockThis(bool unblockable, int blockHeight)
{
    return false;
}

std::vector<std::string> *BattleCharacter::getAllSprites()
{
    return nullptr;
}
