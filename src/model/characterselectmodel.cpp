#include "characterselectmodel.h"

#include "../filemanagment/fileReader.h"

CharacterSelectModel::CharacterSelectModel(std::string characterListFile, MusicControllerAbstract * musicController)
{
    this->characterListFile = characterListFile;
    numberOfCharacters = 0;
    readyToStartFight = false;
    this->musicController = musicController;

    FileReader fr(characterListFile);
    while(fr.hasNext())
    {
        std::vector<std::string> splitUp = fr.splitString(fr.next(), ',');

        characters.push_back(splitUp.at(0));
        characterWidths.push_back(std::stof(splitUp.at(1)));
        characterHeights.push_back(std::stof(splitUp.at(2)));
        numberOfCharacters++;
    }
}

std::vector<std::string> *CharacterSelectModel::getCharacters()
{
    return &characters;
}

std::vector<float> *CharacterSelectModel::getCharacterWidths()
{
    return &characterWidths;
}

std::vector<float> *CharacterSelectModel::getCharacterHeights()
{
    return &characterHeights;
}

void CharacterSelectModel::moveCursor(int x, int y)
{
    musicController->playSoundEffect("MenuMove");

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

void CharacterSelectModel::enter(std::string type)
{
    musicController->playSoundEffect("MenuEnter");

    if(numberCharacterSelected == 0)
    {
        numberCharacterSelected++;
        selectedOneIndex = getCursorPos();
        p1IsACPU = (type == "CPU");
    }
    else if(numberCharacterSelected == 1)
    {
        numberCharacterSelected++;
        selectedTwoIndex = getCursorPos();
        p2IsACPU = (type == "CPU");
    }
    else if(numberCharacterSelected == 2)
    {
        //Start the fight
        readyToStartFight = true;
    }
}

void CharacterSelectModel::cancel()
{
    if(numberCharacterSelected > 0)
    {
        musicController->playSoundEffect("MenuCancel");
        numberCharacterSelected--;
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

bool CharacterSelectModel::getP1IsACPU()
{
    return p1IsACPU;
}

bool CharacterSelectModel::getP2IsACPU()
{
    return p2IsACPU;
}

bool CharacterSelectModel::getReadyToStartFight()
{
    return readyToStartFight;
}

void CharacterSelectModel::reset()
{
    readyToStartFight = false;
    numberCharacterSelected = 0;
    cursorPosX = 0;
    cursorPosY = 0;
}

