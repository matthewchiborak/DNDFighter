#include "characterselectbuilder.h"

CharacterSelectBuilder::CharacterSelectBuilder(GameModel *gameModel)
{
    this->gameModel = gameModel;
}

UserInputHandler *CharacterSelectBuilder::getCreatedUserInputHandler()
{
    return nullptr;
}
