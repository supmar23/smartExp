#ifndef __DETECTOPERATORTASK__
#define __DETECTOPERATORTASK__

#include "Task.h"
#include "Pir.h"
#include "Led.h"
#include "Button.h"
#include "Sonar.h"
#include "Utility.h"

extern bool detectedStatus;
extern bool expStart;
extern bool expFinish;

class DetectOperatorTask: public Task {
  
  public:
    DetectOperatorTask(Pir* pir, Led* ledRed, Led* ledGreen, Button* bStart, Button* bStop, Sonar* sonar, Utility* ut);
    void init(int period);
    void tick();

  private:
    Pir* pir;
    Led* ledRed;
    Led* ledGreen;
    Button* bStart;
    Button* bStop;
    Sonar* sonar;
    Utility* ut;
};

#endif
