#ifndef ATTACKMODEL_H
#define ATTACKMODEL_H

#include "hitbox.h"
//#include "battlecharacter.h"
class BattleCharacter;

class AttackModel
{
public:
    AttackModel(BattleCharacter * user, int recovery, int hitStun, float posX, float posY, float w, float h, std::string hitboxSprite, int heightForBlocking, float velocity, int duration, int damage);

    virtual HitBox * applyAttack();

protected:
    BattleCharacter * user;

    int recovery;
    int hitStun;
    float posX;
    float posY;
    float w;
    float h;
    std::string hitBoxSprite;
    int heightForBlocking;
    float velocity;
    int damage;
    int duration;
};

#endif // ATTACKMODEL_H
