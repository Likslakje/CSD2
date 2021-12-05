//All credits for writeToFile, Sine and the structure for every type of oscillator 
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "sine.h"
#include "math.h"
using namespace std;

Sine::Sine(float frequency, double samplerate) : Oscillator (frequency, samplerate){
  cout<< "sine constructor" <<endl;
}



Sine::~Sine() {

}


float Sine::getSample() {
  return sample;
}

void Sine::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  // NOTE 2. - still need todo 'something' with the phase, see 04_sin_function
  phase += frequency / samplerate;
  sample = sin(M_PI * 2 * phase) * amplitude;
}

// getters and setters


