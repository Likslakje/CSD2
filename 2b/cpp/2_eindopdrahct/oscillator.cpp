//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "oscillator.h"
using namespace std;

Oscillator::Oscillator(){

}

Oscillator::Oscillator(double frequency, double samplerate) : frequency(frequency), samplerate(samplerate),
    amplitude(1.0), phase(0.0), sample(0){
    cout<< "contructor Oscillator" <<endl;
}

Oscillator::~Oscillator(){
    cout<< "destructor Oscillator" <<endl;
}

void Oscillator::setWaveform(Waveform type)
{
  cout<< "\n• Synth::setWaveform" <<endl;

  cout<< "\n - using " << waveformTypeToString(type) << " as waveform"
    <<endl;
  switch (type) {
  case Waveform::Sine:
    // set sine
    cout << "\n--- selecting sine";
    break;
  case Waveform::Saw:
    // set saw
    cout << "\n--- selecting saw";
    break;
  case Waveform::Square:
    // set square
    cout << "\n--- selecting square";
    break;
  default:
    break;
  }
}


string Oscillator::waveformTypeToString(Waveform type)
{
  switch(type) {
    case Waveform::Sine:
      return "sine";
    case Waveform::Saw:
      return "saw";
    case Waveform::Square:
      return "square";
    default:
      return "Invalid waveform";
  }
}

void Oscillator::calculate(){
    
}

void Oscillator::setFrequency(double frequency){
    this->frequency = frequency;
}

double Oscillator::getFrequency(){
    return frequency;
}

void Oscillator::setAmplitude(double newAmplitude){
    this->amplitude = newAmplitude;
}

double Oscillator::getAmplitude(){
    return amplitude;
}

void Oscillator::setSamplerate(double samplerate){
    this->samplerate = samplerate;
}

double Oscillator::getSample(){
    return sample;
}

void Oscillator::nextSample(){
    phase += frequency / samplerate;
    if(phase > 1.0) phase -= 1.0;
    calculate();
    sample *= amplitude;
}