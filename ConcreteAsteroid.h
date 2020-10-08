#ifndef CONCRETEASTEROID_H 
#define CONCRETEASTEROID_H


#include "AbstractAsteroid.h"

/**
 * @brief Concrete Asteroid
 * @author Afshawn Lotfi
 * @version 1.0.0
 */
class ConcreteAsteroid: public AbstractAsteroid
{

  public:

    /**
     * @brief Construct a new Concrete Asteroid object
     * 
     */
    ConcreteAsteroid(uLCD_4DGL * uLCD, SideOfScreen sideOfScreen);
    
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



