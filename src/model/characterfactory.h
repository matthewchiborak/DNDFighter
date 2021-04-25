#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H

#include <string>

class BattleCharacter;

class CharacterFactory
{
public:
    CharacterFactory(std::string characterInfoFilepath);

    virtual BattleCharacter * makeCharacter(std::string key);

protected:
    std::string characterInfoFilepath;
};

#endif // CHARACTERFACTORY_H
