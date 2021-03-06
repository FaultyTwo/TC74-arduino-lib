#ifndef TC74_ft
#define TC74_ft

#include "Arduino.h"
#include "Wire.h"

#if (ARDUINO <  100) && !defined(MPIDE)
#error TC74 library requires Arduino 1.0 or later
#endif

#define STANDBY true
#define NORMAL false

class TC74{
  public:
    TC74(uint8_t adr);
	float readTemperature(char c);
    void TC74Mode(bool mode);
    bool isStandby();
    void begin(TwoWire &wirePort = Wire); //ugh
  private:
    uint8_t _adr;
    TwoWire *_wire; //for different i2c port config
};

#endif
