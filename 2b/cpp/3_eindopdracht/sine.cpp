//All credits for Sine go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/taylorSwift/csd2b/theorie/session_3/05_soundingSineClass

#include <iostream>
#include "sine.h"
#include "math.h"

Sine::Sine(double frequency, double samplerate) : Oscillator(frequency, samplerate)
{
  std::cout<< "constructor Sine" <<std::endl;
}

Sine::~Sine()
{
  std::cout<< "destructor Sine" <<std::endl;
}

void Sine::calculate()
{
  // calculate the sine 
  sample = sin(M_PI * 2 * phase);
}
