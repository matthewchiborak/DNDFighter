#include "attackmodelthrow.h"

#include "battlecharacter.h"

AttackModelThrow::AttackModelThrow(BattleCharacter *user, int recovery, int hitStun, float posX, float posY, float w, float h, std::string hitboxSprite, int heightForBlocking, float velocityX, float velocityY, int duration, int damage, bool isFixedToCharacter)
    : AttackModel(user, recovery, hitStun, posX, posY, w, h, hitboxSprite, heightForBlocking, velocityX, velocityY, duration, damage, isFixedToCharacter)
{

}

HitBox *AttackModelThrow::applyAttack(float characterPosX, float characterPosY)
{
    user->setRecovery(recovery);
    return nullptr;
}
