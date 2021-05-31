#include "BlinkTask.h"
#include "Arduino.h"
#include "Config.h"

extern bool objPresent;
extern bool expStart;
extern bool expFinish;

unsigned long last = 0;

BlinkTask::BlinkTask(int pin){
  this->pin = pin;    
}
  
void BlinkTask::init(int period) {
  Task::init(period);
  led = new Led(pin); 
  state = OFF;    
}
  
void BlinkTask::tick() {
  if ((!objPresent && expStart) || (expFinish)) {
    unsigned long now = millis();
    if ((now-last) < ERROR_TIME) {
      last = now;
      switch (state){
      case OFF:
        led->switchOn();
        state = ON; 
        break;
      case ON:
        led->switchOff();
        state = OFF;
        break;
      }
    }
  }
}
