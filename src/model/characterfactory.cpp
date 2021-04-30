#include "characterfactory.h"

CharacterFactory::CharacterFactory(std::string characterInfoFilepath, MusicControllerAbstract *musicController)
{
    this->characterInfoFilepath = characterInfoFilepath;
    this->musicController = musicController;
}

BattleCharacter *CharacterFactory::makeCharacter(std::string key)
{
    return nullptr;
}
