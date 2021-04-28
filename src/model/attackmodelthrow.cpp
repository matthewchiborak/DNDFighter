#include "attackmodelthrow.h"

#include "battlecharacter.h"

AttackModelThrow::AttackModelThrow(BattleCharacter *user, int recovery, int hitStun, float posX, float posY, float w, float h, std::string hitboxSprite, int heightForBlocking, float velocityX, float velocityY, int duration, int damage, bool isFixedToCharacter, bool forceJumpSelf, bool forceJumpEnemy, int forceJumpDir)
    : AttackModel(user, recovery, hitStun, posX, posY, w, h,
                  hitboxSprite, heightForBlocking, velocityX, velocityY, duration, damage, isFixedToCharacter, forceJumpSelf, forceJumpEnemy, forceJumpDir)
{

}

HitBox *AttackModelThrow::applyAttack(float characterPosX, float characterPosY, int dir)
{
    user->setRecovery(recovery);

    if(user->getIsFaceRight())
    {
        return new HitBox(characterPosX + posX, characterPosY + posY, false, hitBoxSprite, duration, hitStun,
                          damage, w, h, velocityX, velocityY, heightForBlocking,
                          isFixedToCharacter, user->getPositionX(), user->getPositionY(), forceJumpSelf, forceJumpEnemy, dir, true);
    }

    return new HitBox(characterPosX + user->getWidth() - posX - w, characterPosY + posY, false, hitBoxSprite, duration, hitStun,
                      damage, w, h, -1 * velocityX, velocityY, heightForBlocking,
                      isFixedToCharacter, user->getPositionX(), user->getPositionY(), forceJumpSelf, forceJumpEnemy, dir, true);
}
