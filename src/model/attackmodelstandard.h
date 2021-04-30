#ifndef ATTACKMODELSTANDARD_H
#define ATTACKMODELSTANDARD_H

#include "attackmodel.h"

class AttackModelStandard : public AttackModel
{
public:
    AttackModelStandard(BattleCharacter * user, std::string identifier, int recovery, int hitStun, float posX, float posY, float w, float h,
                        std::string hitboxSprite, int heightForBlocking,
                        float velocityX, float velocityY, int duration, int damage, bool isFixedToCharacter,
                        bool forceJumpSelf, bool forceJumpEnemy, int forceJumpDir
                        );

    HitBox * applyAttack(float characterPosX, float characterPosY, int dir);
};

#endif // ATTACKMODELSTANDARD_H
