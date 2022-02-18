#pragma once
#include <iostream>
#include "audioEffect.h"
#include "circularBuffer.h"

class Delay : public AudioEffect{
  public:
    enum BufferSizeType{
    SHORT = 0,
    MID,
    LONG,
    SIZE // 3
  };
    Delay(unsigned int samplerate, float dryWet, 
      bool bypass, BufferSizeType bufferSizeType, float delayTime);
    ~Delay();
    //creates a circular buffer of the selected size
    void selectBuffer(BufferSizeType bufferType, float delayTime);
    CircBuf* getBufferType();

  private:
    float delayTime;
    CircBuf* circBuf;
};