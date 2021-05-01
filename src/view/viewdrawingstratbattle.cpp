#include "viewdrawingstratbattle.h"

#include <QDebug>

ViewDrawingStratBattle::ViewDrawingStratBattle(GameModel *model)
    : ViewDrawingStrat(model)
{

}

void ViewDrawingStratBattle::predraw(std::vector<DrawItem> *items)
{
    std::vector<std::string> * allSprites1 = model->getCharacter1()->getAllSprites();
    std::vector<std::string> * allSprites2 = model->getCharacter2()->getAllSprites();

    for(int i = 0; i < allSprites1->size(); i++)
    {
        DrawItem character1Item(
                    0,0,0,0,
                    allSprites1->at(i)
                    );
        items->push_back(character1Item);
    }
    for(int i = 0; i < allSprites2->size(); i++)
    {
        DrawItem character1Item(
                    0,0,0,0,
                    allSprites2->at(i)
                    );
        items->push_back(character1Item);
    }

    delete allSprites1;
    delete allSprites2;
}

void ViewDrawingStratBattle::draw(std::vector<DrawItem> *items, std::vector<TextItem> *texts)
{
    drawBackground(items);
    drawUI(items);
    drawCharacters(items);
    drawHitBoxes(items);
}

void ViewDrawingStratBattle::drawBackground(std::vector<DrawItem> *items)
{
    DrawItem character2Item(
                -1.77f,
                0.f,
                3.55f,
                2.f,
                model->getBackgroundFile()
                );
    items->push_back(character2Item);
}

void ViewDrawingStratBattle::drawCharacters(std::vector<DrawItem> *items)
{
    DrawItem character1Item(
                model->getCharacter1()->getPositionX(),
                model->getCharacter1()->getPositionY(),
                model->getCharacter1()->getWidth(),
                model->getCharacter1()->getHeight(),
                model->getCharacter1()->getCurrentSprite(),
                !model->getCharacter1()->getIsFaceRight()
                );
    items->push_back(character1Item);

    DrawItem character2Item(
                model->getCharacter2()->getPositionX(),
                model->getCharacter2()->getPositionY(),
                model->getCharacter2()->getWidth(),
                model->getCharacter2()->getHeight(),
                model->getCharacter2()->getCurrentSprite(),
                !model->getCharacter2()->getIsFaceRight()
                );
    items->push_back(character2Item);
}

void ViewDrawingStratBattle::drawHitBoxes(std::vector<DrawItem> *items)
{
    drawHitBoxACharacter(items, model->getCharacter1());
    drawHitBoxACharacter(items, model->getCharacter2());
}

void ViewDrawingStratBattle::drawHitBoxACharacter(std::vector<DrawItem> *items, BattleCharacter *character)
{
    for(int i = 0; i < character->getActiveHitBoxes()->size(); i++)
    {
        if(character->getActiveHitBoxes()->at(i)->gethasVisuals())
        {
            DrawItem hitbox1(
                        character->getActiveHitBoxes()->at(i)->getPosX(),
                        character->getActiveHitBoxes()->at(i)->getPosY(),
                        character->getActiveHitBoxes()->at(i)->getwidth(),
                        character->getActiveHitBoxes()->at(i)->getheight(),
                        "\\CharacterSprites\\" + character->getSpriteKeyPrefix() + "\\" + character->getActiveHitBoxes()->at(i)->getsprite() + ".png",
                        character->getActiveHitBoxes()->at(i)->getFlipSprite()
                        );
            items->push_back(hitbox1);
        }
        else
        {
            //Just to testing where the normals are. Wont have this in final
            DrawItem hitbox1(
                        character->getActiveHitBoxes()->at(i)->getPosX(),
                        character->getActiveHitBoxes()->at(i)->getPosY(),
                        character->getActiveHitBoxes()->at(i)->getwidth(),
                        character->getActiveHitBoxes()->at(i)->getheight(),
                        "\\UI\\HealthBarBack.png"
                        );
            items->push_back(hitbox1);
        }
    }

    DrawItem hurtbox(
                character->gethurtBoxPosX(),
                character->gethurtBoxPosY(),
                character->gethurtBoxWidth(),
                character->gethurtBoxHeight(),
                "\\UI\\HurtBox.png"
                );
    items->push_back(hurtbox);
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
                -1.35f,
                1.8f,
                1.2f,
                0.1f,
                "\\UI\\HealthBarBack.png"
                );
    items->push_back(char1HealthBarBack);
    DrawItem char1HealthBarFront(
                -1.35f + (1.2f - 1.2f * model->getCharacter1()->getHealthPercentage()),
                1.8f,
                1.2f * model->getCharacter1()->getHealthPercentage(),
                0.1f,
                "\\UI\\HealthBarFront.png"
                );
    items->push_back(char1HealthBarFront);

    for(int i = 0; i < model->getNumberOfWinsNeeded(); i++)
    {
        std::string path = "\\UI\\RoundEmpty.png";
        if(i < model->getNumberOfP1Rounds())
        {
            path = "\\UI\\RoundWin.png";
        }

        DrawItem round(
                    -1.35f + 1.2f - (0.11 * (i+1)),
                    1.69f,
                    0.1f,
                    0.1f,
                    path
                    );
        items->push_back(round);
    }
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
                0.15f,
                1.8f,
                1.2f,
                0.1f,
                "\\UI\\HealthBarBack.png"
                );
    items->push_back(char2HealthBarBack);
    DrawItem char2HealthBarFront(
                0.15f,
                1.8f,
                1.2f * model->getCharacter2()->getHealthPercentage(),
                0.1f,
                "\\UI\\HealthBarFront.png"
                );
    items->push_back(char2HealthBarFront);

    for(int i = 0; i < model->getNumberOfWinsNeeded(); i++)
    {
        std::string path = "\\UI\\RoundEmpty.png";
        if(i < model->getNumberOfP2Rounds())
        {
            path = "\\UI\\RoundWin.png";
        }

        DrawItem round(
                    0.15f + (0.11 * i),
                    1.69f,
                    0.1f,
                    0.1f,
                    path
                    );
        items->push_back(round);
    }
}
