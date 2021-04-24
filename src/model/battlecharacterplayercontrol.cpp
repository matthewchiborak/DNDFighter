#include "battlecharacterplayercontrol.h"

#include <QDebug>

BattleCharacterPlayerControl::BattleCharacterPlayerControl(std::string spriteKeyPrefix)
    : BattleCharacter(spriteKeyPrefix)
{

}

void BattleCharacterPlayerControl::punch()
{
    qDebug() << "Do a punch";
    currentSpriteKeySuffix = "Punch";
}

void BattleCharacterPlayerControl::kick()
{
    qDebug() << "Do a kick";
}

void BattleCharacterPlayerControl::move(int dir)
{
    qDebug() << "Do a move";
}

void BattleCharacterPlayerControl::special(std::string key)
{
    qDebug() << "Do a special " << QString::fromStdString(key);
}
