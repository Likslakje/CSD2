#pragma once
#include <iostream>

class CircBuf{
  public:
    CircBuf(int size, int numSamplesDelay);
    ~CircBuf();

    void writeToBuf(float sample);
    float readBuf();
    void wrapWrite();

  private:
    int size; //= the total delay length
    int numSamplesDelay;
    int write;
    int read;
    float delayedValue;
    // reserve space for the buffer
    float* buffer;

};