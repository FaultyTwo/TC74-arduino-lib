// TC74-Example
// - FaultyTwo
#include "TC74.h"

TC74 dvc(0x4D); //A5 Address, also default

void setup() {
  Serial.begin(9600);
  while(dvc.isStandby()){ //wait until the sensor is ready
    
  }
  Serial.println("Hello TC74!");
}

void loop() {
  Serial.print("Current Celsius is: ");
  Serial.println(dvc.readTemperatureC());
  Serial.print("Current Fahrenheit is: ");
  Serial.println(dvc.readTemperatureF());
  Serial.print("Current Kelvin is: ");
  Serial.println(dvc.readTemperatureK());
  delay(1500);
  Serial.println();
}
