#include "gamecontroller.h"

#include <QDebug>

GameController::GameController(AbstractView *view, GameModel *gameModel, GameStateFactoryAbstract *gameStateFactory, BattleBuilder * battleBuilder, CharacterSelectBuilder *characterSelectBuilder, MusicControllerAbstract *musicController)
{
    allowGameModelUpdates = false;

    this->view = view;
    this->gameModel = gameModel;
    this->gameStateFactory = gameStateFactory;
    this->battleBuilder = battleBuilder;
    this->characterSelectBuilder = characterSelectBuilder;
    this->musicController = musicController;

    view->setDrawingStrat(gameStateFactory->getViewDrawingStrat("CharacterSelect"));
    musicController->playMusic("CharacterSelect");
    this->userInputHandler = characterSelectBuilder->getCreatedUserInputHandler();
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

    if(allowGameModelUpdates)
        gameModel->framePassed();
    else if(gameModel->getCharacterSelectModel()->getReadyToStartFight())
        switchToBattleMode();
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

void GameController::switchToBattleMode()
{
    battleBuilder->start();
    battleBuilder->makePlayer1(gameModel->getCharacterSelectModel()->getCharacters()->at(gameModel->getCharacterSelectModel()->getselectedOneIndex()), "Player");
    battleBuilder->makePlayer2(gameModel->getCharacterSelectModel()->getCharacters()->at(gameModel->getCharacterSelectModel()->getselectedTwoIndex()), "Player");
    battleBuilder->makeStage("Ship");
    this->userInputHandler = battleBuilder->getCreatedUserInputHandler();

    view->setDrawingStrat(gameStateFactory->getViewDrawingStrat("Battle"));
    musicController->playMusic("Battle");

    allowGameModelUpdates = true;
}
