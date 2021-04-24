#include "buttoncommandpunch.h"

#pragma comment(lib, "User32.lib")

#include <Windows.h>

#include <QDebug>

ButtonCommandPunch::ButtonCommandPunch(GameModel *model, char keyChar, BattleCharacter *myCharacter)
    : ButtonCommand(model, keyChar)
{
    buttonIsDown = false;
    this->myCharacter = myCharacter;
}


void ButtonCommandPunch::execute()
{
    if((GetAsyncKeyState(keyChar) & 0x8000) && !buttonIsDown)
    {
        buttonIsDown = true;
        myCharacter->punch();
    }

    if(!(GetAsyncKeyState(keyChar) & 0x8000) && buttonIsDown)
    {
        buttonIsDown = false;
    }
}
