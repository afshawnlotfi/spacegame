#include "mbed.h"
#include "SpaceShipEarth.h"
#include "ConcreteAsteroid.h"
#include "TimeBar.h"
#include "PinDetect.h"
#include "SoundManager.h"
PinDetect pb1(p16);


bool bombsUsed = false;
bool explodeAllAsteroids = false;
void pb1_hit_callback (void){

    if (bombsUsed == false){

        bombsUsed = true;
        explodeAllAsteroids = true;

    }
}



int main() {
   uLCD_4DGL uLCD(p28, p27, p29); // create a global uLCD object
   (uLCD).text_string("Survive 30 Secs!" , 1, 4, FONT_7X8, WHITE);
   wait(2);
   uLCD.background_color(BLACK);
   uLCD.cls();
   uLCD.baudrate(300000); 
   wait(0.2);
   srand(time(0));
   ConcreteAsteroid * ActiveAsteroids[NUM_ASTEROIDS];
   SpaceShipEarth ship(&uLCD);
   ConcreteAsteroid concreteAsteroid_one(&uLCD, TOPLEFT);
   ConcreteAsteroid concreteAsteroid_two(&uLCD, TOPRIGHT);
   ConcreteAsteroid concreteAsteroid_three(&uLCD, BOTTOMLEFT);
   ConcreteAsteroid concreteAsteroid_four(&uLCD, BOTTOMRIGHT);

   TimeBar timeBar(&uLCD);

   SoundManager soundManager;

   ActiveAsteroids[0] =  &concreteAsteroid_one;
   ActiveAsteroids[1] =  &concreteAsteroid_two;
   ActiveAsteroids[2] =  &concreteAsteroid_three;
   ActiveAsteroids[3] =  &concreteAsteroid_four;
   

   bool startLooping = true;
   pb1.mode(PullUp);
   wait(.01);

   pb1.attach_deasserted(&pb1_hit_callback);

   pb1.setSampleFrequency();

   while(startLooping) {

      double increment = 0.01;
      wait(increment);

      timeBar.update();
      timeBar.draw();
      ship.update();
      ship.draw();
      for (int i = 0; i < NUM_ASTEROIDS; i++){

         (*ActiveAsteroids[i]).update();

         (*ActiveAsteroids[i]).draw();

         if (explodeAllAsteroids == true){
            soundManager.playExplosion();
            (*ActiveAsteroids[i]).explode();
         }else{
            if (overlap(ship,*ActiveAsteroids[i])){
               soundManager.playExplosion();
               ship.explode();
               (uLCD).text_string("You Crashed!" , 4, 4, FONT_7X8, WHITE);

               soundManager.playLose();

               startLooping = false;
               break;
            }
         }

      }
      explodeAllAsteroids = false;
      
      if (timeBar.isTimeUp()){
         soundManager.playWin();
         (uLCD).text_string("You Won!" , 5, 4, FONT_7X8, WHITE);
         startLooping = false;




      }
   } 
} 