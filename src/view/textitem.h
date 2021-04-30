#ifndef TEXTITEM_H
#define TEXTITEM_H

#include <string>

class TextItem
{
public:
    TextItem(float x,
             float y,
             float w,
             float h,
             std::string content);

    float x;
    float y;
    float w;
    float h;
    std::string content;
};

#endif // TEXTITEM_H
