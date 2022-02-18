#include <iostream>
#include "tremolo.h"

Tremolo::Tremolo(unsigned int samplerate, float dryWet, 
    bool bypass, WaveformType waveformType, float modFreq) :
     Modulation(samplerate, dryWet, bypass,
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
  float effectedSample;
  bool bypass = getBypass();
  if (bypass == false){
    // transform sine in range [-1, 1] to range [0, 1]
    float modSignal = getOscillator()->genNextSample() * 0.5 + 0.5;
    // apply modulation signal to input
    effectedSample = input * modSignal;
  }else{
    effectedSample = input;
  }
  #if DEBUG > 2
    std::cout<< "Tremolo::Tremolo effectedSample: " << effectedSample <<std::endl;
  #endif
  return effectedSample;
}

