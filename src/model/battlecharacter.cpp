#include "battlecharacter.h"

#include <QDebug>

BattleCharacter::BattleCharacter(std::string spriteKeyPrefix)
{
    this->spriteKeyPrefix = spriteKeyPrefix;

    recovery = 0;
    height = 1.f;
    width = 1.f;
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

void BattleCharacter::doThrow()
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

void BattleCharacter::doDamage(int amount)
{
    currentHealth -= amount;

    if(currentHealth > maxHealth)
        currentHealth = maxHealth;
    if(currentHealth < 0)
        currentHealth = 0;
}

void BattleCharacter::applyHitStun(int hitStun)
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
        activeHitBoxes.push_back(value);
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
