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

    virtual bool gameIsDone();

    int getNumberOfWinsNeeded();
    int getNumberOfP1Rounds();
    int getNumberOfP2Rounds();
    void setNumberOfWinsNeeded(int value);
    void setNumberOfP1Rounds(int value);
    void setNumberOfP2Rounds(int value);

    void setCharacter1(BattleCharacter * value);
    void setCharacter2(BattleCharacter * value);
    BattleCharacter * getCharacter1();
    BattleCharacter * getCharacter2();
    void setBackgroundFile(std::string value);
    std::string getBackgroundFile();

    CharacterSelectModel * getCharacterSelectModel();
    MusicControllerAbstract *  getMusicController();

protected:
    BattleCharacter * character1;
    BattleCharacter * character2;
    CharacterSelectModel characterSelectModel;
    MusicControllerAbstract * musicController;
    std::string backgroundFile;

    int numberOfWinsNeeded;
    int numberOfP1Rounds;
    int numberOfP2Rounds;
};

#endif // GAMEMODEL_H
