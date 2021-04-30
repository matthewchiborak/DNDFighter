#ifndef VIEWDRAWINGSTRAT_H
#define VIEWDRAWINGSTRAT_H

#include "../model/gamemodel.h"
#include "drawitem.h"
#include <vector>

class ViewDrawingStrat
{
public:
    ViewDrawingStrat(GameModel * model);

    virtual void predraw(std::vector<DrawItem> * items);
    virtual void draw(std::vector<DrawItem> * items);

protected:
    GameModel * model;
};

#endif // VIEWDRAWINGSTRAT_H
