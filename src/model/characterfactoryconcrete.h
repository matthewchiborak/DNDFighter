#ifndef CHARACTERFACTORYCONCRETE_H
#define CHARACTERFACTORYCONCRETE_H

#include "characterfactory.h"

class CharacterFactoryConcrete : public CharacterFactory
{
public:
    CharacterFactoryConcrete(std::string characterInfoFilepath);

    BattleCharacter * makeCharacter(std::string key);
};

#endif // CHARACTERFACTORYCONCRETE_H
