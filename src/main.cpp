#include <QGuiApplication>

#include "controller/gamecontroller.h"
#include "view/gameview.h"
#include "model/gamemodelconcrete.h"
#include "controller/gamestatefactoryconcrete.h"
#include "controller/battlebuilderconcrete.h"
#include "view/spriteflyweightfactory.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    GameModelConcrete model;

    SpriteFlyweightFactory spriteFlyFact("D:\\Qt Projects\\DNDFighter\\src\\resources");

    GameView view(&spriteFlyFact);

    GameStateFactoryConcrete gameStateFactory(&model);

    BattleBuilderConcrete battleBuilder(&model);

    GameController controller(&view, &model, &gameStateFactory, &battleBuilder);
    controller.start();

    return a.exec();
}
