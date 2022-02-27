#include <iostream>
#include "circularBuffer.h"
//for the debugging
#include "audioEffect.h"

// CircBuf::CircBuf(){
  
// }

CircBuf::CircBuf(unsigned int samplerate, int size, float delayTime) : 
  samplerate(samplerate), size(size){
  #if DEBUG > 0
    std::cout<< "contructor CircBuf" <<std::endl;
  #endif

  buffer = new float[size];
  //make sure theres no shit in the buffer
  for (int i = 0; i < size; i++){
    buffer[i] = 0;
  };

  millisToSamples(delayTime);
  //set write/read heads to correct starting index
  writeHead = 0;
  readHead = size - numSamplesDelay;
}


CircBuf::~CircBuf(){
  #if DEBUG > 0
    std::cout<< "~destructor CircBuf" <<std::endl;
  #endif
  //release that bitch
  delete [] buffer;
  buffer = nullptr;
}

void CircBuf::millisToSamples(float delayTime){
  //1000 ms = 44100 samples
  numSamplesDelay = delayTime * 44.1f;
  #if DEBUG > 1
    std::cout<< "CircBuf::CircBuf millisToSamps: " << numSamplesDelay <<std::endl;
  #endif
}

void CircBuf::writeToBuf(float sample){
  writeHead = wrapHead(writeHead);
  #if DEBUG > 2
    std::cout<< "CircBuf::CircBuf writeToBuf : writehead: " << writeHead <<std::endl;
  #endif
  buffer[writeHead++] = sample;
}

float CircBuf::readFromBuf(){
  readHead = wrapHead(readHead);
  #if DEBUG > 2
    std::cout<< "CircBuf::CircBuf writeToBuf : readHead: " << readHead <<std::endl;
  #endif
  float sample = buffer[modulation + readHead++];
  return sample;

}

int CircBuf::wrapHead(int head){
  if (head > size) {
    return 0;
  }else{
    return head;
  }
} 

void CircBuf::setModulation(int modulation){
  this->modulation = modulation;
}
