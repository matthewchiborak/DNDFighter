#ifndef HITBOX_H
#define HITBOX_H

#include <string>

class HitBox
{
public:
    HitBox(
            float posx,
            float posy,
            bool hasVisuals,
            std::string sprite,
            int duration,
            int hitstun,
            int damage,
            float width,
            float height,
            float velocityX,
            float velocityY,
            int heightForBlocking,
            bool isFixedToCharacter,
            float characterPosX,
            float characterPosY
            );

    bool gethasVisuals();
    std::string getsprite();
    int getduration();
    int gethitstun();
    int getdamage();
    float getwidth();
    float getheight();
    float getvelocityX();
    float getvelocityY();
    int getheightForBlocking();
    bool getisFixedToCharacter();

    void setPos(float charPosX, float charPosY);
    void advance();
    bool isDone();

    float getPosX();
    float getPosY();

private:
    float spawnPosX;
    float spawnPosY;
    float posx;
    float posy;
    bool hasVisuals;
    std::string sprite;
    int lifeTime;
    int duration;
    int hitstun;
    int damage;
    float width;
    float height;
    float velocityX;
    float velocityY;
    int heightForBlocking; //0 - low, 1 - mid, 2- overhead
    bool isFixedToCharacter;

    float characterPosXAtSpawn;
    float characterPosYAtSpawn;
};

#endif // HITBOX_H
