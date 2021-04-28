#include "characterselectmodel.h"

#include "../filemanagment/fileReader.h"

CharacterSelectModel::CharacterSelectModel(std::string characterListFile)
{
    this->characterListFile = characterListFile;
    numberOfCharacters = 0;
    readyToStartFight = false;

    FileReader fr(characterListFile);
    while(fr.hasNext())
    {
        characters.push_back(fr.next());
        numberOfCharacters++;
    }
}

std::vector<std::string> *CharacterSelectModel::getCharacters()
{
    return &characters;
}

void CharacterSelectModel::moveCursor(int x, int y)
{
    cursorPosX += x;
    cursorPosY += y;

    if(cursorPosY > 1)
        cursorPosY = 0;
    if(cursorPosY < 0)
        cursorPosY = 1;

    if(cursorPosX > (numberOfCharacters-1)/2)
        cursorPosX = 0;
    if(cursorPosX < 0)
        cursorPosX = (numberOfCharacters-1)/2;
}

void CharacterSelectModel::enter()
{
    if(numberCharacterSelected == 0)
    {
        numberCharacterSelected++;
        selectedOneIndex = getCursorPos();
    }
    else if(numberCharacterSelected == 1)
    {
        numberCharacterSelected++;
        selectedTwoIndex = getCursorPos();
    }
    else if(numberCharacterSelected == 2)
    {
        //Start the fight
        readyToStartFight = true;
    }
}

int CharacterSelectModel::getCursorPos()
{
    return (cursorPosX*2) + (cursorPosY);
}

int CharacterSelectModel::getnumberCharacterSelected()
{
    return numberCharacterSelected;
}

int CharacterSelectModel::getselectedOneIndex()
{
    return selectedOneIndex;
}

int CharacterSelectModel::getselectedTwoIndex()
{
    return selectedTwoIndex;
}

bool CharacterSelectModel::getReadyToStartFight()
{
    return readyToStartFight;
}
