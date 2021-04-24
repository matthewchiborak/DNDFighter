#include "buttoncommandcrouch.h"

#pragma comment(lib, "User32.lib")

#include <Windows.h>

ButtonCommandCrouch::ButtonCommandCrouch(GameModel * model, char keyChar, BattleCharacter * myCharacter)
    : ButtonCommand(model, keyChar)
{
    this->myCharacter = myCharacter;
}

void ButtonCommandCrouch::execute()
{
    if((GetAsyncKeyState(keyChar) & 0x8000))
    {
        myCharacter->setIsCrouching(true);
    }
    else
    {
        myCharacter->setIsCrouching(false);
    }
}
