#include <iostream>
#include "delay.h"

Delay::Delay(unsigned int samplerate, float dryWet, bool bypass,
  BufferSizeType bufferSizeType, float delayTime) : delayTime(delayTime), AudioEffect(samplerate,
  dryWet, bypass){
  #if DEBUG > 0 
    std::cout<< "contructor Delay" <<std::endl;
  #endif
  //create a Circbuffer object dynamicly
  selectBuffer(bufferSizeType, delayTime);
}

Delay::~Delay(){
  #if DEBUG > 0
    std::cout<< "~destructor Delay" <<std::endl;
  #endif
  // release dynamically allocated circbuffer object.
  delete circBuf;
  circBuf = nullptr;
}

void Delay::selectBuffer(BufferSizeType bufferType, float delayTime){
  //select the buffer size from enum
  unsigned int samplerate = getSamplerate();
  int size;
  switch (bufferType){
    case BufferSizeType::SHORT:{
      size = 2 * samplerate;
      circBuf = new CircBuf(samplerate, size, delayTime);
      break;
    }
    case BufferSizeType::MID:{
      size = 5 * samplerate;
      circBuf = new CircBuf(samplerate, size, delayTime);
      break;
    }
    case BufferSizeType::LONG:{
      size = 10 * samplerate;
      circBuf = new CircBuf(samplerate, size, delayTime);
      break;
    }
    default:
      //a modderfokking starwars reference
      throw "if an item does not appear in our records, it does not exist";
      break;
  }
  #if DEBUG > 1
    std::cout<< "Delay::Delay selectBuffer: " << size <<std::endl;
  #endif
}

CircBuf* Delay::getBufferType(){
  return circBuf;
}
