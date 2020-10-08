#ifndef SOUNDMANAGER_H 
#define SOUNDMANAGER_H
#include "mbed.h"
#include "Speaker.h"

/**
 * @brief Sound Manager
 * @author Afshawn Lotfi
 * @version 1.0.0
 */
class SoundManager
{

  public:


    SoundManager();
    void playMusic();
    void stopMusic();
    void playWin();
    void playLose();
    void playExplosion();


};


#endif



