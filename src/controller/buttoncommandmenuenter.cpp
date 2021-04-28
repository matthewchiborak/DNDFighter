#include "buttoncommandmenuenter.h"

#pragma comment(lib, "User32.lib")

#include <Windows.h>

ButtonCommandMenuEnter::ButtonCommandMenuEnter(GameModel *model, char keyChar)
    : ButtonCommand(model, keyChar)
{
    buttonIsDown = false;
}

void ButtonCommandMenuEnter::execute()
{
    if((GetAsyncKeyState(keyChar) & 0x8000) && !buttonIsDown)
    {
        buttonIsDown = true;
        model->getCharacterSelectModel()->enter();
    }

    if(!(GetAsyncKeyState(keyChar) & 0x8000) && buttonIsDown)
    {
        buttonIsDown = false;
    }
}
