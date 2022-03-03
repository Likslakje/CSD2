#pragma once
#include <iostream>
#include "../../../CSD2_pull/Ciska/CSD_21-22/csd2c/sharedCode/oscillators/oscillator.h"
#include "../../../CSD2_pull/Ciska/CSD_21-22/csd2c/sharedCode/oscillators/saw.h"
#include "../../../CSD2_pull/Ciska/CSD_21-22/csd2c/sharedCode/oscillators/sine.h"
#include "../../../CSD2_pull/Ciska/CSD_21-22/csd2c/sharedCode/oscillators/square.h"

class Wavetable{
  public:
    Wavetable();
    enum WaveformType {
      SINE = 0, // ensure enum starts at 0
      SAW,
      SQUARE,
      SIZE // 3
    };
    Wavetable(unsigned int samplerate, int size, 
      WaveformType waveformType, int freq);
    ~Wavetable();
    void selectWaveform(WaveformType waveformType);
    void oscToWavetable();
    float getSampWavetable();
  private:
    float* buffer;
    Oscillator* osc;
    unsigned int samplerate;
    int size;
    int oneCycle;
    float freq;
    unsigned int wavetableSamplerate;
    int writeCount = 0;
    int bufferWriteIndex = 0;
    int readCount = 0;
    int bufferReadIndex = 0;


};
