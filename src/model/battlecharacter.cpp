#include "battlecharacter.h"

#include <QDebug>

BattleCharacter::BattleCharacter(std::string spriteKeyPrefix)
{
    isCrouching = false;
    this->spriteKeyPrefix = spriteKeyPrefix;
    this->currentSpriteKeySuffix = "Idle";
}

void BattleCharacter::setIsCrouching(bool value)
{
    isCrouching = value;
}

void BattleCharacter::punch()
{

}

void BattleCharacter::kick()
{

}

void BattleCharacter::move(int dir)
{

}

void BattleCharacter::special(std::string key)
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

std::string BattleCharacter::getCurrentSprite()
{
    return "\\" + spriteKeyPrefix + "\\" + currentSpriteKeySuffix + ".png";
}
