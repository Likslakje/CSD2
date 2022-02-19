#pragma once
#include <iostream>

class Wavetable{
  public:
    Wavetable(unsigned int samplerate, int sizeTable, int freq);
    ~Wavetable();
    float getWavetableAtIndex();
    void fillWavetable(float sample);

    float* wavetable;
  private:
    int sizeTable;
    // initialize it with index 0
    unsigned int wavetableSamplerate;
    int writeWavetableIndex = 0;
    int readWavetableIndex = 0;
    int sampleCount = 0;
    unsigned int calcWavetableSamplerate(unsigned int samplerate, int freq);
   
};
