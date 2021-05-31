#ifndef __SPEEDVISTASK__
#define __SPEEDVISTASK__

#include "Task.h"
#include "ServoMotorImpl.h"

class SpeedVisTask: public Task {
  public:
    SpeedVisTask(ServoMotorImpl* servo);
    void init(int period);
    void tick();
  
  private:
    ServoMotorImpl* servo;
};

#endif
