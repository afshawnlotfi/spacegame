#include "TimeBar.h"

Timer t;


TimeBar::TimeBar(uLCD_4DGL *uLCD):ScreenObject(uLCD){

    t.start();
    this->barLength = 127;
}


bool TimeBar::isTimeUp(){
    if(t.read() >= 30){
        t.stop();
        return true;
    }else{
        return false;
    }

}

void TimeBar::draw()
{

    this->barLength = 127 - (t.read() / 30.0)*127;
    (*uLCD).line(0, 127, this->barLength, 127, WHITE);

}

void TimeBar::update()
{

    (*uLCD).line(0, 127, this->barLength, 127, BLACK);


}

