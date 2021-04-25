#include "battlecharacter.h"

#include <QDebug>

BattleCharacter::BattleCharacter(std::string spriteKeyPrefix, float walkSpeed, int health)
{
    this->currentHealth = health;
    this->maxHealth = health;

    this->spriteKeyPrefix = spriteKeyPrefix;

    this->walkSpeed = walkSpeed;
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

void BattleCharacter::move(double dir)
{

}

void BattleCharacter::special(std::string key)
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

float BattleCharacter::getHealthPercentage()
{
    return (float)currentHealth / float(maxHealth);
}
