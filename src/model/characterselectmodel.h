#ifndef CHARACTERSELECTMODEL_H
#define CHARACTERSELECTMODEL_H

#include <string>
#include <vector>

class CharacterSelectModel
{
public:
    CharacterSelectModel(std::string characterListFile);

    std::vector<std::string> * getCharacters();
    std::vector<float> * getCharacterWidths();
    std::vector<float> * getCharacterHeights();

    void moveCursor(int x, int y);
    void enter();
    void cancel();

    int getCursorPos();

    int getnumberCharacterSelected();
    int getselectedOneIndex();
    int getselectedTwoIndex();

    bool getReadyToStartFight();

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
    int selectedTwoIndex;

    bool readyToStartFight;
};

#endif // CHARACTERSELECTMODEL_H
