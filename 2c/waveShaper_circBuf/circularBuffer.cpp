#include <iostream>
#include "circularBuffer.h"

CircBuf::CircBuf(){

}

CircBuf::CircBuf(int size) : size(size){
  std::cout<< "contructor CircBuf" <<std::endl;

  buffer = new float[size];
  //make sure theres no shit in the buffer
  for (int i = 0; i < size; i++){
    buffer[i] = 0;
  };

  writeHead = 0;
  readHead = 0;
}


CircBuf::~CircBuf(){
  std::cout<< "~destructor CircBuf" <<std::endl;
  //release that bitch
  delete [] buffer;
  buffer = nullptr;
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
