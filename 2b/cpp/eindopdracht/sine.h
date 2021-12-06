//All credits for writeToFile, Sine and the structure for every type of oscillator 
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#include "oscillator.h"

// #define SAMPLERATE 44100

class Sine : public Oscillator {
  public:
      Sine(float frequency, double samplerate);
      ~Sine();
      //getSample() and tick() not inside Oscillator() because they are unique per type of wavefrom
      //return the current sample
      float getSample();
      // go to next sample
      void tick();
};

#endif
