#include <iostream>
#include "delay.h"

Delay::Delay(unsigned int samplerate, WaveformType waveformType,
      float modFreq, float ratio) : AudioEffect(samplerate, 
      waveformType, modFreq, ratio){
    std::cout<< "constructor Delay" <<std::endl;
}

Delay::~Delay(){
    std::cout<< "~destructor Delay" <<std::endl;
}

float Delay::samplesToMillis(unsigned int delaySamples){
    float delayMillis = delaySamples;
    return delayMillis;
}

void Delay::setDelayTime(unsigned int delaySamples){
    delayTime = samplesToMillis(delaySamples);
}

float Delay::applyEffect(float input)
{
  return input;
}

