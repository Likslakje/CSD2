#include "tremolo.h"

Tremolo::Tremolo(unsigned int samplerate, float dryWet, 
    bool bypass, WaveformType waveformType, float modFreq) :
     Modulation(samplerate, waveformType, dryWet, 
     waveformType, modFreq){
  std::cout<< "constructor Tremolo" <<std::endl;
}

Tremolo::~Tremolo(){
  std::cout<< "~destructor Tremolo" <<std::endl;
}

float Tremolo::applyEffect(float input){
  // transform sine in range [-1, 1] to range [0, 1]
  float modSignal = getOscillator()->genNextSample() * 0.5 + 0.5;
  // apply modulation signal to input
  float effectedSample = input * modSignal;
  return effectedSample;
}

