#include "buttoncommandmoveforward.h"

#pragma comment(lib, "User32.lib")

#include <Windows.h>

#include <QDebug>

ButtonCommandMoveForward::ButtonCommandMoveForward(GameModel *model, char keyChar, BattleCharacter *myCharacter, char oppositeKeyChar)
    : ButtonCommand(model, keyChar)
{
    this->myCharacter = myCharacter;
    this->oppositeKeyChar = oppositeKeyChar;
}

void ButtonCommandMoveForward::execute()
{
    if((GetAsyncKeyState(keyChar) & 0x8000))
        this->myCharacter->setHorzAxis(1);
    else if((GetAsyncKeyState(oppositeKeyChar) & 0x8000))
        this->myCharacter->setHorzAxis(-1);
    else
        this->myCharacter->setHorzAxis(0);
}
