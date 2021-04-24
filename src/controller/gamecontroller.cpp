#include "gamecontroller.h"

#include <QDebug>

GameController::GameController(AbstractView *view, GameModel *gameModel, GameStateFactoryAbstract *gameStateFactory)
{
    this->view = view;
    this->gameModel = gameModel;
    this->gameStateFactory = gameStateFactory;

    view->setDrawingStrat(gameStateFactory->getViewDrawingStrat("Battle"));
    this->userInputState = gameStateFactory->getUserInputState("Battle");

    connect(&eventLoopTimer, SIGNAL(timeout()), this, SLOT(eventLoopTimerTimeout()));
}

void GameController::start()
{
    eventLoopTimer.start(20);
    view->show();
}

void GameController::eventLoopTimerTimeout()
{

}
