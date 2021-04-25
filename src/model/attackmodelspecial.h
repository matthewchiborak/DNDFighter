#ifndef ATTACKMODELSPECIAL_H
#define ATTACKMODELSPECIAL_H

#include "attackmodel.h"

class AttackModelSpecial : public AttackModel
{
public:
    AttackModelSpecial(BattleCharacter * user, int recovery, int hitStun, float posX, float posY, float w, float h, std::string hitboxSprite, int heightForBlocking, float velocity, int duration, int damage);

    HitBox * applyAttack();
};

#endif // ATTACKMODELSPECIAL_H
