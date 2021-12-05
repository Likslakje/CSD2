//All credits for writeToFile, Sine and the structure for every type of oscillator 
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "oscillator.h"
using namespace std;

Oscillator::Oscillator(float frequency, double samplerate) : frequency(frequency),
  amplitude(1.0), phase(0), sample(0), samplerate(samplerate){
    cout<< "Oscillator" <<endl;
     this->frequency = frequency;
        amplitude = 1.0;
        sample = 0;
        phase = 0;

}

Oscillator::~Oscillator(){

}

void Oscillator::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Oscillator::getFrequency()
{
  return frequency;
}