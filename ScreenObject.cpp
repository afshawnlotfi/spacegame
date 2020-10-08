#include "ScreenObject.h"



ScreenObject::ScreenObject(uLCD_4DGL * uLCD):uLCD(uLCD){
  this->xPos = SCREEN_MIN;
  this->yPos = SCREEN_MIN;
};

double ScreenObject::getXPos(){
    return this->xPos;
}

double ScreenObject::getYPos(){
    return this->yPos;
}



bool overlap(ScreenObject & objectA, ScreenObject & objectB){

    double xMin = objectA.getXPos();
    double xMax = objectA.getXPos() + 10;
    double yMin = objectA.getYPos();
    double yMax = objectA.getYPos() + 10;

    if ((objectB.getXPos() >= xMin && objectB.getXPos() <= xMax) && (objectB.getYPos() >= yMin && objectB.getYPos() <= yMax)){
        return true;
    }else{
        return false;
    }


}





