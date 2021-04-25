#ifndef BATTLECHARACTER_H
#define BATTLECHARACTER_H

#include <string>

class BattleCharacter
{
public:
    BattleCharacter(std::string spriteKeyPrefix, float walkSpeed, int health);

    virtual void setHorzAxis(int value);
    virtual void setVertAxis(int value);

    virtual void framePassed();

    virtual void punch();
    virtual void kick();
    virtual void move(double dir);
    virtual void special(std::string key);
    virtual void jump();
    virtual void doThrow();

    float getPositionX();
    void setPositionX(float value);
    float getPositionY();
    void setPositionY(float value);
    float getWidth();
    void setWidth(float value);
    float getHeight();
    void setHeight(float value);

    std::string getCurrentSprite();
    std::string getSpriteKeyPrefix();

    virtual void applyGravity();

    void doDamage(int amount);
    float getHealthPercentage();

protected:
    int currentHealth;
    int maxHealth;

    int axisHorz = 0;
    int axisVert = 0;

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
