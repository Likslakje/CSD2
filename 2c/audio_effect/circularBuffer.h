#pragma once
#include <iostream>

class CircBuf{
  public:  
    // CircBuf();
    CircBuf(unsigned int samplerate, int size, float delayTime);
    ~CircBuf();
    unsigned int millisToSamples(float delayTime);
    void writeToBuf(float sample);
    float readFromBuf();
    int wrapHead(int head);
    
  private:
    unsigned int samplerate;
    int numSamplesDelay;
    float delayTime;
    int size;
    float* buffer;
    //make sure the index starts at 0
    int writeHead = 0;
    int readHead;
};