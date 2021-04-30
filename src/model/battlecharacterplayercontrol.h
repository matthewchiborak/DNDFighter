#ifndef BATTLECHARACTERPLAYERCONTROL_H
#define BATTLECHARACTERPLAYERCONTROL_H

#include "battlecharacter.h"

class BattleCharacterPlayerControl : public BattleCharacter
{
public:
    BattleCharacterPlayerControl(std::string spriteKeyPrefix, MusicControllerAbstract * musicController);

    void framePassed();

    void setHorzAxis(int value);
    void setVertAxis(int value);
    void punch();
    void kick();
    void special();
    void jump();
    bool forceJump(int dir);
    void doThrow();
    void forceMove(float moveSpeed);

    void applyGravity();

    void doDamage(int amount, int hitStun, int blockStun, bool unblockable, int blockHeight);
    bool wouldBlockThis(bool unblockable, int blockHeight);
    void forceJumpFromMidAirHit(int dir);

    void setHurtBox(float posx, float posy, float w, float h);
    void setHurtBoxCrouch(float posx, float posy, float w, float h);

    void advanceHitBoxes();

    void setIsFaceRight(bool isRight);
    std::vector<std::string> * getAllSprites();

private:
    bool walkState = false;
    int walkCount = 0;
    int framesPerWalk = 4;

    float potentialJumpPos;
    int lockedDir = 0;
    int framesSinceLastJump = 1000;
    float jumpVelo = (1.f/10.f);//(1.f/12.f);
    float gravity = (-1.f/280.f);//(-1.f/360.f); //
    float jumpStartingHeight = 0.f;
};

#endif // BATTLECHARACTERPLAYERCONTROL_H
