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
      bool bypass, BufferSizeType bufferSizeType, float delayTime,
      float feedback);
    ~Delay();
    // selectSize sperate cuz we need it for retrieveValueInRange functions max
    static int selectSize(unsigned int samplerate, BufferSizeType bufferType);
    //creates a circular buffer of the selected size
    void selectBuffer(BufferSizeType bufferType, float delayTime);
    void modulateDelayTime(float modulation);
    float applyEffect(float input) override;

  protected:
    float delayTime;
    float feedback;
    //delayedSignal must be initialized with 0
    //cuz the first sample that written to the circular buffer
    //= the input sample + the delayed sample
    float delayedSignal = 0;
    CircBuf* circBuf;
    //make static cuz it needs to be accessed from AudioManager
    int size;
};