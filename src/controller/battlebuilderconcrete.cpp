#include "battlebuilderconcrete.h"

#include "buttoncommandpunch.h"
#include "buttoncommandkick.h"
#include "buttoncommandmoveforward.h"
#include "buttoncommandcrouch.h"
#include "buttoncommandthrow.h"
#include "buttoncommandjump.h"
#include "buttoncommandspecial.h"
#include "battlecommandrandomactionforcpus.h"

BattleBuilderConcrete::BattleBuilderConcrete(GameModel *gameModel, CharacterFactory * characterFactory)
    : BattleBuilder(gameModel, characterFactory)
{

}

void BattleBuilderConcrete::makePlayer1(std::string character, std::string type)
{
    //Probably make a factory for this based on character key passed in.
    BattleCharacter * newPlayer = characterFactory->makeCharacter(character);
    gameModel->setCharacter1(newPlayer);

    newPlayer->setPositionX(-1.5);
    newPlayer->setPositionY(0);
    newPlayer->forceSetIsFaceRight(true);

    if(type == "Player")
    {
        resultInputHandler->addCommand(new ButtonCommandMoveForward(gameModel, 'D', newPlayer, 'A'));
        resultInputHandler->addCommand(new ButtonCommandCrouch(gameModel, 'S', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandPunch(gameModel, 'E', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandKick(gameModel, 'R', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandSpecial(gameModel, 'F', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandThrow(gameModel, 'T', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandJump(gameModel, 'W', newPlayer));
    }
    else if(type == "CPU")
    {
        resultInputHandler->addCommand(new BattleCommandRandomActionForCPUs(gameModel, 'A', newPlayer));
    }
}

void BattleBuilderConcrete::makePlayer2(std::string character, std::string type)
{
    //Probably make a factory for this based on character key passed in.
    BattleCharacter * newPlayer = characterFactory->makeCharacter(character);
    gameModel->setCharacter2(newPlayer);

    newPlayer->setPositionX(1.5 - (newPlayer->getWidth()));
    newPlayer->setPositionY(0);
    newPlayer->forceSetIsFaceRight(false);

    if(type == "Player")
    {
        resultInputHandler->addCommand(new ButtonCommandMoveForward(gameModel, 'L', newPlayer, 'J'));
        resultInputHandler->addCommand(new ButtonCommandCrouch(gameModel, 'K', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandPunch(gameModel, 'O', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandKick(gameModel, 'P', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandSpecial(gameModel, 'M', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandThrow(gameModel, 'N', newPlayer));
        resultInputHandler->addCommand(new ButtonCommandJump(gameModel, 'I', newPlayer));
    }
    else if(type == "CPU")
    {
        resultInputHandler->addCommand(new BattleCommandRandomActionForCPUs(gameModel, 'A', newPlayer));
    }
}

void BattleBuilderConcrete::makeStage(std::string stageKey)
{
    gameModel->setBackgroundFile(stageKey);
}
