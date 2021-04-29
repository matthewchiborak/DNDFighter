#include "viewdrawingstratcharacterselect.h"

ViewDrawingStratCharacterSelect::ViewDrawingStratCharacterSelect(GameModel * model)
    : ViewDrawingStrat(model)
{

}

void ViewDrawingStratCharacterSelect::draw(std::vector<DrawItem> *items)
{
    for(int i = 0; i < model->getCharacterSelectModel()->getCharacters()->size(); i++)
    {
        DrawItem portrait(
                    -1.5f + ((i/2)*0.3f) + 0.025f,
                    (((i+1)%2)*0.3f) + 0.025f,
                    0.3f - 0.05f,
                    0.3f - 0.05f,
                    "\\CharacterSprites\\" + model->getCharacterSelectModel()->getCharacters()->at(i) + "\\Icon.png"
                    );
        items->push_back(portrait);
    }

    if(model->getCharacterSelectModel()->getnumberCharacterSelected() == 0)
    {
        DrawItem portraitL(
                    -1.5f,
                    0.85f,
                    model->getCharacterSelectModel()->getCharacterWidths()->at(model->getCharacterSelectModel()->getCursorPos()),
                    model->getCharacterSelectModel()->getCharacterHeights()->at(model->getCharacterSelectModel()->getCursorPos()),
                    "\\CharacterSprites\\"
                    + model->getCharacterSelectModel()->getCharacters()->at(model->getCharacterSelectModel()->getCursorPos()) + "\\Idle.png"
                    );
        items->push_back(portraitL);
    }
    else if(model->getCharacterSelectModel()->getnumberCharacterSelected() == 1)
    {
        DrawItem portraitL(
                    -1.5f,
                    0.85f,
                    model->getCharacterSelectModel()->getCharacterWidths()->at(model->getCharacterSelectModel()->getselectedOneIndex()),
                    model->getCharacterSelectModel()->getCharacterHeights()->at(model->getCharacterSelectModel()->getselectedOneIndex()),
                    "\\CharacterSprites\\"
                    + model->getCharacterSelectModel()->getCharacters()->at(model->getCharacterSelectModel()->getselectedOneIndex()) + "\\Idle.png"
                    );
        items->push_back(portraitL);
        DrawItem portraitR(
                    0.f,
                    0.85f,
                    model->getCharacterSelectModel()->getCharacterWidths()->at(model->getCharacterSelectModel()->getCursorPos()),
                    model->getCharacterSelectModel()->getCharacterHeights()->at(model->getCharacterSelectModel()->getCursorPos()),
                    "\\CharacterSprites\\"
                    + model->getCharacterSelectModel()->getCharacters()->at(model->getCharacterSelectModel()->getCursorPos()) + "\\Idle.png",
                    true
                    );
        items->push_back(portraitR);
    }
    else if(model->getCharacterSelectModel()->getnumberCharacterSelected() == 2)
    {
        DrawItem portraitL(
                    -1.5f,
                    0.85f,
                    model->getCharacterSelectModel()->getCharacterWidths()->at(model->getCharacterSelectModel()->getselectedOneIndex()),
                    model->getCharacterSelectModel()->getCharacterHeights()->at(model->getCharacterSelectModel()->getselectedOneIndex()),
                    "\\CharacterSprites\\"
                    + model->getCharacterSelectModel()->getCharacters()->at(model->getCharacterSelectModel()->getselectedOneIndex()) + "\\Idle.png"
                    );
        items->push_back(portraitL);
        DrawItem portraitR(
                    0.f,
                    0.85f,
                    model->getCharacterSelectModel()->getCharacterWidths()->at(model->getCharacterSelectModel()->getselectedTwoIndex()),
                    model->getCharacterSelectModel()->getCharacterHeights()->at(model->getCharacterSelectModel()->getselectedTwoIndex()),
                    "\\CharacterSprites\\"
                    + model->getCharacterSelectModel()->getCharacters()->at(model->getCharacterSelectModel()->getselectedTwoIndex()) + "\\Idle.png",
                    true
                    );
        items->push_back(portraitR);
    }


    if(model->getCharacterSelectModel()->getnumberCharacterSelected() < 2)
    {
        DrawItem cursor(
                    -1.5f + ((model->getCharacterSelectModel()->getCursorPos()/2)*0.3f),
                    (((model->getCharacterSelectModel()->getCursorPos()+1)%2)*0.3f),
                    0.3f,
                    0.3f,
                    "\\UI\\SelectCursor.png"
                    );
        items->push_back(cursor);
    }
}
