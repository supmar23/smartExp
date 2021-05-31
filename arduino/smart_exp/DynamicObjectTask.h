#ifndef __DYNAMICOBJECTTASK__
#define __DYNAMICOBJECTTASK__

#include "Task.h"
#include "Sonar.h"
#include "Pot.h"

extern bool objPresent;
extern float distance;
extern float speedObj;
extern float accObj;

class DynamicObjectTask: public Task {
  public:
    DynamicObjectTask(Sonar* sonar, Potentiometer* pot);
    void init(int period);
    void tick();
  
  private:
    Sonar* sonar;
    Potentiometer* pot;
};

#endif
