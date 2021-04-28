#ifndef CHARACTERSELECTMODEL_H
#define CHARACTERSELECTMODEL_H

#include <string>
#include <vector>

class CharacterSelectModel
{
public:
    CharacterSelectModel(std::string characterListFile);

    std::vector<std::string> * getCharacters();

    void moveCursor(int x, int y);
    void enter();

    int getCursorPos();

    int getnumberCharacterSelected();
    int getselectedOneIndex();
    int getselectedTwoIndex();

    bool getReadyToStartFight();

protected:
    std::string characterListFile;
    std::vector<std::string> characters;
    int numberOfCharacters;

    int cursorPosX = 0;
    int cursorPosY = 0;

    int numberCharacterSelected = 0;
    int selectedOneIndex;
    int selectedTwoIndex;

    bool readyToStartFight;
};

#endif // CHARACTERSELECTMODEL_H
