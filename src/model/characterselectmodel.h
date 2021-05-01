#ifndef CHARACTERSELECTMODEL_H
#define CHARACTERSELECTMODEL_H

#include <string>
#include <vector>
#include "../controller/musiccontrollerabstract.h"

class CharacterSelectModel
{
public:
    CharacterSelectModel(std::string characterListFile, MusicControllerAbstract * musicController);

    std::vector<std::string> * getCharacters();
    std::vector<float> * getCharacterWidths();
    std::vector<float> * getCharacterHeights();

    void moveCursor(int x, int y);
    void enter(std::string type);
    void cancel();

    int getCursorPos();

    int getnumberCharacterSelected();
    int getselectedOneIndex();
    int getselectedTwoIndex();
    bool getP1IsACPU();
    bool getP2IsACPU();

    bool getReadyToStartFight();

    void reset();

protected:
    std::string characterListFile;
    std::vector<std::string> characters;
    std::vector<float> characterWidths;
    std::vector<float> characterHeights;
    int numberOfCharacters;

    int cursorPosX = 0;
    int cursorPosY = 0;

    int numberCharacterSelected = 0;
    int selectedOneIndex;
    bool p1IsACPU;
    int selectedTwoIndex;
    bool p2IsACPU;

    bool readyToStartFight;

    MusicControllerAbstract * musicController;
};

#endif // CHARACTERSELECTMODEL_H
