#ifndef ATTACKMODELSPECIAL_H
#define ATTACKMODELSPECIAL_H

#include "attackmodel.h"
#include "specialpropertycommand.h"

class AttackModelSpecial : public AttackModel
{
public:
    AttackModelSpecial(BattleCharacter * user, std::string identifier, int recovery, int hitStun, float posX, float posY, float w, float h,
                       std::string hitboxSprite, int heightForBlocking, float velocityX, float velocityY, int duration, int damage, bool isFixedToCharacter,
                       bool forceJumpSelf, bool forceJumpEnemy, int forceJumpDir, SpecialPropertyCommand * specialProperty
                       );

    HitBox * applyAttack(float characterPosX, float characterPosY, int dir);

private:
    SpecialPropertyCommand * specialProperty;
};

#endif // ATTACKMODELSPECIAL_H
