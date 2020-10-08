#include "ConcreteAsteroid.h"


int asteroid_sprite_1[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
    _,_,_,_,X,X,X,X,X,X,X,X,_,_,_, 
    _,_,_,X,_,_,_,_,_,_,_,_,X,_,_, 
    _,_,X,_,_,_,_,_,_,_,_,_,X,_,_, 
    _,X,_,_,_,_,_,_,_,_,_,_,X,_,_, 
    X,X,X,X,_,_,_,_,_,_,_,_,_,X,_, 
    _,_,_,X,_,_,_,_,_,_,_,_,_,X,_, 
    _,_,X,_,_,_,_,_,_,_,_,_,_,X,_, 
    _,X,_,_,_,_,_,X,_,_,_,_,_,X,_, 
    X,_,_,_,_,_,X,X,_,_,_,_,X,_,_, 
    _,X,_,_,_,X,_,X,_,_,_,_,X,_,_, 
    _,_,X,_,X,_,_,X,_,_,_,X,_,_,_, 
    _,_,_,X,_,_,_,X,X,X,X,_,_,_,_
};


int asteroid_sprite_1_cover[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_
};

int asteroid_sprite_explode[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
   _,_,_,_,R,R,R,R,R,R,R,R,_,_,_, 
    _,_,_,R,_,_,_,_,_,_,_,_,R,_,_, 
    _,_,R,_,_,_,_,_,_,_,_,_,R,_,_, 
    _,R,_,_,_,_,_,_,_,_,_,_,R,_,_, 
    R,R,R,R,_,_,_,_,_,_,_,_,_,R,_, 
    _,_,_,R,_,_,_,_,_,_,_,_,_,R,_, 
    _,_,R,_,_,_,_,_,_,_,_,_,_,R,_, 
    _,R,_,_,_,_,_,R,_,_,_,_,_,R,_, 
    R,_,_,_,_,_,R,R,_,_,_,_,R,_,_, 
    _,R,_,_,_,R,_,R,_,_,_,_,R,_,_, 
    _,_,R,_,R,_,_,R,_,_,_,R,_,_,_, 
    _,_,_,R,_,_,_,R,R,R,R,_,_,_,_
};




ConcreteAsteroid::ConcreteAsteroid(uLCD_4DGL * uLCD, SideOfScreen sideOfScreen):AbstractAsteroid(uLCD,sideOfScreen){




}



void ConcreteAsteroid::draw()
{
    (*uLCD).BLIT(this->xPos,this->yPos, ASTEROID_WIDTH, ASTEROID_HEIGHT, asteroid_sprite_1);
}

void ConcreteAsteroid::update()
{
    (*uLCD).BLIT(this->xPos,this->yPos, ASTEROID_WIDTH, ASTEROID_HEIGHT, asteroid_sprite_1_cover);
    this->moveAsteroid();


}

void ConcreteAsteroid::explode(){
    (*uLCD).BLIT(this->xPos,this->yPos, ASTEROID_WIDTH, ASTEROID_HEIGHT, asteroid_sprite_explode);
    wait(0.5);
    this->update();
    this->resetAsteroid();
}

