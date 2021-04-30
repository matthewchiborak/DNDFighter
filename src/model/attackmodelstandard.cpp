#include "attackmodelstandard.h"

#include "battlecharacter.h"

AttackModelStandard::AttackModelStandard(BattleCharacter *user, std::string identifier, int recovery, int hitStun, float posX, float posY, float w, float h, std::string hitboxSprite, int heightForBlocking, float velocityX, float velocityY, int duration, int damage, bool isFixedToCharacter, bool forceJumpSelf, bool forceJumpEnemy, int forceJumpDir)
    : AttackModel(user, identifier, recovery, hitStun, posX, posY, w, h, hitboxSprite,
                  heightForBlocking, velocityX, velocityY, duration, damage, isFixedToCharacter, forceJumpSelf, forceJumpEnemy, forceJumpDir)
{

}

HitBox *AttackModelStandard::applyAttack(float characterPosX, float characterPosY, int dir)
{
    if(doesThisAttackAlreadyExists(identifier))
        return nullptr;

    user->setRecovery(recovery);

    int heightForBlockToUse = heightForBlocking;

    if(user->getPositionY() > 0)
        heightForBlockToUse = 2;

    if(user->getIsFaceRight())
    {
        return new HitBox(identifier, characterPosX + posX, characterPosY + posY, false, hitBoxSprite, duration, hitStun,
                          damage, w, h, velocityX, velocityY, heightForBlockToUse,
                          isFixedToCharacter, user->getPositionX(), user->getPositionY(), forceJumpSelf, forceJumpEnemy, forceJumpDir, false);
    }

    return new HitBox(identifier, characterPosX + user->getWidth() - posX - w, characterPosY + posY, false, hitBoxSprite, duration, hitStun,
                      damage, w, h, -1 * velocityX, velocityY, heightForBlockToUse,
                      isFixedToCharacter, user->getPositionX(), user->getPositionY(), forceJumpSelf, forceJumpEnemy, -1 * forceJumpDir, false);
}
