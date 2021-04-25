#include "attackmodel.h"

AttackModel::AttackModel(BattleCharacter *user, int recovery, int hitStun, float posX, float posY, float w, float h, std::string hitboxSprite, int heightForBlocking, float velocity, int duration, int damage)
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
    this->velocity = velocity;
    this->duration = duration;
    this->damage = damage;
}

HitBox *AttackModel::applyAttack()
{
    return nullptr;
}
