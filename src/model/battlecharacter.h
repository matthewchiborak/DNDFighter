#ifndef BATTLECHARACTER_H
#define BATTLECHARACTER_H

#include <string>

class BattleCharacter
{
public:
    BattleCharacter(std::string spriteKeyPrefix, float walkSpeed);

    virtual void setIsCrouching(bool value);

    virtual void framePassed();

    virtual void punch();
    virtual void kick();
    virtual void move(double dir);
    virtual void special(std::string key);
    virtual void jump();

    float getPositionX();
    void setPositionX(float value);
    float getPositionY();
    void setPositionY(float value);
    float getWidth();
    void setWidth(float value);
    float getHeight();
    void setHeight(float value);

    std::string getCurrentSprite();

    virtual void applyGravity();

protected:
    bool isCrouching;
    float width;
    float height;
    float positionX;
    float positionY;
    std::string spriteKeyPrefix;
    std::string currentSpriteKeySuffix;

    float walkSpeed;
    int recovery;
};

#endif // BATTLECHARACTER_H
