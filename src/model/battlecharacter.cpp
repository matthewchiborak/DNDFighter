#include "battlecharacter.h"

#include <QDebug>

BattleCharacter::BattleCharacter(std::string spriteKeyPrefix, float walkSpeed)
{
    isCrouching = false;
    this->spriteKeyPrefix = spriteKeyPrefix;

    this->walkSpeed = walkSpeed;
    recovery = 0;
    height = 1.f;
    width = 1.f;
}

void BattleCharacter::setIsCrouching(bool value)
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

void BattleCharacter::move(double dir)
{

}

void BattleCharacter::special(std::string key)
{

}

void BattleCharacter::jump()
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
    return "\\" + spriteKeyPrefix + "\\" + currentSpriteKeySuffix + ".png";
}

void BattleCharacter::applyGravity()
{

}
