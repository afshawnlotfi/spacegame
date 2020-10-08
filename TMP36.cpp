#include "TMP36.h"
#include "mbed.h"


TMP36::TMP36(PinName pin) : _pin(pin) {} //This is an initializer list ... more to come in class // _pin(pin) means pass pin to the AnalogIn constructor
float TMP36::read()
{
    //convert sensor reading to temperature in degrees C
    return ((_pin.read() * 3.3) - 0.500) * 100.0;
    //read() function returns a normalized value of the voltage from 0 to 1 as a float
}


