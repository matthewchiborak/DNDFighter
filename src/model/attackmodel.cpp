#include "attackmodel.h"

#include "battlecharacter.h"

AttackModel::AttackModel(BattleCharacter *user, std::string identifier, int recovery, int hitStun, float posX, float posY, float w, float h, std::string hitboxSprite, int heightForBlocking, float velocityX, float velocityY, int duration, int damage, bool isFixedToCharacter, bool forceJumpSelf, bool forceJumpEnemy, int forceJumpDir)
{
    this->identifier = identifier;
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

    this->forceJumpSelf = forceJumpSelf;
    this->forceJumpEnemy = forceJumpEnemy;
    this->forceJumpDir = forceJumpDir;
}

HitBox *AttackModel::applyAttack(float characterPosX, float characterPosY, int dir)
{
    return nullptr;
}

std::string AttackModel::getHitBoxSprite()
{
    return hitBoxSprite;
}

bool AttackModel::doesThisAttackAlreadyExists(std::string id)
{
    for(int i = 0; i < user->getActiveHitBoxes()->size(); i++)
    {
        if(user->getActiveHitBoxes()->at(i)->getIdentifier() == id)
            return true;
    }

    return false;
}
