#include "SoundManager.h"

Speaker speaker(p21);



SoundManager::SoundManager(){
}

void SoundManager::playMusic(){

        speaker.PlayNote(293.66, 0.5, 0.1);
        speaker.PlayNote(392.0, 0.5, 0.1);
        speaker.PlayNote(196.0, 0.5, 0.1);

}


void SoundManager::playWin(){

    speaker.PlayNote(293.66, 0.25, 0.2);
    speaker.PlayNote(369.99, 0.25, 0.2);
    speaker.PlayNote(440.0, 0.25, 0.2);
    speaker.PlayNote(523.25, 0.25, 0.2);
    speaker.PlayNote(493.88, 0.25, 0.2);
    speaker.PlayNote(440.0, 0.25, 0.2);
    speaker.PlayNote(392.0, 1, 0.2);

    
}

void SoundManager::playLose(){

    speaker.PlayNote(392.0, 0.5, 0.2);
    speaker.PlayNote(293.66, 0.5, 0.2);
    speaker.PlayNote(196.0, 0.5, 0.2);

}

void SoundManager::playExplosion(){
    speaker.PlayNote(97.99, 0.5, 0.2);

}

