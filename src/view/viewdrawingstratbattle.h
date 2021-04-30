#ifndef VIEWDRAWINGSTRATBATTLE_H
#define VIEWDRAWINGSTRATBATTLE_H

#include "viewdrawingstrat.h"

class ViewDrawingStratBattle : public ViewDrawingStrat
{
public:
    ViewDrawingStratBattle(GameModel * model);

    void predraw(std::vector<DrawItem> * items);
    void draw(std::vector<DrawItem> * items, std::vector<TextItem> * texts);

private:
    void drawBackground(std::vector<DrawItem> *items);
    void drawCharacters(std::vector<DrawItem> *items);
    void drawHitBoxes(std::vector<DrawItem> *items);
    void drawHitBoxACharacter(std::vector<DrawItem> *items, BattleCharacter * character);

    void drawUI(std::vector<DrawItem> *items);
};

#endif // VIEWDRAWINGSTRATBATTLE_H
