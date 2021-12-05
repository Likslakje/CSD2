//All credits for writeToFile and sine go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#include "oscillator.h"

#define SAMPLERATE 44100

class Sine : public Oscillator {
  public:
      //Constructor and destructor
      Sine(float frequency);
      ~Sine();

      //return the current sample
      float getSample();
      // go to next sample
      void tick();

      //getters and setters
      // void setFrequency(float frequency);
      // float getFrequency();

      //NOTE - do we need a setter for phase? for now -> not using one

  private:
    float amplitude;
    float frequency;
    float phase;
    // contains the current sample
    float sample;
};

#endif
