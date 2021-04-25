#include "buttoncommandspecial.h"

#pragma comment(lib, "User32.lib")

#include <Windows.h>

ButtonCommandSpecial::ButtonCommandSpecial(GameModel *model, char keyChar, BattleCharacter *myCharacter)
    : ButtonCommand(model, keyChar)
{
    buttonIsDown = false;
    this->myCharacter = myCharacter;
}

void ButtonCommandSpecial::execute()
{
    if((GetAsyncKeyState(keyChar) & 0x8000) && !buttonIsDown)
    {
        buttonIsDown = true;
        myCharacter->special();
    }

    if(!(GetAsyncKeyState(keyChar) & 0x8000) && buttonIsDown)
    {
        buttonIsDown = false;
    }
}
