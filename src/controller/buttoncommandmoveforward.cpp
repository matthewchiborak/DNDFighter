#include "buttoncommandmoveforward.h"

#pragma comment(lib, "User32.lib")

#include <Windows.h>

#include <QDebug>

ButtonCommandMoveForward::ButtonCommandMoveForward(GameModel *model, char keyChar, BattleCharacter *myCharacter, int dir)
    : ButtonCommand(model, keyChar)
{
    buttonIsDown = false;
    this->myCharacter = myCharacter;
    this->dir = dir;
}

void ButtonCommandMoveForward::execute()
{
    handleKeyHold();
    handleKeyDown();
    handleKeyUp();
}

void ButtonCommandMoveForward::handleKeyDown()
{
    if((GetAsyncKeyState(keyChar) & 0x8000) && !buttonIsDown)
    {
        buttonIsDown = true;

        auto nowTime = std::chrono::system_clock::now().time_since_epoch();
        auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(nowTime).count();
        theTimeNow = (millis);
        timeOfLastButtonEvent = theTimeNow;
    }
}

void ButtonCommandMoveForward::handleKeyHold()
{
    if((GetAsyncKeyState(keyChar) & 0x8000) && buttonIsDown)
    {
        auto nowTime = std::chrono::system_clock::now().time_since_epoch();
        auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(nowTime).count();
        theTimeNow =(millis);
        elapsed_millies = theTimeNow - timeOfLastButtonEvent;
        timeOfLastButtonEvent = theTimeNow;

        this->myCharacter->move(elapsed_millies * dir);
    }
}

void ButtonCommandMoveForward::handleKeyUp()
{
    if(!(GetAsyncKeyState(keyChar) & 0x8000) && buttonIsDown)
    {
        this->myCharacter->move(0);
        buttonIsDown = false;
    }
}
