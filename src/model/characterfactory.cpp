#include "characterfactory.h"

CharacterFactory::CharacterFactory(std::string characterInfoFilepath)
{
    this->characterInfoFilepath = characterInfoFilepath;
}

BattleCharacter *CharacterFactory::makeCharacter(std::string key)
{
    return nullptr;
}
