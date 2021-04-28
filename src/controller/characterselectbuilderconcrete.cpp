#include "characterselectbuilderconcrete.h"

#include "buttoncommandmenumove.h"
#include "buttoncommandmenuenter.h"

CharacterSelectBuilderConcrete::CharacterSelectBuilderConcrete(GameModel *gameModel)
    : CharacterSelectBuilder(gameModel)
{

}

UserInputHandler *CharacterSelectBuilderConcrete::getCreatedUserInputHandler()
{
    UserInputHandler * resultInputHandler = new UserInputHandler(gameModel);

    resultInputHandler->addCommand(new ButtonCommandMenuMove(gameModel, 'W', 'S', 'A', 'D'));
    resultInputHandler->addCommand(new ButtonCommandMenuEnter(gameModel, 'E'));

    return resultInputHandler;
}
