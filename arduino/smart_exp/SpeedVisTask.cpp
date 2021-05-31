#include "SpeedVisTask.h"
#include "Arduino.h"
#include "Config.h"

extern bool expStart;
extern bool objPresent;
extern float speedObj;

SpeedVisTask::SpeedVisTask(ServoMotorImpl* servo) {
  this->servo = servo;
}

void SpeedVisTask::init(int period) {
  Task::init(period);
}

void SpeedVisTask::tick() {
  if (expStart && objPresent) {
    servo->on();
    int myangle = map(speedObj, 0, MAX_VEL, 0, 180);
    servo->setPosition(myangle);
  }
}
