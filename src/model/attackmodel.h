#ifndef ATTACKMODEL_H
#define ATTACKMODEL_H

#include "hitbox.h"
//#include "battlecharacter.h"
class BattleCharacter;

class AttackModel
{
public:
    AttackModel(BattleCharacter * user, int recovery);

    virtual HitBox * applyAttack();

protected:
    BattleCharacter * user;

    int recovery;
};

#endif // ATTACKMODEL_H
