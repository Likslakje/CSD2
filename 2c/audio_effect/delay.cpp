#include <iostream>
#include "delay.h"

Delay::Delay(unsigned int samplerate) : AudioEffect(samplerate){
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

float Delay::processFrame(float input)
{
  return input;
}

