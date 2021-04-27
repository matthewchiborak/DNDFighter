#include "attackmodelstandard.h"

#include "battlecharacter.h"

AttackModelStandard::AttackModelStandard(BattleCharacter *user, int recovery, int hitStun, float posX, float posY, float w, float h, std::string hitboxSprite, int heightForBlocking, float velocityX, float velocityY, int duration, int damage, bool isFixedToCharacter, bool forceJumpSelf, bool forceJumpEnemy, int forceJumpDir)
    : AttackModel(user, recovery, hitStun, posX, posY, w, h, hitboxSprite,
                  heightForBlocking, velocityX, velocityY, duration, damage, isFixedToCharacter, forceJumpSelf, forceJumpEnemy, forceJumpDir)
{

}

HitBox *AttackModelStandard::applyAttack(float characterPosX, float characterPosY, int dir)
{
    user->setRecovery(recovery);
    return new HitBox(characterPosX + posX, characterPosY + posY, false, hitBoxSprite, duration, hitStun,
                      damage, w, h, velocityX, velocityY, heightForBlocking,
                      isFixedToCharacter, user->getPositionX(), user->getPositionY(), forceJumpSelf, forceJumpEnemy, forceJumpDir);
}
