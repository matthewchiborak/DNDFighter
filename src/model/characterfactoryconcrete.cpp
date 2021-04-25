#include "characterfactoryconcrete.h"

#include "battlecharacterplayercontrol.h"

#include "attackmodelstandard.h"

CharacterFactoryConcrete::CharacterFactoryConcrete(std::string characterInfoFilepath)
    : CharacterFactory(characterInfoFilepath)
{

}

BattleCharacter *CharacterFactoryConcrete::makeCharacter(std::string key)
{
    BattleCharacter * newChar = new BattleCharacterPlayerControl(key, 1.f/30.f, 100);

    newChar->setPunchModel(new AttackModelStandard(newChar, 10));
    newChar->setKickModel(new AttackModelStandard(newChar, 15));
    newChar->setCrouchPunchModel(new AttackModelStandard(newChar, 20));
    newChar->setCrouchKickModel(new AttackModelStandard(newChar, 30));
    newChar->setThrowModel(new AttackModelStandard(newChar, 40));
    newChar->setNeutralSpecialModel(new AttackModelStandard(newChar, 50));
    newChar->setForwardSpecialModel(new AttackModelStandard(newChar, 60));
    newChar->setDownSpecialModel(new AttackModelStandard(newChar, 70));

    return newChar;
}
