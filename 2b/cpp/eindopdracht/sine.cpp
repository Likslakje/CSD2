//All credits for writeToFile and sine go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
#include "sine.h"
#include "math.h"

Sine::Sine(float frequency) {
  // initialize members
  this->frequency = frequency;
  amplitude = 1.0;
  sample = 0;
  phase = 0;
  std::cout << "Sine - constructor\n";
}



Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}


float Sine::getSample() {
  return sample;
}

void Sine::tick() {
  // TODO - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / SAMPLERATE;
  sample = sin(M_PI * 2 * phase);
}

//getters and setters
void Sine::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Sine::getFrequency()
{
  return frequency;
}
