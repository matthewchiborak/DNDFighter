#include <QGuiApplication>

#include "controller/gamecontroller.h"
#include "view/gameview.h"
#include "model/gamemodelconcrete.h"
#include "controller/gamestatefactoryconcrete.h"
#include "controller/battlebuilderconcrete.h"
#include "view/spriteflyweightfactory.h"
#include "model/characterfactoryconcrete.h"
#include "controller/characterselectbuilderconcrete.h"
#include "controller/musiccontrollerconcrete.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    MusicControllerConcrete musicController("D:\\Qt Projects\\DNDFighter\\src\\resources\\Music",
                "D:\\Qt Projects\\DNDFighter\\src\\resources\\SFX");
    musicController.manualLoad("Hit", "Hit.wav");
    musicController.manualLoad("Attack", "Throw.wav");
    musicController.manualLoad("Block", "Block.wav");
    musicController.manualLoad("MenuCancel", "MenuCancel.wav");
    musicController.manualLoad("MenuMove", "MenuMove.wav");
    musicController.manualLoad("MenuEnter", "MenuSelect.wav");
    musicController.manualLoad("Battle", "Battle.wav");
    musicController.manualLoad("CharacterSelect", "CharacterSelect.mp3");

    GameModelConcrete model("D:\\Qt Projects\\DNDFighter\\src\\resources\\CharacterList.txt", &musicController);

    SpriteFlyweightFactory spriteFlyFact("D:\\Qt Projects\\DNDFighter\\src\\resources");

    GameView view(&spriteFlyFact);

    GameStateFactoryConcrete gameStateFactory(&model);

    CharacterFactoryConcrete characterFactory("D:\\Qt Projects\\DNDFighter\\src\\resources\\CharacterInfo", &musicController);

    BattleBuilderConcrete battleBuilder(&model, &characterFactory);
    CharacterSelectBuilderConcrete characterSelectBuilder(&model);

    GameController controller(&view, &model, &gameStateFactory, &battleBuilder, &characterSelectBuilder, &musicController);
    controller.start();

    return a.exec();
}
