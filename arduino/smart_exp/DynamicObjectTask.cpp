#include "DynamicObjectTask.h"
#include "Arduino.h"

extern bool expStart;
bool objPresent;
float speedObj; // speed in cm/s
float accObj; // speed in cm/s^2
int frequency;

unsigned long precT = 0;
float precDist = 0;
float precSpeed = 0;
unsigned long tForFrequencyPrec = 0;

DynamicObjectTask::DynamicObjectTask(Sonar* sonar, Potentiometer * pot) {
  this->sonar = sonar;
  this->pot = pot;
}

void DynamicObjectTask::init(int period) {
  Task::init(period);
  objPresent = false;
}

void DynamicObjectTask::tick() {
  if(!expStart) {
    frequency = pot->getValue();
    frequency = frequency * 100;
  }
  
  if (expStart && (sonar->getDistance()<100)) {
    unsigned long tForFrequency = millis();
    if (tForFrequency-tForFrequencyPrec >= frequency) {
      unsigned long tForGraph = millis();
      Serial.println(tForGraph * 0.001);
      objPresent = true;

      unsigned long currentT = millis();
      float currentDist = sonar->getDistance();
      speedObj = ((currentDist-precDist) / ((currentT-precT)*0.001));
      if (speedObj < 0) {
        Serial.println(speedObj * -1);
      } else {
        Serial.println(speedObj); 
      }
      precDist = currentDist;
  
      accObj = ((speedObj-precSpeed) / ((currentT-precT)*0.001));
      Serial.println(accObj);
      precSpeed = speedObj;
      
      precT = currentT;
      tForFrequencyPrec = tForFrequency;
    }
    
  } else if (expStart && (sonar->getDistance()>1.0)) {
    objPresent = false;
  }
}
