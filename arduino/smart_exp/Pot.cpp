#include "Pot.h"
#include "Arduino.h"
#include "Config.h"

Potentiometer::Potentiometer(int pin){
  this->pin = pin;
} 
  
float Potentiometer::getValue(){
  float val = analogRead(pin);
  int freq = map(val, 0, 1023, MIN_FREQ, MAX_FREQ);
  return freq;
}
