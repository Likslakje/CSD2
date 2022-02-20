#include <iostream>

class CircBuf{
  public:  
    CircBuf();
    CircBuf(int size);
    ~CircBuf();
    unsigned int millisToSamples(float delayTime);
    void writeToBuf(float sample);
    float readFromBuf();
    int wrapHead(int head);
    float* getBuffer();
  private:
    unsigned int samplerate;
    int size;
    float* buffer;
    int readHead;
    //make sure the index starts at 0
    int writeHead = 0;
};