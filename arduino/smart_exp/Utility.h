#ifndef __UTILITY__
#define __UTILITY__

#include "Pir.h"

class Utility {
  public:
    Utility(int pinPir);
    void sleep();
  private:
    int pinPin;
};

#endif
