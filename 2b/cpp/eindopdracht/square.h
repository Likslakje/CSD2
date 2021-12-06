//All credits for writeToFile, Sine and the structure for every type of oscillator 
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <iostream>
#include "oscillator.h"

#define SAMPLERATE 44100

class Square : public Oscillator {
  public:
      //Constructor and destructor
      Square(float frequency, double samplerate);
      ~Square();

      //return the current sample
      float getSample();
      // go to next sample
      void tick();
};

#endif
