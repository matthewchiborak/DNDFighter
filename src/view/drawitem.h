#ifndef DRAWITEM_H
#define DRAWITEM_H

#include <string>

class DrawItem
{
public:
    DrawItem(int x,
    int y,
    int w,
    int h,
    std::string key,
    bool flip = false);

    int x;
    int y;
    int w;
    int h;
    std::string key;
    bool flip;
};

#endif // DRAWITEM_H
