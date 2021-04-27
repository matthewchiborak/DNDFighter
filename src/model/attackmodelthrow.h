#ifndef ATTACKMODELTHROW_H
#define ATTACKMODELTHROW_H

#include "attackmodel.h"

class AttackModelThrow : public AttackModel
{
public:
    AttackModelThrow(BattleCharacter * user, int recovery, int hitStun, float posX, float posY, float w, float h,
                     std::string hitboxSprite, int heightForBlocking, float velocityX, float velocityY, int duration, int damage, bool isFixedToCharacter);

    HitBox * applyAttack(float characterPosX, float characterPosY);
};

#endif // ATTACKMODELTHROW_H
