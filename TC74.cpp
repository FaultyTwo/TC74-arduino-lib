#include "TC74.h"

TC74::TC74(uint8_t adr){
  _adr = adr;
}

void TC74::begin(TwoWire &wirePort = Wire){
  //for different i2c port
  _wire = &wirePort;
  _wire->begin();
}

short TC74::readTemperature(){
  int8_t val; //easiest way for 2's complement
  _wire->beginTransmission(_adr);
  _wire->write(0x00); //I NEED TEMPERATURE
  _wire->endTransmission(false);
  _wire->requestFrom(_adr,byte(1));
  if(_wire->available()){
    val = Wire.read();
    _wire->endTransmission();
    return short(val);
  } else {
    _wire->endTransmission();
    return -999; //device not found
  }
}

void TC74::TC74Mode(bool mode){
  _wire->beginTransmission(_adr);
  _wire->write(0x01); //R/W Config
  _wire->write(0x00 | (mode << 7)); //D[7] -> STANDBY switch
  _wire->endTransmission();
}

bool TC74::isStandby(){
  _wire->beginTransmission(_adr);
  _wire->write(0x01); //I NEED ITS CONFIG
  _wire->endTransmission(false);
  _wire->requestFrom(_adr,byte(1));
  if(_wire->available()){
    if(_wire->read() == 0x40 || _wire->read() == 0x00){ //0x00 or 0x40
      _wire->endTransmission();
      return false;
    } else {
      _wire->endTransmission();
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
