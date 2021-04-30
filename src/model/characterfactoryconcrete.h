#ifndef CHARACTERFACTORYCONCRETE_H
#define CHARACTERFACTORYCONCRETE_H

#include "characterfactory.h"

#include "specialpropertycommand.h"

class CharacterFactoryConcrete : public CharacterFactory
{
public:
    CharacterFactoryConcrete(std::string characterInfoFilepath, MusicControllerAbstract *musicController);

    BattleCharacter * makeCharacter(std::string key);

private:
    SpecialPropertyCommand * getSpecialPropertyCommand(std::string key, BattleCharacter * user);
};

#endif // CHARACTERFACTORYCONCRETE_H
