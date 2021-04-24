#include "buttoncommandjump.h"

#pragma comment(lib, "User32.lib")

#include <Windows.h>

ButtonCommandJump::ButtonCommandJump(GameModel *model, char keyChar, BattleCharacter *myCharacter)
    : ButtonCommand(model, keyChar)
{
    buttonIsDown = false;
    this->myCharacter = myCharacter;
}

void ButtonCommandJump::execute()
{
    if((GetAsyncKeyState(keyChar) & 0x8000))
    {
        buttonIsDown = true;
        myCharacter->jump();
    }
}
