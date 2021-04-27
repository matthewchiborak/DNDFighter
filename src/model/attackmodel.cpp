#include "attackmodel.h"

AttackModel::AttackModel(BattleCharacter *user, int recovery, int hitStun, float posX, float posY, float w, float h, std::string hitboxSprite, int heightForBlocking, float velocityX, float velocityY, int duration, int damage, bool isFixedToCharacter)
{
    this->user = user;
    this->recovery = recovery;
    this->hitStun = hitStun;
    this->posX = posX;
    this->posY = posY;
    this->w = w;
    this->h = h;
    this->hitBoxSprite = hitboxSprite;
    this->heightForBlocking = heightForBlocking;
    this->velocityX = velocityX;
    this->velocityY = velocityY;
    this->duration = duration;
    this->damage = damage;
    this->isFixedToCharacter = isFixedToCharacter;
}

HitBox *AttackModel::applyAttack(float characterPosX, float characterPosY)
{
    return nullptr;
}
