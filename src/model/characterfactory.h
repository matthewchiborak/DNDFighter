#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H

#include <string>
#include "../controller/musiccontrollerabstract.h"

class BattleCharacter;

class CharacterFactory
{
public:
    CharacterFactory(std::string characterInfoFilepath, MusicControllerAbstract *musicController);

    virtual BattleCharacter * makeCharacter(std::string key);

protected:
    std::string characterInfoFilepath;
    MusicControllerAbstract *musicController;
};

#endif // CHARACTERFACTORY_H
