#include "attackmodel.h"

AttackModel::AttackModel(BattleCharacter *user, int recovery)
{
    this->user = user;
    this->recovery = recovery;
}

HitBox *AttackModel::applyAttack()
{
    return nullptr;
}
