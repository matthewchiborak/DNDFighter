#include "drawitem.h"

DrawItem::DrawItem(float x, float y, float w, float h, std::string key, bool flip)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->key = key;
    this->flip = flip;
}
