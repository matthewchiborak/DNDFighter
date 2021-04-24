#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "battlecharacter.h"

class GameModel
{
public:
    GameModel();

    void setCharacter1(BattleCharacter * value);
    void setCharacter2(BattleCharacter * value);
    BattleCharacter * getCharacter1();
    BattleCharacter * getCharacter2();

protected:
    BattleCharacter * character1;
    BattleCharacter * character2;
};

#endif // GAMEMODEL_H
