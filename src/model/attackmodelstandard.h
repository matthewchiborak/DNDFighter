#ifndef ATTACKMODELSTANDARD_H
#define ATTACKMODELSTANDARD_H

#include "attackmodel.h"

class AttackModelStandard : public AttackModel
{
public:
    AttackModelStandard(BattleCharacter * user, int recovery, int hitStun, float posX, float posY, float w, float h, std::string hitboxSprite, int heightForBlocking, float velocity, int duration, int damage);

    HitBox * applyAttack();
};

#endif // ATTACKMODELSTANDARD_H
