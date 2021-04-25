#include "viewdrawingstratbattle.h"

ViewDrawingStratBattle::ViewDrawingStratBattle(GameModel *model)
    : ViewDrawingStrat(model)
{

}

void ViewDrawingStratBattle::draw(std::vector<DrawItem> *items)
{
    drawBackground(items);
    drawUI(items);
    drawCharacters(items);
}

void ViewDrawingStratBattle::drawBackground(std::vector<DrawItem> *items)
{

}

void ViewDrawingStratBattle::drawCharacters(std::vector<DrawItem> *items)
{
    DrawItem character1Item(
                model->getCharacter1()->getPositionX(),
                model->getCharacter1()->getPositionY(),
                model->getCharacter1()->getWidth(),
                model->getCharacter1()->getHeight(),
                model->getCharacter1()->getCurrentSprite()
                );
    items->push_back(character1Item);

    DrawItem character2Item(
                model->getCharacter2()->getPositionX(),
                model->getCharacter2()->getPositionY(),
                model->getCharacter2()->getWidth(),
                model->getCharacter2()->getHeight(),
                model->getCharacter2()->getCurrentSprite()
                );
    items->push_back(character2Item);
}

void ViewDrawingStratBattle::drawUI(std::vector<DrawItem> *items)
{
    DrawItem character1Item(
                -1.7f,
                1.7f,
                0.3f,
                0.3f,
                "\\CharacterSprites\\" + model->getCharacter1()->getSpriteKeyPrefix() + "\\Icon.png"
                );
    items->push_back(character1Item);

    DrawItem char1HealthBarBack(
                -1.3f,
                1.85f,
                1.2f,
                0.1f,
                "\\UI\\HealthBarBack.png"
                );
    items->push_back(char1HealthBarBack);
    DrawItem char1HealthBarFront(
                -1.3f,
                1.85f,
                1.2f * model->getCharacter1()->getHealthPercentage(),
                0.1f,
                "\\UI\\HealthBarFront.png"
                );
    items->push_back(char1HealthBarFront);
    /////////////////////////////////////

    DrawItem character2Item(
                1.7f - 0.3f,
                1.7f,
                0.3f,
                0.3f,
                "\\CharacterSprites\\" + model->getCharacter2()->getSpriteKeyPrefix() + "\\Icon.png",
                true
                );
    items->push_back(character2Item);

    DrawItem char2HealthBarBack(
                0.1f,
                1.85f,
                1.2f,
                0.1f,
                "\\UI\\HealthBarBack.png"
                );
    items->push_back(char2HealthBarBack);
    DrawItem char2HealthBarFront(
                0.1f + 1.2f * model->getCharacter2()->getHealthPercentage(),
                1.85f,
                1.2f * model->getCharacter2()->getHealthPercentage(),
                0.1f,
                "\\UI\\HealthBarFront.png"
                );
    items->push_back(char2HealthBarFront);
}
