#include "userinputhandler.h"


UserInputHandler::UserInputHandler(GameModel *model)
{
    this->model = model;
}

UserInputHandler::~UserInputHandler()
{
    for(int i = 0; i < buttonCommands.size(); i++)
    {
        delete buttonCommands.at(i);
    }
}

void UserInputHandler::addCommand(ButtonCommand *command)
{
    buttonCommands.push_back(command);
}

void UserInputHandler::handleUserInput()
{
    for(int i = 0; i < buttonCommands.size(); i++)
    {
        buttonCommands.at(i)->execute();
    }
}
