#include "musiccontrollerabstract.h"

MusicControllerAbstract::MusicControllerAbstract(std::string musicFilepath, std::string sfxFilePath)
{
    this->musicFilepath = musicFilepath;
    this->sfxFilePath = sfxFilePath;
}

void MusicControllerAbstract::playMusic(std::string key)
{

}

void MusicControllerAbstract::playSoundEffect(std::string key)
{

}

void MusicControllerAbstract::manualLoad(std::string typeKey, std::string soundKey)
{

}

void MusicControllerAbstract::loopMusic(int resetPos, int loopPoint)
{

}
