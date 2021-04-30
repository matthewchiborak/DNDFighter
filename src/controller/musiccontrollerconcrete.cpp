#include "musiccontrollerconcrete.h"

#include <QDebug>

MusicControllerConcrete::MusicControllerConcrete(std::string musicFilepath, std::string sfxFilePath)
    : MusicControllerAbstract(musicFilepath, sfxFilePath)
{

}

void MusicControllerConcrete::playMusic(std::string key)
{
    if(key == lastBGMusicKey)
        return;

    backgroundMusic.setMedia(QUrl(QString::fromStdString("file:///" + musicFilepath+"\\"+keyToFileMap[key])));
    if(backgroundMusic.state() == QMediaPlayer::PlayingState)
    {
        backgroundMusic.setPosition(0);
    }
    else if(backgroundMusic.state() == QMediaPlayer::StoppedState)
        backgroundMusic.play();
}

void MusicControllerConcrete::playSoundEffect(std::string key)
{
    if(key == "Hit")
    {
        if(hitSE1.state() == QMediaPlayer::PlayingState)
            hitSE2.play();
        else
            hitSE1.play();
    }
    else if(key == "Attack")
    {
        if(attackSE1.state() == QMediaPlayer::PlayingState)
            attackSE2.play();
        else
            attackSE1.play();
    }
    else if(key == "Block")
    {
        if(blockSE1.state() == QMediaPlayer::PlayingState)
            blockSE2.play();
        else
            blockSE1.play();
    }
    else if(key == "MenuCancel")
    {
        menuCancelSE.play();
    }
    else if(key == "MenuMove")
    {
        menuMoveSE.play();
    }
    else if(key == "MenuEnter")
    {
        menuEnterSE.play();
    }
    else
    {
        miscSE.setMedia(QUrl(QString::fromStdString("file:///" + sfxFilePath+"\\"+key)));
        if(miscSE.state() == QMediaPlayer::PlayingState)
        {
            miscSE.setPosition(0);
        }
        else if(miscSE.state() == QMediaPlayer::StoppedState)
            miscSE.play();
    }
}

void MusicControllerConcrete::manualLoad(std::string typeKey, std::string soundKey)
{
    if(typeKey == "Hit")
    {
        hitSE1.setMedia(QUrl(QString::fromStdString("file:///" + sfxFilePath+"\\"+soundKey)));
        hitSE2.setMedia(QUrl(QString::fromStdString("file:///" + sfxFilePath+"\\"+soundKey)));
    }
    else if(typeKey == "Attack")
    {
        attackSE1.setMedia(QUrl(QString::fromStdString("file:///" + sfxFilePath+"\\"+soundKey)));
        attackSE2.setMedia(QUrl(QString::fromStdString("file:///" + sfxFilePath+"\\"+soundKey)));
    }
    else if(typeKey == "Block")
    {
        blockSE1.setMedia(QUrl(QString::fromStdString("file:///" + sfxFilePath+"\\"+soundKey)));
        blockSE2.setMedia(QUrl(QString::fromStdString("file:///" + sfxFilePath+"\\"+soundKey)));
    }
    else if(typeKey == "MenuCancel")
    {
        menuCancelSE.setMedia(QUrl(QString::fromStdString("file:///" + sfxFilePath+"\\"+soundKey)));
    }
    else if(typeKey == "MenuMove")
    {
        menuMoveSE.setMedia(QUrl(QString::fromStdString("file:///" + sfxFilePath+"\\"+soundKey)));
    }
    else if(typeKey == "MenuEnter")
    {
        menuEnterSE.setMedia(QUrl(QString::fromStdString("file:///" + sfxFilePath+"\\"+soundKey)));
    }
    else
    {
        keyToFileMap[typeKey] = soundKey;
    }
}

void MusicControllerConcrete::loopMusic(int resetPos, int loopPoint)
{
    if(backgroundMusic.state() == QMediaPlayer::PlayingState)
    {
        if(backgroundMusic.position() >= loopPoint)
            backgroundMusic.setPosition(resetPos);
    }
    if(backgroundMusic.state() == QMediaPlayer::StoppedState)
    {
        backgroundMusic.setPosition(resetPos);
        backgroundMusic.play();
    }
}
