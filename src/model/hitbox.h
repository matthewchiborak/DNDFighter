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
};

#endif // HITBOX_H
