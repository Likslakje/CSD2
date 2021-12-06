//All credits for writeToFile, Sine and the structure for every type of oscillator 
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
#include "saw.h"
#include "math.h"

Saw::Saw(float frequency, double samplerate) : Oscillator (frequency, samplerate) {
  // initialize members
  this->frequency = frequency;
  amplitude = 1.0;
  sample = 0;
  phase = 0;
  std::cout << "Saw - constructor\n";
}



Saw::~Saw() {
  std::cout << "Saw - destructor\n";
}


float Saw::getSample() {
  return sample;
}

void Saw::tick() {
  // TODO - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / SAMPLERATE;
  sample = sin(M_PI * 2 * phase);
}
