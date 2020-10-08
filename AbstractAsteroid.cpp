#include "AbstractAsteroid.h"
#include <string> 
#include "TMP36.h"


TMP36 tempSensor(p15);


AbstractAsteroid::AbstractAsteroid(uLCD_4DGL *uLCD, SideOfScreen sideOfScreen):ScreenObject(uLCD),sideOfScreen(sideOfScreen){
    this->resetAsteroid();
}

SideOfScreen AbstractAsteroid::getSideScreen(){
    return this->sideOfScreen;
}

void AbstractAsteroid::resetAsteroid(){
    this->deltaX = this->generateNum(1,10);
    this->deltaY = this->generateNum(1,10);

    switch(this->sideOfScreen){
        case TOPLEFT:
            this->xPos = this->generateNum(0,0.5*SCREEN_MAX);
            this->yPos = 0;
            break;
        case TOPRIGHT:
            this->xPos = this->generateNum(SCREEN_MAX*0.5,SCREEN_MAX);
            this->yPos = 0;
            this->deltaX = this->deltaX*-1;
            break;
        case BOTTOMLEFT:
            this->xPos = this->generateNum(0,0.5*SCREEN_MAX);
            this->yPos = SCREEN_MAX;
            this->deltaY = this->deltaY*-1;
            break;
        case BOTTOMRIGHT:
            this->xPos = this->generateNum(SCREEN_MAX*0.5,SCREEN_MAX);
            this->yPos = SCREEN_MAX;
            this->deltaX = this->deltaX*-1;
            this->deltaY = this->deltaY*-1;

            break;

    }

}

void AbstractAsteroid::moveAsteroid(){

    this->xPos = xPos + this->deltaX;
    this->yPos = yPos + this->deltaY;

    if (this->xPos < SCREEN_MIN || this->xPos > SCREEN_MAX || this->yPos < SCREEN_MIN || this->yPos > SCREEN_MAX){
        this->resetAsteroid();
    }




}

double AbstractAsteroid::generateNum(double min, double max){
    double firstReading = tempSensor.read();
    double secondReading = tempSensor.read();
    double thermalRandNum = (firstReading - secondReading) * 1000;
    double randNum = (static_cast<int>(rand() + thermalRandNum) % static_cast<int>(max) + static_cast<int>(min));
    randNum = randNum + (secondReading/firstReading);

    if (randNum > max){
        return max;
    }

    return randNum;
}



double AbstractAsteroid::getDeltaX(){
    return this->deltaX;
}

double AbstractAsteroid::getDeltaY(){
    return this->deltaY;
}

void AbstractAsteroid::setDeltaX(double xPos){
    this->deltaX = xPos;
}

void AbstractAsteroid::setDeltaY(double yPos){
    this->deltaY = yPos;
}