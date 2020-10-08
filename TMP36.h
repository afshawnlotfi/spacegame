#include "mbed.h"
#ifndef TMP36_H 
#define TMP36_H
//Setup a new class for TMP36 sensor
class TMP36
{
  public:
    TMP36(PinName pin);
    TMP36();
    float read();

  private:
    //class sets up the AnalogIn pin
    AnalogIn _pin;
};
#endif


