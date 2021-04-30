#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "battlecharacter.h"
#include "characterselectmodel.h"
#include "../controller/musiccontrollerabstract.h"

class GameModel
{
public:
    GameModel(std::string characterListFile, MusicControllerAbstract * musicController);

    virtual void framePassed();

    void setCharacter1(BattleCharacter * value);
    void setCharacter2(BattleCharacter * value);
    BattleCharacter * getCharacter1();
    BattleCharacter * getCharacter2();

    CharacterSelectModel * getCharacterSelectModel();
    MusicControllerAbstract *  getMusicController();

protected:
    BattleCharacter * character1;
    BattleCharacter * character2;
    CharacterSelectModel characterSelectModel;
    MusicControllerAbstract * musicController;
};

#endif // GAMEMODEL_H
