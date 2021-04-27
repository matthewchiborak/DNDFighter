#ifndef BATTLECHARACTERPLAYERCONTROL_H
#define BATTLECHARACTERPLAYERCONTROL_H

#include "battlecharacter.h"

class BattleCharacterPlayerControl : public BattleCharacter
{
public:
    BattleCharacterPlayerControl(std::string spriteKeyPrefix);

    void framePassed();

    void setHorzAxis(int value);
    void setVertAxis(int value);
    void punch();
    void kick();
    void special();
    void jump();
    void doThrow();

    void applyGravity();

    void applyHitStun(int hitStun);

    void setHurtBox(float posx, float posy, float w, float h);
    void setHurtBoxCrouch(float posx, float posy, float w, float h);

    void advanceHitBoxes();

private:
    bool walkState = false;
    int walkCount = 0;
    int framesPerWalk = 4;

    float potentialJumpPos;
    int lockedDir = 0;
    int framesSinceLastJump = 1000;
    float horzJumpSpeed = (1.f/42.f);
    float jumpVelo = (1.f/12.f);
    float gravity = (-1.f/280.f);
};

#endif // BATTLECHARACTERPLAYERCONTROL_H
