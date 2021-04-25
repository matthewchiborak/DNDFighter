#ifndef ATTACKMODELSTANDARD_H
#define ATTACKMODELSTANDARD_H

#include "attackmodel.h"

class AttackModelStandard : public AttackModel
{
public:
    AttackModelStandard(BattleCharacter * user, int recovery);

    HitBox * applyAttack();
};

#endif // ATTACKMODELSTANDARD_H
