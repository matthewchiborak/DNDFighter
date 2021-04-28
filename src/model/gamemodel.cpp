#include "gamemodel.h"

GameModel::GameModel(std::string characterListFile)
    : characterSelectModel(characterListFile)
{

}

void GameModel::framePassed()
{

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

CharacterSelectModel *GameModel::getCharacterSelectModel()
{
    return &characterSelectModel;
}
