#include "buttoncommandkick.h"

#pragma comment(lib, "User32.lib")

#include <Windows.h>

ButtonCommandKick::ButtonCommandKick(GameModel *model, char keyChar, BattleCharacter *myCharacter)
    : ButtonCommand(model, keyChar)
{
    buttonIsDown = false;
    this->myCharacter = myCharacter;
}

void ButtonCommandKick::execute()
{
    if((GetAsyncKeyState(keyChar) & 0x8000) && !buttonIsDown)
    {
        buttonIsDown = true;
        myCharacter->kick();
    }

    if(!(GetAsyncKeyState(keyChar) & 0x8000) && buttonIsDown)
    {
        buttonIsDown = false;
    }
}
