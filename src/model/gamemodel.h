#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "battlecharacter.h"
#include "characterselectmodel.h"

class GameModel
{
public:
    GameModel(std::string characterListFile);

    virtual void framePassed();

    void setCharacter1(BattleCharacter * value);
    void setCharacter2(BattleCharacter * value);
    BattleCharacter * getCharacter1();
    BattleCharacter * getCharacter2();

    CharacterSelectModel * getCharacterSelectModel();

protected:
    BattleCharacter * character1;
    BattleCharacter * character2;
    CharacterSelectModel characterSelectModel;
};

#endif // GAMEMODEL_H
