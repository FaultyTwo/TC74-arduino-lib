#ifndef TC74_ft
#define TC74_t

#include "Arduino.h"
#include "Wire.h"

#if (ARDUINO <  100) && !defined(MPIDE)
#error TC74 library requires Arduino 1.0 or later
#endif

#define STANDBY true
#define NORMAL false

class TC74{
  public:
    TC74(uint8_t _adr);
    short readTemperatureC();
    float readTemperatureF();
    float readTemperatureK(); //kfc lmao
    void TC74Mode(bool mode);
    bool isStandby();
  private:
    short readTemperature();
    uint8_t adr;
};

/* What does this library need?
 * - Can read temperature
 * - Standby mode supported
 */


#endif
