#include "attackmodelspecial.h"

#include "battlecharacter.h"

AttackModelSpecial::AttackModelSpecial(BattleCharacter *user, int recovery, int hitStun, float posX, float posY, float w, float h, std::string hitboxSprite, int heightForBlocking, float velocity, int duration, int damage)
    : AttackModel(user, recovery, hitStun, posX, posY, w, h, hitboxSprite, heightForBlocking, velocity, duration, damage)
{

}

HitBox *AttackModelSpecial::applyAttack()
{
    user->setRecovery(recovery);

    return nullptr;
}
