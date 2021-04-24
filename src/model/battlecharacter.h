#ifndef BATTLECHARACTER_H
#define BATTLECHARACTER_H

#include <string>

class BattleCharacter
{
public:
    BattleCharacter(std::string spriteKeyPrefix);

    void setIsCrouching(bool value);

    virtual void punch();
    virtual void kick();
    virtual void move(int dir);
    virtual void special(std::string key);

    float getPositionX();
    void setPositionX(float value);

    std::string getCurrentSprite();

protected:
    bool isCrouching;
    float positionX;
    std::string spriteKeyPrefix;
    std::string currentSpriteKeySuffix;
};

#endif // BATTLECHARACTER_H
