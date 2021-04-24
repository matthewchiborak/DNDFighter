#include "drawitem.h"

DrawItem::DrawItem(int x, int y, int w, int h, std::string key, bool flip)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->key = key;
    this->flip = flip;
}
