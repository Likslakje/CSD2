//All credits for writeToFile, Sine and the structure for every type of oscillator 
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include "oscillator.h"

#define SAMPLERATE 44100

class Saw : public Oscillator {
  public:
      //Constructor and destructor
      Saw(float frequency, double samplerate);
      ~Saw();

      //return the current sample
      float getSample();
      // go to next sample
      void tick();
};

#endif