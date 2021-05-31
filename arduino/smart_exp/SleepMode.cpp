//#include "SleepMode.h"
//#include "Arduino.h"
//
//void wakeUp() {}
//
//SleepMode::SleepMode(int pin) {
//  this->pin = pin;
//}
//
//void SleepMode::init() {
//  attachInterrupt(digitalPinToInterrupt(pin), wakeUp, RISING);
//}
//
//void SleepMode::goSleep() {
//  Serial.println("going in sleep mode...");
//  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
//  sleep_enable();
//  sleep_mode();
//  Serial.println("wake up!");
//  sleep_disable();
//}
