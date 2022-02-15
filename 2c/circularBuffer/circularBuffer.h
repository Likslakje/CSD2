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
    int writeHead = 0;
};