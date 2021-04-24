#include <QGuiApplication>

#include "controller/gamecontroller.h"
#include "view/gameview.h"
#include "model/gamemodelconcrete.h"
#include "controller/gamestatefactoryconcrete.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    GameModelConcrete model;

    GameView view;

    GameStateFactoryConcrete gameStateFactory(&model);

    GameController controller(&view, &model, &gameStateFactory);
    controller.start();

    return a.exec();
}
