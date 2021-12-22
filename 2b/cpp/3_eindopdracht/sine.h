//All credits for Sine go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/taylorSwift/csd2b/theorie/session_3/05_soundingSineClass

#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#include "oscillator.h"

class Sine : public Oscillator
{
public:
  Sine(double frequency, double samplerate);
  ~Sine();

protected:
  // override the virtual calculate from Oscillator
  void calculate() override;
};

#endif
