#ifndef VIEWDRAWINGSTRATCHARACTERSELECT_H
#define VIEWDRAWINGSTRATCHARACTERSELECT_H

#include "viewdrawingstrat.h"

class ViewDrawingStratCharacterSelect : public ViewDrawingStrat
{
public:
    ViewDrawingStratCharacterSelect(GameModel * model);

    void draw(std::vector<DrawItem> * items);
};

#endif // VIEWDRAWINGSTRATCHARACTERSELECT_H
