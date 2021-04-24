#include "buttoncommand.h"

ButtonCommand::ButtonCommand(GameModel *model, char keyChar)
{
    this->model = model;
    this->keyChar = keyChar;
}

ButtonCommand::~ButtonCommand()
{

}

void ButtonCommand::execute()
{

}
