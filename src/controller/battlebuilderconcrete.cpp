#include "battlebuilderconcrete.h"

#include "buttoncommandpunch.h"
#include "../model/battlecharacterplayercontrol.h"

BattleBuilderConcrete::BattleBuilderConcrete(GameModel *gameModel)//, UserInputCommandFactory *userInputCommandFactory)
    : BattleBuilder(gameModel)//, userInputCommandFactory)
{

}

void BattleBuilderConcrete::makePlayer1(std::string character, std::string type)
{
    //Probably make a factory for this based on character key passed in.
    BattleCharacterPlayerControl * newPlayer = new BattleCharacterPlayerControl(character);
    gameModel->setCharacter1(newPlayer);

    newPlayer->setPositionX(0);

    if(type == "Player")
    {
        resultInputHandler->addCommand(new ButtonCommandPunch(gameModel, 'E', newPlayer));
    }
    else if(type == "CPU")
    {

    }
}

void BattleBuilderConcrete::makePlayer2(std::string character, std::string type)
{
    //Probably make a factory for this based on character key passed in.
    BattleCharacterPlayerControl * newPlayer = new BattleCharacterPlayerControl(character);
    gameModel->setCharacter2(newPlayer);

    newPlayer->setPositionX(100);

    if(type == "Player")
    {
        resultInputHandler->addCommand(new ButtonCommandPunch(gameModel, 'O', newPlayer));
    }
    else if(type == "CPU")
    {

    }
}

void BattleBuilderConcrete::makeStage(std::string stageKey)
{

}
