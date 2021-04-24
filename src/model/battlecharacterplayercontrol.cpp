#include "battlecharacterplayercontrol.h"

#include <QDebug>

BattleCharacterPlayerControl::BattleCharacterPlayerControl(std::string spriteKeyPrefix, float walkSpeed)
    : BattleCharacter(spriteKeyPrefix, walkSpeed)
{
    this->currentSpriteKeySuffix = "Idle";
}

void BattleCharacterPlayerControl::setIsCrouching(bool value)
{
    if(recovery > 0)
        return;

//    if(dir != 0)
//        return;

    isCrouching = value;
    if(!isCrouching || positionY > 0)
        this->currentSpriteKeySuffix = "Idle";
    else
        this->currentSpriteKeySuffix = "CrouchIdle";
}

void BattleCharacterPlayerControl::framePassed()
{
    if(recovery == 0)
        return;

    recovery--;

    if(recovery <= 0)
    {
        recovery = 0;

        if(dir == 0)
        {
            if(!isCrouching || positionY > 0)
                this->currentSpriteKeySuffix = "Idle";
            else
                this->currentSpriteKeySuffix = "CrouchIdle";
        }
    }
}

void BattleCharacterPlayerControl::punch()
{
    if(recovery > 0)
        return;

    dir = 0;

    if(!isCrouching)
    {
        currentSpriteKeySuffix = "Punch";
        recovery = 15;
    }
    else
    {
        currentSpriteKeySuffix = "CrouchPunch";
        recovery = 15;
    }
}

void BattleCharacterPlayerControl::kick()
{
    if(recovery > 0)
        return;

    dir = 0;

    if(!isCrouching)
    {
        currentSpriteKeySuffix = "Kick";
        recovery = 15;
    }
    else
    {
        currentSpriteKeySuffix = "CrouchKick";
        recovery = 15;
    }
}

void BattleCharacterPlayerControl::move(double dir)
{
    if(recovery > 0)
        return;

    this->dir = dir;

    if(positionY > 0)
        return;

    if(isCrouching)
        return;

    positionX += (walkSpeed * dir);

    ////////////////////////
    if(dir != 0)
    {
        walkCount++;
        if(walkCount > framesPerWalk)
        {
            if(walkState)
                this->currentSpriteKeySuffix = "Idle";
            else if(!walkState)
                this->currentSpriteKeySuffix = "Walk";

            walkState = !walkState;
            walkCount = 0;
        }
    }
    else
    {
        walkState = false;
        walkCount = 0;
    }
}

void BattleCharacterPlayerControl::special(std::string key)
{
    if(recovery > 0)
        return;

    dir = 0;

    qDebug() << "Do a special " << QString::fromStdString(key);
}

void BattleCharacterPlayerControl::jump()
{
    if(recovery > 0)
        return;

    if(positionY > 0)
        return;

    lockedDir = dir;

//    if(dir == 0)
//        return;
//    else
//        return;

    auto nowTime = std::chrono::system_clock::now().time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(nowTime).count();
    jumptheTimeNow = (millis);
    jumptimeOfLastButtonEvent = jumptheTimeNow;
}

void BattleCharacterPlayerControl::applyGravity()
{
    //x = x0 + v0t + 0.5at^2

    auto nowTime = std::chrono::system_clock::now().time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(nowTime).count();
    jumptheTimeNow =(millis);
    jumpelapsed_millies = jumptheTimeNow - jumptimeOfLastButtonEvent;

    potentialJumpPos = (jumpVelo*jumpelapsed_millies) + (0.5f * gravity * (jumpelapsed_millies*jumpelapsed_millies));

    if(potentialJumpPos > 0)
    {
        isCrouching = false;
        positionX += (horzJumpSpeed * lockedDir);
        setPositionY(potentialJumpPos);
    }
    else
        setPositionY(0);

}
