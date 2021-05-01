#ifndef HITBOX_H
#define HITBOX_H

#include <string>

class HitBox
{
public:
    HitBox(
            std::string identifier,
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
            float characterPosY,
            bool forceJumpSelf,
            bool forceJumpEnemy,
            bool forceAJumpEnemyInAirOkay,
            int forceJumpDir,
            bool isUnBlockable,
            bool flip = false
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
    void makeDone();

    float getPosX();
    float getPosY();

    bool getforceAJumpEnemy();
    bool getForceAJumpInAirOkay();
    bool getforceAJumpSelf();
    int getforceJumpDir();

    bool getFlipSprite();

    bool getIsUnblockable();

    static bool boxCollisions(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

    bool isAProjectile();

    std::string getIdentifier();

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
    bool forceAJumpEnemy;
    bool forceAJumpEnemyInAirOkay;
    bool forceAJumpSelf;
    int forceJumpDir;
    bool isUnblockable;

    bool flipSprite;

    float characterPosXAtSpawn;
    float characterPosYAtSpawn;

    std::string identifier;
};

#endif // HITBOX_H
