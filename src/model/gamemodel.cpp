#include "gamemodel.h"

GameModel::GameModel(std::string characterListFile, MusicControllerAbstract *musicController)
    : characterSelectModel(characterListFile, musicController)
{
    this->musicController = musicController;
}

void GameModel::framePassed()
{

}

bool GameModel::gameIsDone()
{
    return false;
}

int GameModel::getNumberOfWinsNeeded()
{
    return numberOfWinsNeeded;
}

int GameModel::getNumberOfP1Rounds()
{
    return numberOfP1Rounds;
}

int GameModel::getNumberOfP2Rounds()
{
    return numberOfP2Rounds;
}

void GameModel::setNumberOfWinsNeeded(int value)
{
    numberOfWinsNeeded = value;
}

void GameModel::setNumberOfP1Rounds(int value)
{
    numberOfP1Rounds = value;
}

void GameModel::setNumberOfP2Rounds(int value)
{
    numberOfP2Rounds = value;
}

void GameModel::setCharacter1(BattleCharacter *value)
{
    character1 = value;
}

void GameModel::setCharacter2(BattleCharacter *value)
{
    character2 = value;
}

BattleCharacter *GameModel::getCharacter1()
{
    return character1;
}

BattleCharacter *GameModel::getCharacter2()
{
    return character2;
}

void GameModel::setBackgroundFile(std::string value)
{
    backgroundFile = value;
}

std::string GameModel::getBackgroundFile()
{
    return "\\Backgrounds\\" + backgroundFile + ".png";
}

CharacterSelectModel *GameModel::getCharacterSelectModel()
{
    return &characterSelectModel;
}

MusicControllerAbstract *GameModel::getMusicController()
{
    return musicController;
}
