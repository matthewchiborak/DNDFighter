#ifndef CHARACTERSELECTBUILDER_H
#define CHARACTERSELECTBUILDER_H

#include "userinputhandler.h"
#include <string>

class CharacterSelectBuilder
{
public:
    CharacterSelectBuilder(GameModel * gameModel);

    virtual UserInputHandler * getCreatedUserInputHandler();

protected:
    GameModel * gameModel;
};

#endif // CHARACTERSELECTBUILDER_H
