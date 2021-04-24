#include "battlebuilder.h"

BattleBuilder::BattleBuilder(GameModel *gameModel)//, UserInputCommandFactory *userInputCommandFactory)
{
    //this->userInputCommandFactory = userInputCommandFactory;
    this->gameModel = gameModel;
    this->resultInputHandler = nullptr;
}

void BattleBuilder::start()
{
    if(resultInputHandler!=nullptr)
        delete resultInputHandler;

    resultInputHandler = new UserInputHandler(gameModel);
}

void BattleBuilder::makePlayer1(std::string character, std::string type)
{

}

void BattleBuilder::makePlayer2(std::string character, std::string type)
{

}

void BattleBuilder::makeStage(std::string stageKey)
{

}

UserInputHandler *BattleBuilder::getCreatedUserInputHandler()
{
    return resultInputHandler;
}
