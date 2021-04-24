#ifndef BATTLECHARACTERPLAYERCONTROL_H
#define BATTLECHARACTERPLAYERCONTROL_H

#include "battlecharacter.h"

class BattleCharacterPlayerControl : public BattleCharacter
{
public:
    BattleCharacterPlayerControl(std::string spriteKeyPrefix, float walkSpeed);

    void setIsCrouching(bool value);
    void framePassed();

    void punch();
    void kick();
    void move(double dir);
    void special(std::string key);
    void jump();

    void applyGravity();

private:
    bool walkState = false;
    int walkCount = 0;
    int framesPerWalk = 5;
    int dir = 0;

    long long jumptheTimeNow;
    long long jumptimeOfLastButtonEvent;
    double jumpelapsed_millies;
    float potentialJumpPos;
    int lockedDir = 0;
    float horzJumpSpeed = (1.f/700.f);
    float jumpVelo = (1.f/200.f);
    float gravity = (-1.f/80000.f);
};

#endif // BATTLECHARACTERPLAYERCONTROL_H
