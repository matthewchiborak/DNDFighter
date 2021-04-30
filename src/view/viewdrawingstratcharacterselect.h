#ifndef VIEWDRAWINGSTRATCHARACTERSELECT_H
#define VIEWDRAWINGSTRATCHARACTERSELECT_H

#include "viewdrawingstrat.h"

class ViewDrawingStratCharacterSelect : public ViewDrawingStrat
{
public:
    ViewDrawingStratCharacterSelect(GameModel * model);

    void predraw(std::vector<DrawItem> * items);
    void draw(std::vector<DrawItem> * items, std::vector<TextItem> * texts);
};

#endif // VIEWDRAWINGSTRATCHARACTERSELECT_H
