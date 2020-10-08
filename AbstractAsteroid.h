#ifndef ABSTRACTASTEROID_H 
#define ABSTRACTASTEROID_H

#define ASTEROID_HEIGHT 12 
#define ASTEROID_WIDTH 15
#include "ScreenObject.h"





/**
 * @brief Side of Screen
 * 
 */
enum SideOfScreen
{
    TOPLEFT,
    TOPRIGHT,
    BOTTOMLEFT,
    BOTTOMRIGHT
};




/**
 * @brief Abstract Asteroid Object
 * @author Afshawn Lotfi
 * @version 1.0.0
 */
class AbstractAsteroid: public ScreenObject
{

  public:


    AbstractAsteroid(uLCD_4DGL *uLCD,SideOfScreen sideOfScreen);

    /**
     * @brief Gets delta X position
     * 
     * @return double delta X position
     */
    double getDeltaX();
    /**
     * @brief Gets delta Y position
     * 
     * @return double delta Y position
     */
    double getDeltaY();
    /**
     * @brief Sets delta X position
     * 
     * @param deltaX 
     */
    void setDeltaX(double deltaX);
    /**
     * @brief Sets delta Y position
     * 
     * @param deltaY 
     */
    void setDeltaY(double deltaY);

    /**
     * @brief Get the Side Screen object
     * 
     * @return SideOfScreen 
     */
    SideOfScreen getSideScreen();


  private:
    /**
     * @brief X position of object
     * 
     */
    double deltaX; 
    /**
     * @brief Y position of object
     * 
     */
    double deltaY;

    /**
     * @brief Side of screen asteroid comes from
     * 
     */
    SideOfScreen sideOfScreen;


  protected:
    double generateNum(double min, double max);
    void moveAsteroid();
    void resetAsteroid();

};


#endif

