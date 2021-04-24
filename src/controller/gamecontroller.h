#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QTimer>

#include "../view/abstractview.h"
#include "../model/gamemodel.h"
#include "gamestatefactoryabstract.h"
#include "userinputhandler.h"
#include "battlebuilder.h"

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(AbstractView * view, GameModel * gameModel, GameStateFactoryAbstract * gameStateFactory, BattleBuilder * battleBuilder);

    void start();

private slots:
    void eventLoopTimerTimeout();

private:
    QTimer eventLoopTimer;

    AbstractView * view;
    GameModel * gameModel;
    GameStateFactoryAbstract * gameStateFactory;
    BattleBuilder * battleBuilder;

    UserInputHandler * userInputHandler;

};

#endif // GAMECONTROLLER_H