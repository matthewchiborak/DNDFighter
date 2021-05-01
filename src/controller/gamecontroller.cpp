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
    {
        if(gameModel->gameIsDone())
        {
            switchToCharacterSelect();
            return;
        }
    }

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
    gameModel->setNumberOfP1Rounds(0);
    gameModel->setNumberOfP2Rounds(0);

    battleBuilder->start();
    if(gameModel->getCharacterSelectModel()->getP1IsACPU())
        battleBuilder->makePlayer1(gameModel->getCharacterSelectModel()->getCharacters()->at(gameModel->getCharacterSelectModel()->getselectedOneIndex()), "CPU");
    else
        battleBuilder->makePlayer1(gameModel->getCharacterSelectModel()->getCharacters()->at(gameModel->getCharacterSelectModel()->getselectedOneIndex()), "Player");
    if(gameModel->getCharacterSelectModel()->getP2IsACPU())
        battleBuilder->makePlayer2(gameModel->getCharacterSelectModel()->getCharacters()->at(gameModel->getCharacterSelectModel()->getselectedTwoIndex()), "CPU");
    else
        battleBuilder->makePlayer2(gameModel->getCharacterSelectModel()->getCharacters()->at(gameModel->getCharacterSelectModel()->getselectedTwoIndex()), "Player");
    battleBuilder->makeStage("Ship");

    UserInputHandler * temp = this->userInputHandler;
    this->userInputHandler = battleBuilder->getCreatedUserInputHandler();
    delete temp;

    view->setDrawingStrat(gameStateFactory->getViewDrawingStrat("Battle"));
    musicController->playMusic("Battle");

    allowGameModelUpdates = true;
}

void GameController::switchToCharacterSelect()
{
    allowGameModelUpdates = false;

    gameModel->getCharacterSelectModel()->reset();

    UserInputHandler * temp = this->userInputHandler;
    this->userInputHandler = characterSelectBuilder->getCreatedUserInputHandler();
    delete temp;

    gameModel->setBackgroundFile("CharacterSelect");
    view->setDrawingStrat(gameStateFactory->getViewDrawingStrat("CharacterSelect"));
    musicController->playMusic("CharacterSelect");
}
