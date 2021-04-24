#ifndef BATTLEBUILDER_H
#define BATTLEBUILDER_H

//#include "userinputcommandfactory.h"
#include "userinputhandler.h"
#include <string>

class BattleBuilder
{
public:
    BattleBuilder(GameModel * gameModel);//, UserInputCommandFactory * userInputCommandFactory);

    void start();
    virtual void makePlayer1(std::string character, std::string type);
    virtual void makePlayer2(std::string character, std::string type);
    virtual void makeStage(std::string stageKey);
    UserInputHandler * getCreatedUserInputHandler();

protected:
    //UserInputCommandFactory * userInputCommandFactory;
    GameModel * gameModel;

    UserInputHandler * resultInputHandler;
};

#endif // BATTLEBUILDER_H
