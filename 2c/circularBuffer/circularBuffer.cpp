#include <iostream>
#include "circularBuffer.h"

CircBuf::CircBuf(){

}

CircBuf::CircBuf(unsigned int samplerate, DelayTimeType delayTimeType,
  float delayTime) : 
  samplerate(samplerate), delayTime(delayTime){
  std::cout<< "contructor CircBuf" <<std::endl;
  //select the buffer size from enum
  switch (delayTimeType){
    case DelayTimeType::SHORT:{
      size = 2000 * samplerate;
      break;
    }
    case DelayTimeType::MID:{
      size = 5000 * samplerate;
      break;
    }
    case DelayTimeType::LONG:{
      size = 10000 * samplerate;
      break;
    }
    default:
      throw "if an item does not appear in our records, it does not exist";
      break;
    }

  buffer = new float[size];
  //make sure theres no shit in the buffer
  for (int i = 0; i < size; i++){
    buffer[i] = 0;
  };

  //set write/read heads to correct starting index
  numSamplesDelay = millisToSamples(delayTime);
  write = 0;
  read = size - numSamplesDelay;
}


CircBuf::~CircBuf(){
  std::cout<< "~destructor CircBuf" <<std::endl;
  //release that bitch
  delete [] buffer;
  buffer = nullptr;
}

unsigned int CircBuf::millisToSamples(float delayTime){
  //1000 ms = 44100 samples
  delayTime *= 44.1f;
  std::cout<< delayTime <<std::endl;
  return delayTime;
}

