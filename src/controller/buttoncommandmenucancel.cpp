#include "buttoncommandmenucancel.h"

#pragma comment(lib, "User32.lib")

#include <Windows.h>

ButtonCommandMenuCancel::ButtonCommandMenuCancel(GameModel *model, char keyChar)
    : ButtonCommand(model, keyChar)
{
    buttonIsDown = false;
}

void ButtonCommandMenuCancel::execute()
{
    if((GetAsyncKeyState(keyChar) & 0x8000) && !buttonIsDown)
    {
        buttonIsDown = true;
        model->getCharacterSelectModel()->cancel();
    }

    if(!(GetAsyncKeyState(keyChar) & 0x8000) && buttonIsDown)
    {
        buttonIsDown = false;
    }
}
