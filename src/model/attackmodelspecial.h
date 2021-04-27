#ifndef ATTACKMODELSPECIAL_H
#define ATTACKMODELSPECIAL_H

#include "attackmodel.h"

class AttackModelSpecial : public AttackModel
{
public:
    AttackModelSpecial(BattleCharacter * user, int recovery, int hitStun, float posX, float posY, float w, float h,
                       std::string hitboxSprite, int heightForBlocking, float velocityX, float velocityY, int duration, int damage, bool isFixedToCharacter);

    HitBox * applyAttack(float characterPosX, float characterPosY);
};

#endif // ATTACKMODELSPECIAL_H