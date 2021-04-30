#include "viewdrawingstratcharacterselect.h"

ViewDrawingStratCharacterSelect::ViewDrawingStratCharacterSelect(GameModel * model)
    : ViewDrawingStrat(model)
{

}

void ViewDrawingStratCharacterSelect::predraw(std::vector<DrawItem> *items)
{

}

void ViewDrawingStratCharacterSelect::draw(std::vector<DrawItem> *items, std::vector<TextItem> *texts)
{
    DrawItem bg(
                -1.77f,
                0.f,
                3.55f,
                2.f,
                model->getBackgroundFile()
                );
    items->push_back(bg);

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
                    0.75f,
                    model->getCharacterSelectModel()->getCharacterWidths()->at(model->getCharacterSelectModel()->getCursorPos()),
                    model->getCharacterSelectModel()->getCharacterHeights()->at(model->getCharacterSelectModel()->getCursorPos()),
                    "\\CharacterSprites\\"
                    + model->getCharacterSelectModel()->getCharacters()->at(model->getCharacterSelectModel()->getCursorPos()) + "\\Idle.png"
                    );
        items->push_back(portraitL);

        TextItem nameL(-325, 525, 1500, 140, model->getCharacterSelectModel()->getCharacters()->at(model->getCharacterSelectModel()->getCursorPos()));
        texts->push_back(nameL);
    }
    else if(model->getCharacterSelectModel()->getnumberCharacterSelected() == 1)
    {
        DrawItem portraitL(
                    -1.5f,
                    0.75f,
                    model->getCharacterSelectModel()->getCharacterWidths()->at(model->getCharacterSelectModel()->getselectedOneIndex()),
                    model->getCharacterSelectModel()->getCharacterHeights()->at(model->getCharacterSelectModel()->getselectedOneIndex()),
                    "\\CharacterSprites\\"
                    + model->getCharacterSelectModel()->getCharacters()->at(model->getCharacterSelectModel()->getselectedOneIndex()) + "\\Idle.png"
                    );
        items->push_back(portraitL);

        TextItem nameL(-325, 525, 1500, 140, model->getCharacterSelectModel()->getCharacters()->at(model->getCharacterSelectModel()->getselectedOneIndex()));
        texts->push_back(nameL);

        DrawItem portraitR(
                    0.f,
                    0.75f,
                    model->getCharacterSelectModel()->getCharacterWidths()->at(model->getCharacterSelectModel()->getCursorPos()),
                    model->getCharacterSelectModel()->getCharacterHeights()->at(model->getCharacterSelectModel()->getCursorPos()),
                    "\\CharacterSprites\\"
                    + model->getCharacterSelectModel()->getCharacters()->at(model->getCharacterSelectModel()->getCursorPos()) + "\\Idle.png",
                    true
                    );
        items->push_back(portraitR);

        TextItem nameR(325, 525, 1500, 140, model->getCharacterSelectModel()->getCharacters()->at(model->getCharacterSelectModel()->getCursorPos()));
        texts->push_back(nameR);
    }
    else if(model->getCharacterSelectModel()->getnumberCharacterSelected() == 2)
    {
        DrawItem portraitL(
                    -1.5f,
                    0.75f,
                    model->getCharacterSelectModel()->getCharacterWidths()->at(model->getCharacterSelectModel()->getselectedOneIndex()),
                    model->getCharacterSelectModel()->getCharacterHeights()->at(model->getCharacterSelectModel()->getselectedOneIndex()),
                    "\\CharacterSprites\\"
                    + model->getCharacterSelectModel()->getCharacters()->at(model->getCharacterSelectModel()->getselectedOneIndex()) + "\\Idle.png"
                    );
        items->push_back(portraitL);

        TextItem nameL(-325, 525, 1500, 140, model->getCharacterSelectModel()->getCharacters()->at(model->getCharacterSelectModel()->getselectedOneIndex()));
        texts->push_back(nameL);

        DrawItem portraitR(
                    0.f,
                    0.75f,
                    model->getCharacterSelectModel()->getCharacterWidths()->at(model->getCharacterSelectModel()->getselectedTwoIndex()),
                    model->getCharacterSelectModel()->getCharacterHeights()->at(model->getCharacterSelectModel()->getselectedTwoIndex()),
                    "\\CharacterSprites\\"
                    + model->getCharacterSelectModel()->getCharacters()->at(model->getCharacterSelectModel()->getselectedTwoIndex()) + "\\Idle.png",
                    true
                    );
        items->push_back(portraitR);

        TextItem nameR(325, 525, 1500, 140, model->getCharacterSelectModel()->getCharacters()->at(model->getCharacterSelectModel()->getselectedTwoIndex()));
        texts->push_back(nameR);
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
