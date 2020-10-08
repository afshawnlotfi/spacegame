#ifndef SCREENOBJECT_H 
#define SCREENOBJECT_H
#include "uLCD_4DGL.h"
#define SPRITE_MAX 15
#define EXPLOSION1_WIDTH 20
#define Q 0x808000 //OLIVE 
#define I 0x008000 //GREEN 
#define S 0xC0C0C0 //SILVER 
#define C 0x17202A //UFO GLASS 
#define D 0x797D7F //DARK GREY 
#define L 0x00FF00 //LIME 
#define P 0xFF00FF //PINK 
#define R 0xF1C40F //YELLOW 
#define O 0xF39C12 //ORANGE 
#define G 0xAAB7B8 //GREY 
#define _ 0x000000 //BLACK 
#define X 0xFFFFFF //WHITE 
#define B 0x0000FF //BLUE 
#define r 0xFF0000 //RED
#define SCREEN_MAX 125 
#define SCREEN_MIN 1
#define NUM_ASTEROIDS 4



class ScreenObject;
bool overlap(ScreenObject & objectA, ScreenObject & objectB);



/**
 * @brief Abstract ScreenObject
 * @author Afshawn Lotfi
 * @version 1.0.0
 */
class ScreenObject
{

  public:


    ScreenObject(uLCD_4DGL * uLCD);
    /**
     * @brief Virtual Function that draws
     * 
     */
    virtual void draw()=0;
    /**
     * @brief Virtual function that updates
     * 
     */
    virtual void update()=0;

    /**
     * @brief Gets X Pos
     * 
     * @return double 
     */
    double getXPos();

    /**
     * @brief Gets Y Pos
     * 
     * @return double 
     */
    double getYPos();



  protected:
    /**
     * @brief X position of object
     * 
     */
    double xPos; 
    /**
     * @brief Y position of object
     * 
     */
    double yPos;
   


    uLCD_4DGL * uLCD;

};


#endif



