#include "attackmodelstandard.h"

#include "battlecharacter.h"

AttackModelStandard::AttackModelStandard(BattleCharacter *user, int recovery)
    : AttackModel(user, recovery)
{

}

HitBox *AttackModelStandard::applyAttack()
{
    user->setRecovery(recovery);
    return nullptr;
}
