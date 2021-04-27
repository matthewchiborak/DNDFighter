#include "attackmodelspecial.h"

#include "battlecharacter.h"

AttackModelSpecial::AttackModelSpecial(BattleCharacter *user, int recovery, int hitStun, float posX, float posY, float w, float h, std::string hitboxSprite, int heightForBlocking, float velocityX, float velocityY, int duration, int damage, bool isFixedToCharacter)
    : AttackModel(user, recovery, hitStun, posX, posY, w, h, hitboxSprite, heightForBlocking, velocityX, velocityY, duration, damage, isFixedToCharacter)
{

}

HitBox *AttackModelSpecial::applyAttack(float characterPosX, float characterPosY)
{
    user->setRecovery(recovery);

    return new HitBox(characterPosX + posX, characterPosY + posY, false, hitBoxSprite, duration, hitStun,
                      damage, w, h, velocityX, velocityY, heightForBlocking, isFixedToCharacter, user->getPositionX(), user->getPositionY());
}
