#include <iostream>
#include "audioEffect.h"

class Delay : public AudioEffect{
  public:
    Delay(unsigned int samplerate, float dryWet, 
      bool bypass, float delayTime);
    ~Delay();
    //creates a circular buffer of the selected size
    void selectBuffer(BufferSizeType bufferType);
    CircBuf* getBufferType();
    float samplesToMillis(unsigned int delaySamples);

  private:
    float delayTime;
    CircBuf* circBuf;
};