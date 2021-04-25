#include "battlecharacterplayercontrol.h"

#include <QDebug>

BattleCharacterPlayerControl::BattleCharacterPlayerControl(std::string spriteKeyPrefix, float walkSpeed, int health)
    : BattleCharacter(spriteKeyPrefix, walkSpeed, health)
{
    this->currentSpriteKeySuffix = "Idle";
}

void BattleCharacterPlayerControl::framePassed()
{
    if(recovery > 0)
    {
        recovery--;
        return;
    }

    if(axisVert < 0)
    {
        this->currentSpriteKeySuffix = "CrouchIdle";
        return;
    }

    if(axisHorz != 0 && positionY <= 0)
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
        positionX += (walkSpeed * axisHorz);
        return;
    }

    this->currentSpriteKeySuffix = "Idle";
}

void BattleCharacterPlayerControl::setHorzAxis(int value)
{
    axisHorz = value;
}

void BattleCharacterPlayerControl::setVertAxis(int value)
{
    axisVert = value;
}

void BattleCharacterPlayerControl::punch()
{
    if(recovery > 0)
        return;

    if(axisVert >= 0)
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

    if(axisVert >= 0)
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

void BattleCharacterPlayerControl::special(std::string key)
{
    if(recovery > 0)
        return;



    qDebug() << "Do a special " << QString::fromStdString(key);
}

void BattleCharacterPlayerControl::jump()
{
    if(recovery > 0)
        return;

    if(positionY > 0)
        return;

    lockedDir = axisHorz;
    framesSinceLastJump = 0;
}

void BattleCharacterPlayerControl::doThrow()
{
    if(recovery > 0)
        return;

    if(positionY > 0)
        return;

    currentSpriteKeySuffix = "Throw";
    recovery = 25;
}

void BattleCharacterPlayerControl::applyGravity()
{
    //x = x0 + v0t + 0.5at^2
    framesSinceLastJump++;

    potentialJumpPos = (jumpVelo*framesSinceLastJump) + (0.5f * gravity * (framesSinceLastJump*framesSinceLastJump));

    if(potentialJumpPos > 0)
    {
        positionX += (horzJumpSpeed * lockedDir);
        setPositionY(potentialJumpPos);
    }
    else
        setPositionY(0);

}
