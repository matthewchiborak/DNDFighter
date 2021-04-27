#ifndef ATTACKMODEL_H
#define ATTACKMODEL_H

#include "hitbox.h"
//#include "battlecharacter.h"
class BattleCharacter;

class AttackModel
{
public:
    AttackModel(BattleCharacter * user, int recovery, int hitStun, float posX, float posY, float w, float h,
                std::string hitboxSprite, int heightForBlocking, float velocityX, float velocityY, int duration, int damage, bool isFixedToCharacter,
                bool forceJumpSelf, bool forceJumpEnemy, int forceJumpDir
                );

    virtual HitBox * applyAttack(float characterPosX, float characterPosY, int dir);

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
    float velocityX;
    float velocityY;
    int damage;
    int duration;
    bool isFixedToCharacter;
    bool forceJumpSelf;
    bool forceJumpEnemy;
    int forceJumpDir;
};

#endif // ATTACKMODEL_H
