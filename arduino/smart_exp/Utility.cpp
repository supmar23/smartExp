#include "Utility.h"
#include "Arduino.h"
#include "Pir.h"
#include <avr/sleep.h>

void wakeUp(){}

Utility::Utility(int pirPin) {
  attachInterrupt(digitalPinToInterrupt(pirPin), wakeUp, RISING);
}

void Utility::sleep() {
  Serial.println("going sleep...");
  delay(100);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);  
  sleep_enable();
  sleep_mode(); 
  // ...
  Serial.println("wake up!");
  sleep_disable();
}
