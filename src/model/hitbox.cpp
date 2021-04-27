#include "hitbox.h"

HitBox::HitBox(float posx, float posy, bool hasVisuals, std::string sprite, int duration, int hitstun,
               int damage, float width, float height, float velocityX, float velocityY, int heightForBlocking,
               bool isFixedToCharacter, float characterPosX, float characterPosY)
{
    this->posx = posx;
    this->posy = posy;
    this->spawnPosX = posx;
    this->spawnPosY = posy;
    this->hasVisuals = hasVisuals;
    this->sprite = sprite;
    this->duration = duration;
    this->hitstun = hitstun;
    this->damage = damage;
    this->width = width;
    this->height = height;
    this->velocityX = velocityX;
    this->velocityY = velocityY;
    this->heightForBlocking = heightForBlocking;
    this->isFixedToCharacter = isFixedToCharacter;
    this->characterPosXAtSpawn = characterPosX;
    this->characterPosYAtSpawn = characterPosY;

    this->hasVisuals = (sprite != "None");

    this->lifeTime = 0;
}

bool HitBox::gethasVisuals()
{
    return hasVisuals;
}

std::string HitBox::getsprite()
{
    return sprite;
}

int HitBox::getduration()
{
    return duration;
}

int HitBox::gethitstun()
{
    return hitstun;
}

int HitBox::getdamage()
{
    return damage;
}

float HitBox::getwidth()
{
    return width;
}

float HitBox::getheight()
{
    return height;
}

float HitBox::getvelocityX()
{
    return velocityX;
}

float HitBox::getvelocityY()
{
    return velocityY;
}

int HitBox::getheightForBlocking()
{
    return heightForBlocking;
}

bool HitBox::getisFixedToCharacter()
{
    return isFixedToCharacter;
}

void HitBox::setPos(float charPosX, float charPosY)
{
    posx = (spawnPosX) + (charPosX - characterPosXAtSpawn);
    posy = (spawnPosY) + (charPosY - characterPosYAtSpawn);
}

void HitBox::advance()
{
    posx += velocityX;
    posy += velocityY;

    lifeTime++;
}

bool HitBox::isDone()
{
    return lifeTime >= duration;
}

float HitBox::getPosX()
{
    return posx;
}

float HitBox::getPosY()
{
    return posy;
}
