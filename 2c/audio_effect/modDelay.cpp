#include <iostream>
#include "modDelay.h"

ModDelay::ModDelay(unsigned int samplerate, float dryWet, 
      bool bypass, BufferSizeType bufferSizeType, float delayTime,
      float feedback, float modFreq, float modDepth) : modDepth(modDepth),
      Delay(samplerate, dryWet, bypass, bufferSizeType,
      delayTime, feedback){

  std::cout<< "contructor ModDelay" <<std::endl;
  osc = new Sine(modFreq, samplerate);
}

ModDelay::~ModDelay(){
  std::cout<< "~destructor ModDelay" <<std::endl;
  delete osc;
  osc = nullptr;
}

float ModDelay::applyEffect(float input){
  float effectedSample;
  circBuf->writeToBuf(input);
  //range osc = size buffer
  //osc sample dictates index of readhead
  float modSig = osc->genNextSample();
  // just the hardcoded max
  // max = 250 seconds
  int modSigAsIndex = modSig * modDepth;
  circBuf->setModulation(modSigAsIndex);
  delayedSignal = circBuf->readFromBuf();
  effectedSample = input + (delayedSignal * dryWet);
  return effectedSample;
}