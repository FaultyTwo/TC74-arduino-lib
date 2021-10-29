#include "TC74.h"

TC74::TC74(uint8_t _adr){
  adr = _adr;
  Wire.begin();
}

short TC74::readTemperature(){
  int8_t val; //easiest way for 2's complement
  Wire.beginTransmission(adr);
  Wire.write(0x00); //I NEED TEMPERATURE
  Wire.endTransmission(false);
  Wire.requestFrom(adr,byte(1));
  if(Wire.available()){
    val = Wire.read();
    Wire.endTransmission();
    return short(val);
  } else {
    Wire.endTransmission();
    return -999; //device not found
  }
}

void TC74::TC74Mode(bool mode){
  Wire.beginTransmission(adr);
  Wire.write(0x01); //R/W Config
  Wire.write(0x00 | (mode << 7)); //D[7] -> STANDBY switch
  Wire.endTransmission();
}

bool TC74::isStandby(){
  Wire.beginTransmission(adr);
  Wire.write(0x01); //I NEED ITS CONFIG
  Wire.endTransmission(false);
  Wire.requestFrom(adr,byte(1));
  if(Wire.available()){
    if(Wire.read() == 0x40 || Wire.read() == 0x00){ //0x00 or 0x40
      Wire.endTransmission();
      return false;
    } else {
      Wire.endTransmission();
      return true;
    }
  }
}

//no need for creating 'isReady' function
//isStandby also covers the 'data ready' config too

//this might makes transmission cry
//but precision is everything.. uh, kinda

short TC74::readTemperatureC(){
  return readTemperature() == -999 ? -999 : readTemperature();
}

float TC74::readTemperatureF(){
  return readTemperature() == -999 ? -999 : (readTemperature()*(9.0/5)) + 32;
}

float TC74::readTemperatureK(){
  return readTemperature() == -999 ? -999 : readTemperature() + 273.15;
}
