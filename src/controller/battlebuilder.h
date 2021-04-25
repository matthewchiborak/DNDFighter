#ifndef BATTLEBUILDER_H
#define BATTLEBUILDER_H

#include "userinputhandler.h"
#include <string>

#include "../model/characterfactory.h"

class BattleBuilder
{
public:
    BattleBuilder(GameModel * gameModel, CharacterFactory * characterFactory);

    void start();
    virtual void makePlayer1(std::string character, std::string type);
    virtual void makePlayer2(std::string character, std::string type);
    virtual void makeStage(std::string stageKey);
    UserInputHandler * getCreatedUserInputHandler();

protected:
    GameModel * gameModel;
    CharacterFactory * characterFactory;

    UserInputHandler * resultInputHandler;
};

#endif // BATTLEBUILDER_H
