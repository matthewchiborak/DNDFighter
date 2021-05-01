#include "buttoncommandmenuenter.h"

#pragma comment(lib, "User32.lib")

#include <Windows.h>

ButtonCommandMenuEnter::ButtonCommandMenuEnter(GameModel *model, char keyChar, std::string key)
    : ButtonCommand(model, keyChar)
{
    buttonIsDown = false;
    this->key = key;
}

void ButtonCommandMenuEnter::execute()
{
    if((GetAsyncKeyState(keyChar) & 0x8000) && !buttonIsDown)
    {
        buttonIsDown = true;
        model->getCharacterSelectModel()->enter(key);
    }

    if(!(GetAsyncKeyState(keyChar) & 0x8000) && buttonIsDown)
    {
        buttonIsDown = false;
    }
}
