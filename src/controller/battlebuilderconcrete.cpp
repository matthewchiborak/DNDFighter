#include "battlebuilderconcrete.h"

#include "buttoncommandpunch.h"
#include "buttoncommandkick.h"
#include "buttoncommandmoveforward.h"
#include "buttoncommandcrouch.h"
#include "buttoncommandjump.h"
#include "../model/battlecharacterplayercontrol.h"

BattleBuilderConcrete::BattleBuilderConcrete(GameModel *gameModel)//, UserInputCommandFactory *userInputCommandFactory)
    : BattleBuilder(gameModel)//, userInputCommandFactory)
{

}

void BattleBuilderConcrete::makePlayer1(std::string character, std::string type)
{
    //Probably make a factory for this based on character key passed in.
    BattleCharacterPlayerControl * newPlayer = new BattleCharacterPlayerControl(character, 1.f/500.f);
    gameModel->setCharacter1(newPlayer);

    newPlayer->setPositionX(-1);
    newPlayer->setPositionY(0);

    if(type == "Player")
    {
        resultInputHandler->addCommand(new ButtonCommandPunch(gameModel, 'E', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandKick(gameModel, 'R', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandMoveForward(gameModel, 'D', newPlayer, 1));
        resultInputHandler->addCommand(new ButtonCommandMoveForward(gameModel, 'A', newPlayer, -1));
        resultInputHandler->addCommand(new ButtonCommandCrouch(gameModel, 'S', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandJump(gameModel, 'W', newPlayer));
    }
    else if(type == "CPU")
    {

    }
}

void BattleBuilderConcrete::makePlayer2(std::string character, std::string type)
{
    //Probably make a factory for this based on character key passed in.
    BattleCharacterPlayerControl * newPlayer = new BattleCharacterPlayerControl(character, 1.f/500.f);
    gameModel->setCharacter2(newPlayer);

    newPlayer->setPositionX(1);
    newPlayer->setPositionY(0);

    if(type == "Player")
    {
        resultInputHandler->addCommand(new ButtonCommandPunch(gameModel, 'O', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandKick(gameModel, 'P', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandMoveForward(gameModel, 'L', newPlayer, 1));
        resultInputHandler->addCommand(new ButtonCommandMoveForward(gameModel, 'J', newPlayer, -1));
        resultInputHandler->addCommand(new ButtonCommandCrouch(gameModel, 'K', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandJump(gameModel, 'I', newPlayer));
    }
    else if(type == "CPU")
    {

    }
}

void BattleBuilderConcrete::makeStage(std::string stageKey)
{

}
