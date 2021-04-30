#ifndef MUSICCONTROLLERCONCRETE_H
#define MUSICCONTROLLERCONCRETE_H

#include "musiccontrollerabstract.h"
#include <QMediaPlayer>
#include <map>

class MusicControllerConcrete : public MusicControllerAbstract
{
public:
    MusicControllerConcrete(std::string musicFilepath, std::string sfxFilePath);

    void playMusic(std::string key);
    void playSoundEffect(std::string key);
    void manualLoad(std::string typeKey, std::string soundKey);
    void loopMusic(int resetPos, int loopPoint);

private:
    std::string lastBGMusicKey = "None";
    QMediaPlayer backgroundMusic;
    std::map<std::string, std::string> keyToFileMap;

    QMediaPlayer hitSE1;
    QMediaPlayer attackSE1;
    QMediaPlayer blockSE1;
    QMediaPlayer hitSE2;
    QMediaPlayer attackSE2;
    QMediaPlayer blockSE2;

    QMediaPlayer menuMoveSE;
    QMediaPlayer menuEnterSE;
    QMediaPlayer menuCancelSE;

    QMediaPlayer miscSE;
};

#endif // MUSICCONTROLLERCONCRETE_H
