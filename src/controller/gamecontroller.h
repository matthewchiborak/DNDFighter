#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QTimer>

#include "../view/abstractview.h"
#include "../model/gamemodel.h"
#include "gamestatefactoryabstract.h"
#include "userinputhandler.h"
#include "battlebuilder.h"
#include "characterselectbuilder.h"

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(AbstractView * view, GameModel * gameModel,
                   GameStateFactoryAbstract * gameStateFactory, BattleBuilder * battleBuilder, CharacterSelectBuilder * characterSelectBuilder);

    void start();

private slots:
    void eventLoopTimerTimeout();

private:
    AbstractView * view;
    GameModel * gameModel;
    GameStateFactoryAbstract * gameStateFactory;
    BattleBuilder * battleBuilder;
    CharacterSelectBuilder * characterSelectBuilder;

    UserInputHandler * userInputHandler;

    long long theTimeNow;
    long long timeOfLastButtonEvent;
    double elapsed_millies;
    int frameCount;

    bool allowGameModelUpdates;

    void handleFrameRate();
    void switchToBattleMode();
};

#endif // GAMECONTROLLER_H
