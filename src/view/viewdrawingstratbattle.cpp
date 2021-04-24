#include "viewdrawingstratbattle.h"

ViewDrawingStratBattle::ViewDrawingStratBattle(GameModel *model)
    : ViewDrawingStrat(model)
{

}

void ViewDrawingStratBattle::draw(std::vector<DrawItem> *items)
{
    //model->getBackgroundImage

    //model->getCharact1().getPos etc
    DrawItem character1Item(
                model->getCharacter1()->getPositionX(),
                model->getCharacter1()->getPositionY(),
                model->getCharacter1()->getWidth(),
                model->getCharacter1()->getHeight(),
                model->getCharacter1()->getCurrentSprite()
                );
    items->push_back(character1Item);

    //character 2. etc
    DrawItem character2Item(
                model->getCharacter2()->getPositionX(),
                model->getCharacter2()->getPositionY(),
                model->getCharacter2()->getWidth(),
                model->getCharacter2()->getHeight(),
                model->getCharacter2()->getCurrentSprite()
                );
    items->push_back(character2Item);

    //model.getCharer1 get health

    //2

}
