/* 
   TC74 - Arduino Library for TC74, Temperature Sensor.
   By: Chawin 'FaultyTwo' Treesugol <https://github.com/FaultyTwo/TC74-arduino-lib>
*/

#ifndef TC74_ft
#define TC74_ft

#include "Arduino.h"
#include "Wire.h"

#define STANDBY true
#define NORMAL false

/// @brief A TC74 class
class TC74{
  public:
    /// @brief Specify a TC74 device
    /// @param adr The i2c address of TC74
    TC74(uint8_t adr);
    /// @brief Initial a TC74 device
    /// @param wire A TwoWire object, leave blank for default
    void begin(TwoWire &wire = Wire);
    /// @brief Read the temperature
    /// @param c Specify the unit ('C'=Celsius, 'F'=Fahrenheit, 'K'=Kelvin)
    /// @return The temperature value in a unit
    float readTemperature(char unit);
    /// @brief Configure the power mode
    /// @param mode The device mode (logic 0 = NORMAL, logic 1 = STANDBY)
    void TC74Mode(bool mode);
    /// @brief Check if the device is in standby mode or not
    /// @return a boolean value (true or false)
    bool isStandby();
  private:
    uint8_t _adr;
    TwoWire *_wire; //for different i2c port config
};

#endif
