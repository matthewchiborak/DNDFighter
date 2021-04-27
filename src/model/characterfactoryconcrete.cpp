#include "characterfactoryconcrete.h"

#include "battlecharacterplayercontrol.h"

#include "attackmodelstandard.h"
#include "attackmodelthrow.h"
#include "attackmodelspecial.h"

#include "../filemanagment/fileReader.h"

#include <QDebug>

CharacterFactoryConcrete::CharacterFactoryConcrete(std::string characterInfoFilepath)
    : CharacterFactory(characterInfoFilepath)
{

}

BattleCharacter *CharacterFactoryConcrete::makeCharacter(std::string key)
{
    FileReader fr(characterInfoFilepath + "\\" + key + ".txt");

    BattleCharacter * newChar = new BattleCharacterPlayerControl(key);

    /*
    (BattleCharacter * user,
int recovery,
int hitStun,
float posX,
float posY,
float w,
float h,
std::string hitboxSprite,
int heightForBlocking,
float velocityX,
float velocityY,
int duration,
int damage,
bool isFixedToCharacter);
*/

    while(fr.hasNext())
    {
        std::vector<std::string> lineParts = fr.splitString(fr.next(), ',');

        if(lineParts.at(0) == "Health")
        {
            newChar->setMaxHealth(std::stoi(lineParts.at(1)));
            newChar->refillHealth();
        }
        else if(lineParts.at(0) == "Walk")
           newChar->setWalkSpeed(std::stof(lineParts.at(1)));
        else if(lineParts.at(0) == "HurtBox")
            newChar->setHurtBox(std::stof(lineParts.at(1)), std::stof(lineParts.at(2)), std::stof(lineParts.at(3)), std::stof(lineParts.at(4)));
        else if(lineParts.at(0) == "HurtBoxCrouch")
            newChar->setHurtBoxCrouch(std::stof(lineParts.at(1)), std::stof(lineParts.at(2)), std::stof(lineParts.at(3)), std::stof(lineParts.at(4)));
        else if(lineParts.at(0) == "Punch")
            newChar->setPunchModel(new AttackModelStandard(newChar,
                                                           std::stoi(lineParts.at(1)),
                                                           std::stoi(lineParts.at(2)),
                                                           std::stof(lineParts.at(3)),
                                                           std::stof(lineParts.at(4)),
                                                           std::stof(lineParts.at(5)),
                                                           std::stof(lineParts.at(6)),
                                                           lineParts.at(7)
                                                           ,std::stoi(lineParts.at(8))
                                                           ,std::stof(lineParts.at(9))
                                                           ,std::stof(lineParts.at(10))
                                                           ,std::stoi(lineParts.at(11))
                                                           ,std::stoi(lineParts.at(12))
                                                           ,std::stoi(lineParts.at(13))
                                                           ));
        else if(lineParts.at(0) == "Kick")
            newChar->setKickModel(new AttackModelStandard(newChar,
                                                          std::stoi(lineParts.at(1)),
                                                          std::stoi(lineParts.at(2)),
                                                          std::stof(lineParts.at(3)),
                                                          std::stof(lineParts.at(4)),
                                                          std::stof(lineParts.at(5)),
                                                          std::stof(lineParts.at(6)),
                                                          lineParts.at(7)
                                                          ,std::stoi(lineParts.at(8))
                                                          ,std::stof(lineParts.at(9))
                                                          ,std::stof(lineParts.at(10))
                                                          ,std::stoi(lineParts.at(11))
                                                          ,std::stoi(lineParts.at(12))
                                                          ,std::stoi(lineParts.at(13))
                                                           ));
        else if(lineParts.at(0) == "CrouchPunch")
            newChar->setCrouchPunchModel(new AttackModelStandard(newChar,
                                                                 std::stoi(lineParts.at(1)),
                                                                 std::stoi(lineParts.at(2)),
                                                                 std::stof(lineParts.at(3)),
                                                                 std::stof(lineParts.at(4)),
                                                                 std::stof(lineParts.at(5)),
                                                                 std::stof(lineParts.at(6)),
                                                                 lineParts.at(7)
                                                                 ,std::stoi(lineParts.at(8))
                                                                 ,std::stof(lineParts.at(9))
                                                                 ,std::stof(lineParts.at(10))
                                                                 ,std::stoi(lineParts.at(11))
                                                                 ,std::stoi(lineParts.at(12))
                                                                 ,std::stoi(lineParts.at(13))
                                                           ));
        else if(lineParts.at(0) == "CrouchKick")
            newChar->setCrouchKickModel(new AttackModelStandard(newChar,
                                                                std::stoi(lineParts.at(1)),
                                                                std::stoi(lineParts.at(2)),
                                                                std::stof(lineParts.at(3)),
                                                                std::stof(lineParts.at(4)),
                                                                std::stof(lineParts.at(5)),
                                                                std::stof(lineParts.at(6)),
                                                                lineParts.at(7)
                                                                ,std::stoi(lineParts.at(8))
                                                                ,std::stof(lineParts.at(9))
                                                                ,std::stof(lineParts.at(10))
                                                                ,std::stoi(lineParts.at(11))
                                                                ,std::stoi(lineParts.at(12))
                                                                ,std::stoi(lineParts.at(13))
                                                           ));
        else if(lineParts.at(0) == "Throw")
            newChar->setThrowModel(new AttackModelThrow(newChar,
                                                        std::stoi(lineParts.at(1)),
                                                        std::stoi(lineParts.at(2)),
                                                        std::stof(lineParts.at(3)),
                                                        std::stof(lineParts.at(4)),
                                                        std::stof(lineParts.at(5)),
                                                        std::stof(lineParts.at(6)),
                                                        lineParts.at(7)
                                                        ,std::stoi(lineParts.at(8))
                                                        ,std::stof(lineParts.at(9))
                                                        ,std::stof(lineParts.at(10))
                                                        ,std::stoi(lineParts.at(11))
                                                        ,std::stoi(lineParts.at(12))
                                                        ,std::stoi(lineParts.at(13))
                                                           ));
        else if(lineParts.at(0) == "NeutralSpecial")
            newChar->setNeutralSpecialModel(new AttackModelSpecial(newChar,
                                                                   std::stoi(lineParts.at(1)),
                                                                   std::stoi(lineParts.at(2)),
                                                                   std::stof(lineParts.at(3)),
                                                                   std::stof(lineParts.at(4)),
                                                                   std::stof(lineParts.at(5)),
                                                                   std::stof(lineParts.at(6)),
                                                                   lineParts.at(7)
                                                                   ,std::stoi(lineParts.at(8))
                                                                   ,std::stof(lineParts.at(9))
                                                                   ,std::stof(lineParts.at(10))
                                                                   ,std::stoi(lineParts.at(11))
                                                                   ,std::stoi(lineParts.at(12))
                                                                   ,std::stoi(lineParts.at(13))
                                                           ));
        else if(lineParts.at(0) == "ForwardSpecial")
            newChar->setForwardSpecialModel(new AttackModelSpecial(newChar,
                                                                   std::stoi(lineParts.at(1)),
                                                                   std::stoi(lineParts.at(2)),
                                                                   std::stof(lineParts.at(3)),
                                                                   std::stof(lineParts.at(4)),
                                                                   std::stof(lineParts.at(5)),
                                                                   std::stof(lineParts.at(6)),
                                                                   lineParts.at(7)
                                                                   ,std::stoi(lineParts.at(8))
                                                                   ,std::stof(lineParts.at(9))
                                                                   ,std::stof(lineParts.at(10))
                                                                   ,std::stoi(lineParts.at(11))
                                                                   ,std::stoi(lineParts.at(12))
                                                                   ,std::stoi(lineParts.at(13))
                                                           ));
        else if(lineParts.at(0) == "DownSpecial")
            newChar->setDownSpecialModel(new AttackModelSpecial(newChar,
                                                                std::stoi(lineParts.at(1)),
                                                                std::stoi(lineParts.at(2)),
                                                                std::stof(lineParts.at(3)),
                                                                std::stof(lineParts.at(4)),
                                                                std::stof(lineParts.at(5)),
                                                                std::stof(lineParts.at(6)),
                                                                lineParts.at(7)
                                                                ,std::stoi(lineParts.at(8))
                                                                ,std::stof(lineParts.at(9))
                                                                ,std::stof(lineParts.at(10))
                                                                ,std::stoi(lineParts.at(11))
                                                                ,std::stoi(lineParts.at(12))
                                                                ,std::stoi(lineParts.at(13))
                                                           ));
    }

    return newChar;
}
