#include "SpaceShipEarth.h"

Serial pc(USBTX, USBRX); //not used in this program
MMA8452 acc(p9, p10, 40000);   //instantiate an acc object!


int spaceship_earth1[EARTH_WIDTH * EARTH_HEIGHT] = {
_,_,S,S,S,S,S,S,_,_, 
_,S,I,I,I,I,I,I,S,_, 
S,I,I,I,I,I,I,I,I,S, 
S,I,I,I,I,I,I,I,I,S, 
S,I,I,I,I,I,I,I,I,S, 
S,I,I,I,I,I,I,I,I,S, 
S,I,I,I,I,I,I,I,I,S, 
S,I,I,I,I,I,I,I,I,S, 
S,I,I,I,I,I,I,I,S,_, 
_,S,S,S,S,S,S,S,_,_,
};

int spaceship_earth1_cover[EARTH_WIDTH * EARTH_HEIGHT] = {
_,_,_,_,_,_,_,_,_,_, 
_,_,_,_,_,_,_,_,_,_, 
_,_,_,_,_,_,_,_,_,_, 
_,_,_,_,_,_,_,_,_,_, 
_,_,_,_,_,_,_,_,_,_, 
_,_,_,_,_,_,_,_,_,_, 
_,_,_,_,_,_,_,_,_,_, 
_,_,_,_,_,_,_,_,_,_, 
_,_,_,_,_,_,_,_,_,_, 
_,_,_,_,_,_,_,_,_,_,
};

int spaceship_earth_explosion[EARTH_WIDTH * EARTH_HEIGHT] = {
_,_,S,S,S,S,S,S,_,_, 
_,S,R,R,R,R,R,R,S,_, 
S,R,R,R,R,R,R,R,R,S, 
S,R,R,R,R,R,R,R,R,S, 
S,R,R,R,R,R,R,R,R,S, 
S,R,R,R,R,R,R,R,R,S, 
S,R,R,R,R,R,R,R,R,S, 
S,R,R,R,R,R,R,R,R,S, 
S,R,R,R,R,R,R,R,S,_, 
_,S,S,S,S,S,S,S,_,_,
};

double x = 0;
double y = 0;
double z = 0;
const int offsetx = 63;
const int offsety = 63;
const double factor = 50;

SpaceShipEarth::SpaceShipEarth(uLCD_4DGL *uLCD):ScreenObject(uLCD){

      //set parameters -- use these and don't change
      acc.setBitDepth(MMA8452::BIT_DEPTH_12);
      acc.setDynamicRange(MMA8452::DYNAMIC_RANGE_4G);
      acc.setDataRate(MMA8452::RATE_100);
      this->xPos = (0);
      this->yPos = (0);
}


void SpaceShipEarth::draw()
{
    


    this->xPos = -1 * (y) * factor + offsety;
    this->yPos = 1 * (x) * factor + offsetx;

    (*uLCD).BLIT(this->xPos, this->yPos, EARTH_WIDTH, EARTH_HEIGHT, spaceship_earth1);
    

}

void SpaceShipEarth::update()
{


    if (!acc.isXYZReady())
    {

    }
    else
    {

        (*uLCD).BLIT(this->xPos, this->yPos, EARTH_WIDTH, EARTH_HEIGHT, spaceship_earth1_cover);


        acc.readXYZGravity(&x, &y, &z); //notice this is passed by reference use pointers
    }

}


void SpaceShipEarth::explode(){


        (*uLCD).BLIT(this->xPos, this->yPos, EARTH_WIDTH, EARTH_HEIGHT, spaceship_earth_explosion);


}
