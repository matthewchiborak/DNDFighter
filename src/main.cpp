#include <QGuiApplication>

#include "controller/gamecontroller.h"
#include "view/gameview.h"
#include "model/gamemodelconcrete.h"
#include "controller/gamestatefactoryconcrete.h"
#include "controller/battlebuilderconcrete.h"
#include "view/spriteflyweightfactory.h"
#include "model/characterfactoryconcrete.h"
#include "controller/characterselectbuilderconcrete.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    GameModelConcrete model("D:\\Qt Projects\\DNDFighter\\src\\resources\\CharacterList.txt");

    SpriteFlyweightFactory spriteFlyFact("D:\\Qt Projects\\DNDFighter\\src\\resources");

    GameView view(&spriteFlyFact);

    GameStateFactoryConcrete gameStateFactory(&model);

    CharacterFactoryConcrete characterFactory("D:\\Qt Projects\\DNDFighter\\src\\resources\\CharacterInfo");

    BattleBuilderConcrete battleBuilder(&model, &characterFactory);
    CharacterSelectBuilderConcrete characterSelectBuilder(&model);

    GameController controller(&view, &model, &gameStateFactory, &battleBuilder, &characterSelectBuilder);
    controller.start();

    return a.exec();
}
