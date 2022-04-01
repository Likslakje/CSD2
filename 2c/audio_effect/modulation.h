#pragma once
#include <iostream>
#include "audioEffect.h"
#include "../../../CSD2_pull/Ciska/CSD_21-22/csd2c/sharedCode/oscillators/oscillator.h"
#include "../../../CSD2_pull/Ciska/CSD_21-22/csd2c/sharedCode/oscillators/saw.h"
#include "../../../CSD2_pull/Ciska/CSD_21-22/csd2c/sharedCode/oscillators/sine.h"
#include "../../../CSD2_pull/Ciska/CSD_21-22/csd2c/sharedCode/oscillators/square.h"

class Modulation : public AudioEffect{
  public:
    enum WaveformType {
      SINE = 0, // ensure enum starts at 0
      SAW,
      SQUARE,
      SIZE // 3
    };
    Modulation(unsigned int samplerate, float dryWet, 
      bool bypass, WaveformType waveformType, float modFreq);
    ~Modulation();
    void selectWaveform(WaveformType waveformType);
    float applyEffect(float input) override;
  protected:
    Oscillator* osc;
    float modFreq;
};