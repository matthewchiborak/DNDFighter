#include "hitbox.h"

HitBox::HitBox(float posx, float posy, bool hasVisuals, std::string sprite, int duration, int hitstun,
               int damage, float width, float height, float velocityX, float velocityY, int heightForBlocking,
               bool isFixedToCharacter, float characterPosX, float characterPosY, bool forceJumpSelf, bool forceJumpEnemy, int forceJumpDir, bool isUnBlockable, bool flip)
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

    this->forceAJumpSelf = forceJumpSelf;
    this->forceAJumpEnemy = forceJumpEnemy;
    this->forceJumpDir = forceJumpDir;

    this->isUnblockable = isUnBlockable;
    this->flipSprite = flip;

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

void HitBox::makeDone()
{
    lifeTime = duration;
}

float HitBox::getPosX()
{
    return posx;
}

float HitBox::getPosY()
{
    return posy;
}

bool HitBox::getforceAJumpEnemy()
{
    return forceAJumpEnemy;
}

bool HitBox::getforceAJumpSelf()
{
    return forceAJumpSelf;
}

int HitBox::getforceJumpDir()
{
    return forceJumpDir;
}

bool HitBox::getFlipSprite()
{
    return flipSprite;
}

bool HitBox::getIsUnblockable()
{
    return isUnblockable;
}

bool HitBox::boxCollisions(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
    float right1 = x1+w1;
    float top1 = y1+h1;
    float right2 = x2+w2;
    float top2 = y2+h2;

    if (x1 < right2 && right1 > x2 && top1 > y2 && y1 < top2 )
        return true;

    return false;
}
