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

unsigned int AudioEffect::getSamplerate(){
  return samplerate;
}

bool AudioEffect::getBypass(){
  #if DEBUG > 2
   std::cout<< "AudioEffect::AudioEffect getBypass : bypass: " << bypass <<std::endl;
  #endif
  return bypass;
}
