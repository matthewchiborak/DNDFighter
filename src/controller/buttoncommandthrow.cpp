#include "buttoncommandthrow.h"

#pragma comment(lib, "User32.lib")

#include <Windows.h>

ButtonCommandThrow::ButtonCommandThrow(GameModel *model, char keyChar, BattleCharacter *myCharacter)
    : ButtonCommand(model, keyChar)
{
    buttonIsDown = false;
    this->myCharacter = myCharacter;
}

void ButtonCommandThrow::execute()
{
    if((GetAsyncKeyState(keyChar) & 0x8000) && !buttonIsDown)
    {
        buttonIsDown = true;
        myCharacter->doThrow();
    }

    if(!(GetAsyncKeyState(keyChar) & 0x8000) && buttonIsDown)
    {
        buttonIsDown = false;
    }
}
