#include <iostream>
#include "delay.h"

Delay::Delay(unsigned int samplerate, float dryWet, bool bypass,
  float delayTime) : delayTime(delayTime), AudioEffect(samplerate,
  dryWet, bypass){
  std::cout<< "contructor Delay" <<std::endl;
}

Delay::~Delay(){
  std::cout<< "~destructor Delay" <<std::endl;
  // release dynamically allocated circbuffer object.
  delete circBuf;
  circBuf = nullptr;
}

void Delay::selectBuffer(BufferSizeType bufferType){
  //select the buffer size from enum
  unsigned int samplerate = getSamplerate();
  switch (bufferType){
    case BufferSizeType::SHORT:{
      int size = 2 * samplerate;
      circBuf = new CircBuf(samplerate, size);
      break;
    }
    case BufferSizeType::MID:{
      int size = 5 * samplerate;
      circBuf = new CircBuf(samplerate, size);
      break;
    }
    case BufferSizeType::LONG:{
      int size = 10 * samplerate;
      circBuf = new CircBuf(samplerate, size);
      break;
    }
    default:
      //a modderfokking starwars reference
      throw "if an item does not appear in our records, it does not exist";
      break;
  }
}

CircBuf* Delay::getBufferType(){
  return circBuf;
}

float Delay::samplesToMillis(unsigned int delaySamples){
    float delayMillis = delaySamples;
    return delayMillis;
}
