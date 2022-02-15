#pragma once
#include <iostream>

class CircBuf{
  public:  
    CircBuf();
    enum BufferSizeType{
      SHORT = 0,
      MID,
      LONG,
      SIZE // 3
    };
    CircBuf(unsigned int samplerate, int size);
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
    int readHead;
    //make sure the index starts at 0
    int writeHead = 0;
};