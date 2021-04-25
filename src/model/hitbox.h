#ifndef HITBOX_H
#define HITBOX_H

#include <string>

class HitBox
{
public:
    HitBox();

private:
    bool hasVisuals;
    std::string sprite;
    int duration;
    int hitstun;
    int damage;
    float width;
    float height;
    float velocity;
    int heightForBlocking; //0 - low, 1 - mid, 2- overhead
};

#endif // HITBOX_H
