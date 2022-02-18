#include "tremolo.h"

Tremolo::Tremolo(unsigned int samplerate, float dryWet, 
    bool bypass, WaveformType waveformType, float modFreq) :
     Modulation(samplerate, waveformType, dryWet, 
     waveformType, modFreq){
  #if DEBUG > 0
    std::cout<< "constructor Tremolo" <<std::endl;
  #endif
}

Tremolo::~Tremolo(){
  #if DEBUG > 0
    std::cout<< "~destructor Tremolo" <<std::endl;
  #endif
}

float Tremolo::applyEffect(float input){
  // transform sine in range [-1, 1] to range [0, 1]
  float modSignal = getOscillator()->genNextSample() * 0.5 + 0.5;
  // apply modulation signal to input
  float effectedSample = input * modSignal;
  #if DEBUG > 1
    std::cout<< "Tremolo::Tremolo effectedSample: " << effectedSample <<std::endl;
  #endif
  return effectedSample;
}

