#include <iostream>
#include "circularBuffer.h"

CircBuf::CircBuf(){

}

CircBuf::CircBuf(unsigned int samplerate, int size) : 
  samplerate(samplerate), size(size){
  std::cout<< "contructor CircBuf" <<std::endl;

  buffer = new float[size];
  //make sure theres no shit in the buffer
  for (int i = 0; i < size; i++){
    buffer[i] = 0;
  };

  //set write/read heads to correct starting index
  numSamplesDelay = millisToSamples(delayTime);
  writeHead = 0;
  readHead = size - numSamplesDelay;
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
  return delayTime;
}

void CircBuf::writeToBuf(float sample){
  writeHead = wrapHead(writeHead);
  buffer[writeHead++] = sample;
}

float CircBuf::readFromBuf(){
  readHead = wrapHead(readHead);
  float sample = buffer[readHead++];
  return sample;

}

int CircBuf::wrapHead(int head){
  if (head > size) {
    return 0;
  }else{
    return head;
  }
} 
