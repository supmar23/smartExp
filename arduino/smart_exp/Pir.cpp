#include "Pir.h"
#include "Arduino.h"

Pir::Pir(int pin){
  this->pin = pin;
  pinMode(pin, INPUT);     
} 
  
bool Pir::isDetected(){
  return digitalRead(pin) == HIGH;
}

void Pir::calibrate(){
  Serial.println("Wait 10 sec for pir calibration");
  delay(10000);
}
