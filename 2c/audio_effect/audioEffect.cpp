#include <iostream>
#include "audioEffect.h"

AudioEffect::AudioEffect(){

}

AudioEffect::AudioEffect(unsigned int samplerate, float dryWet, 
  bool bypass) : samplerate(samplerate), dryWet(dryWet),
  bypass(bypass){
  #if DEBUG > 0
    std::cout<< "contructor AudioEffect" <<std::endl;
  #endif

}

AudioEffect::~AudioEffect(){
  #if DEBUG > 0
    std::cout<< "~destructor AudioEffect" <<std::endl;
  #endif
}

float AudioEffect::bypassOrApply(float input){
  float effectedSample;
  if(bypass == false){
    effectedSample = applyEffect(input);
  }else{
    effectedSample = input;
  }
  return effectedSample;
}