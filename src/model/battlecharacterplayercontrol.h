#ifndef BATTLECHARACTERPLAYERCONTROL_H
#define BATTLECHARACTERPLAYERCONTROL_H

#include "battlecharacter.h"

class BattleCharacterPlayerControl : public BattleCharacter
{
public:
    BattleCharacterPlayerControl(std::string spriteKeyPrefix);

    void punch();
    void kick();
    void move(int dir);
    void special(std::string key);
};

#endif // BATTLECHARACTERPLAYERCONTROL_H
