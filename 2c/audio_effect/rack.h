#include <iostream>
#include "modulation.h"
#include "delay.h"

class Rack{
  public:
    Rack();
    ~Rack();
  
  private:
    Modulation* modulationEffects;
    Delay* delayEffects;

};