#ifndef __SONAR__
#define __SONAR__

#include "TemperatureSensor.h"

class Sonar {
  public:
    Sonar(int echoPin, int trigPin, TemperatureSensor* sTemp);
    float getDistance();

  private:
    const float vs = 331.5 + 0.6*(sTemp->getTemperature());
    int echoPin;
    int trigPin;
    TemperatureSensor* sTemp;
};

#endif
