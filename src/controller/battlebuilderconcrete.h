#ifndef BATTLEBUILDERCONCRETE_H
#define BATTLEBUILDERCONCRETE_H

#include "battlebuilder.h"

class BattleBuilderConcrete : public BattleBuilder
{
public:
    BattleBuilderConcrete(GameModel * gameModel, CharacterFactory * characterFactory);

    void makePlayer1(std::string character, std::string type);
    void makePlayer2(std::string character, std::string type);
    void makeStage(std::string stageKey);

};

#endif // BATTLEBUILDERCONCRETE_H
