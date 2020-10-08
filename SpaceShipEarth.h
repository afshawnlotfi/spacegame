#ifndef SPACESHIPEARTH_H 
#define SPACESHIPEARTH_H 
#define EARTH_WIDTH 10 
#define EARTH_HEIGHT 10
#include "ScreenObject.h"
#include "MMA8452.h"







/**
 * @brief Space Ship Earth
 * @author Afshawn Lotfi
 * @version 1.0.0
 */
class SpaceShipEarth: public ScreenObject
{


  public:

    SpaceShipEarth(uLCD_4DGL *uLCD);
    /**
     * @brief Draws asteroid
     * 
     */
    virtual void draw();
    /**
     * @brief Updates asteroid
     * 
     */
    virtual void update();

    void explode();



};

#endif



