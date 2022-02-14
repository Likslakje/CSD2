#include <iostream>

class CircBuf{
  public:  
    CircBuf();
    enum DelayTimeType{
      SHORT = 0,
      MID,
      LONG,
      SIZE // 3
    };
    CircBuf(unsigned int samplerate, DelayTimeType delayTimeType, 
      float delayTime);
    ~CircBuf();
    unsigned int millisToSamples(float delayTime);
  private:
    unsigned int samplerate;
    float delayTime;
    int size;
    int numSamplesDelay;
    float* buffer;
    int write;
    int read;
};