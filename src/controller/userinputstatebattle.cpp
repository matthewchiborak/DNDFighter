#include "userinputstatebattle.h"

#pragma comment(lib, "User32.lib")

#include <Windows.h>

UserInputStateBattle::UserInputStateBattle(GameModel *model)
    : UserInputState(model)
{

}

void UserInputStateBattle::handleUserInput()
{
    if(GetAsyncKeyState('W') & 0x8000)
        model; //model->getPlayer1->action("W");
    else if(GetAsyncKeyState('A') & 0x8000)
        return;
    else if(GetAsyncKeyState('S') & 0x8000)
        return;
    else if(GetAsyncKeyState('D') & 0x8000)
        return;
}
