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
}

void GameController::start()
{
    auto nowTime = std::chrono::system_clock::now().time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(nowTime).count();
    theTimeNow = (millis);
    timeOfLastButtonEvent = theTimeNow;
    frameCount = 0;

    connect(view, SIGNAL(frameInited()), this, SLOT(eventLoopTimerTimeout()));
    view->show();
}

void GameController::eventLoopTimerTimeout()
{
    this->userInputHandler->handleUserInput();

    gameModel->framePassed();

    //handleFrameRate();
}

void GameController::handleFrameRate()
{
    frameCount++;

    auto nowTime = std::chrono::system_clock::now().time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(nowTime).count();
    theTimeNow =(millis);
    elapsed_millies = theTimeNow - timeOfLastButtonEvent;


    if(elapsed_millies >= 1000)
    {
        qDebug() << "FPS: " << frameCount;
        timeOfLastButtonEvent = theTimeNow;
        frameCount = 0;
    }
}
