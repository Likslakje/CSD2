#include "tremolo.h"

Tremolo::Tremolo(unsigned int samplerate, WaveformType waveformType = SINE, 
  float modFreq = 10.0f, float ratio = 1.0f) : AudioEffect(samplerate, waveformType, modFreq, ratio){
  std::cout<< "constructor Tremolo" <<std::endl;
}

Tremolo::~Tremolo(){
  std::cout<< "~destructor Tremolo" <<std::endl;
}

float Tremolo::applyEffect(float input){
  // transform sine in range [-1, 1] to range [0, 1]
  modSignal  = getOscillator()->genNextSample() * 0.5 + 0.5;
  // apply modulation signal to input
  float effectedSample = input * modSignal;
  return effectedSample;
}

void Tremolo::setModFreq(float modFreq){
  if(modFreq >= modFreqMin && modFreq <= modFreqMax) {
    getOscillator()->setFrequency(modFreq);
  } else {
    std::cout << "• Tremelo::setModFreq - modFreq is incorrect"
      << " please pass value between " << modFreqMin << " and " << modFreqMax
      << std::endl;
  }
}
