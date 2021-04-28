#include "buttoncommandmenumove.h"

#pragma comment(lib, "User32.lib")

#include <Windows.h>

ButtonCommandMenuMove::ButtonCommandMenuMove(GameModel *model, char keyUp, char keyDown, char keyLeft, char keyRight)
    : ButtonCommand(model, keyUp)
{
    this->keyUp = keyUp;
    this->keyDown = keyDown;
    this->keyLeft = keyLeft;
    this->keyRight = keyRight;
}

void ButtonCommandMenuMove::execute()
{
    if(!buttonIsDown)
    {
        if((GetAsyncKeyState(keyUp) & 0x8000))
        {
            buttonIsDown = true;
            model->getCharacterSelectModel()->moveCursor(0, 1);
        }
        else if((GetAsyncKeyState(keyDown) & 0x8000))
        {
            buttonIsDown = true;
            model->getCharacterSelectModel()->moveCursor(0, -1);
        }
        else if((GetAsyncKeyState(keyLeft) & 0x8000))
        {
            buttonIsDown = true;
            model->getCharacterSelectModel()->moveCursor(-1, 0);
        }
        else if((GetAsyncKeyState(keyRight) & 0x8000))
        {
            buttonIsDown = true;
            model->getCharacterSelectModel()->moveCursor(1, 0);
        }
    }
    else
    {
        if(
                (!(GetAsyncKeyState(keyUp) & 0x8000))
                && (!(GetAsyncKeyState(keyDown) & 0x8000))
                && (!(GetAsyncKeyState(keyLeft) & 0x8000))
                && (!(GetAsyncKeyState(keyRight) & 0x8000))
                )
        {
            buttonIsDown = false;
        }
    }
}
