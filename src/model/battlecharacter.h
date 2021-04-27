#ifndef BATTLECHARACTER_H
#define BATTLECHARACTER_H

#include <string>
#include <vector>
#include "attackmodel.h"
#include "hitbox.h"

class BattleCharacter
{
public:
    BattleCharacter(std::string spriteKeyPrefix);

    virtual void setHorzAxis(int value);
    virtual void setVertAxis(int value);

    virtual void framePassed();

    virtual void punch();
    virtual void kick();
    virtual void special();
    virtual void jump();
    virtual bool forceJump(int dir);
    virtual void doThrow();

    float getPositionX();
    void setPositionX(float value);
    float getPositionY();
    void setPositionY(float value);
    float getWidth();
    void setWidth(float value);
    float getHeight();
    void setHeight(float value);

    std::string getCurrentSprite();
    std::string getSpriteKeyPrefix();

    virtual void applyGravity();

    void doDamage(int amount);
    virtual void applyHitStun(int hitStun);
    float getHealthPercentage();
    void setRecovery(int value);
    void addHitBox(HitBox * value);

    void setMaxHealth(int value);
    void refillHealth();
    void setWalkSpeed(float value);
    void setHorzJumpSpeed(float value);

    void setPunchModel(AttackModel * model);
    void setKickModel(AttackModel * model);
    void setCrouchPunchModel(AttackModel * model);
    void setCrouchKickModel(AttackModel * model);
    void setThrowModel(AttackModel * model);
    void setNeutralSpecialModel(AttackModel * model);
    void setForwardSpecialModel(AttackModel * model);
    void setDownSpecialModel(AttackModel * model);

    virtual void setHurtBox(float posx, float posy, float w, float h);
    virtual void setHurtBoxCrouch(float posx, float posy, float w, float h);

    virtual void advanceHitBoxes();

    std::vector<HitBox*> * getActiveHitBoxes();

    float gethurtBoxPosX();
    float gethurtBoxPosY();
    float gethurtBoxHeight();
    float gethurtBoxWidth();

protected:
    int currentHealth;
    int maxHealth;

    int axisHorz = 0;
    int axisVert = 0;

    float width;
    float height;
    float positionX;
    float positionY;
    std::string spriteKeyPrefix;
    std::string currentSpriteKeySuffix;

    float walkSpeed;
    float horzJumpSpeed;
    int recovery;
    int hitstun;

    AttackModel * punchModel;
    AttackModel * kickModel;
    AttackModel * crouchPunchModel;
    AttackModel * crouchKickModel;
    AttackModel * throwModel;
    AttackModel * neutralSpecialModel;
    AttackModel * forwardSpecialModel;
    AttackModel * downSpecialModel;

    std::vector<HitBox*> activeHitBoxes;

    float hurtBoxPosX;
    float hurtBoxPosY;
    float hurtBoxHeight;
    float hurtBoxWidth;

    float hurtBoxPosXCrouch;
    float hurtBoxPosYCrouch;
    float hurtBoxHeightCrouch;
    float hurtBoxWidthCrouch;
};

#endif // BATTLECHARACTER_H
