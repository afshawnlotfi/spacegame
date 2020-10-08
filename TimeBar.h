#ifndef TIMEBAR_H 
#define TIMEBAR_H 

#include "ScreenObject.h"
#include "mbed.h"

/**
 * @brief Time Bar
 * @author Afshawn Lotfi
 * @version 1.0.0
 */
class TimeBar: public ScreenObject
{


  public:

    TimeBar(uLCD_4DGL *uLCD);
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

    /**
     * @brief Get the Time Elapsed object
     * 
     * @return int 
     */
    double getTimeElapsed();

    bool isTimeUp();

  private:
    
    double barLength;
    int startTime;
};

#endif



