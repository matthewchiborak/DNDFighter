#include "gamecontroller.h"

#include <QDebug>

GameController::GameController(AbstractView *view, GameModel *gameModel, GameStateFactoryAbstract *gameStateFactory, BattleBuilder * battleBuilder)
{
    this->view = view;
    this->gameModel = gameModel;
    this->gameStateFactory = gameStateFactory;
    this->battleBuilder = battleBuilder;

    view->setDrawingStrat(gameStateFactory->getViewDrawingStrat("Battle"));

    battleBuilder->start();
    battleBuilder->makePlayer1("Duke", "Player");
    battleBuilder->makePlayer2("Duke", "Player");
    battleBuilder->makeStage("Test");
    this->userInputHandler = battleBuilder->getCreatedUserInputHandler();

    connect(&eventLoopTimer, SIGNAL(timeout()), this, SLOT(eventLoopTimerTimeout()));
}

void GameController::start()
{
    eventLoopTimer.start(20);
    view->show();
}

void GameController::eventLoopTimerTimeout()
{
    this->userInputHandler->handleUserInput();
}
