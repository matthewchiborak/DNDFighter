#ifndef CHARACTERSELECTBUILDERCONCRETE_H
#define CHARACTERSELECTBUILDERCONCRETE_H

#include "characterselectbuilder.h"

class CharacterSelectBuilderConcrete : public CharacterSelectBuilder
{
public:
    CharacterSelectBuilderConcrete(GameModel * gameModel);

    UserInputHandler * getCreatedUserInputHandler();
};

#endif // CHARACTERSELECTBUILDERCONCRETE_H
