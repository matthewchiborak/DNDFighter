#ifndef DRAWITEM_H
#define DRAWITEM_H

#include <string>

class DrawItem
{
public:
    DrawItem(float x,
    float y,
    float w,
    float h,
    std::string key,
    bool flip = false);

    float x;
    float y;
    float w;
    float h;
    std::string key;
    bool flip;
};

#endif // DRAWITEM_H
