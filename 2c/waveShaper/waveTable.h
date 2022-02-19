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
    int writeSample = 0;
    int readSample = 0;
    int sampleCount = 0;
    // this changes to interpolation later
    int sampleReadCount = 0;
    unsigned int calcWavetableSamplerate(unsigned int samplerate, int freq);
   
};
