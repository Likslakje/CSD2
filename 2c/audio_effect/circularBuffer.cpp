#include <iostream>
#include "circularBuffer.h"

CircBuf::CircBuf(int size, int numSamplesDelay) : size(size), numSamplesDelay(numSamplesDelay){
    std::cout<< "contructor circular buffer" <<std::endl;
    buffer = new float[size];
    //make sure  buffer is 0 at every index
    for(int i = 0; i < size; i ++){
        buffer[i] = 0;
    }
}

CircBuf::~CircBuf(){
    std::cout<< "~destructor circular buffer" <<std::endl;
    //release the buffer
    delete [] buffer;
    buffer = nullptr;
}

void CircBuf::writeToBuf(float value){
    //somethimng execute sample tick
        // buffer[i] = value;
}

float CircBuf::readBuf(){
    return delayedValue;
}

void CircBuf::wrapWrite(){
    if(write >= size){
        write -= size;
    }
}