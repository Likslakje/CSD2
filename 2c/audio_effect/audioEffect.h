#pragma once
#include <iostream>
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/oscillator.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/saw.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/sine.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/square.h"
#include "circularBuffer.h"

class AudioEffect{
  public:
    AudioEffect();
    //enum in base class cuz can use it as modulation source
    enum WaveformType {
        SINE = 0, // ensure enum starts at 0
        SAW,
        SQUARE,
        SIZE // 3
    };
    AudioEffect(unsigned int samplerate, WaveformType waveformType, 
      float modFreq, float ratio);
    virtual ~AudioEffect();
    // applies tremolo effect to the input frame
    virtual float applyEffect(float input) = 0;
    void calcDryWet(float ratio);
    float getDrySig();
    float getWetSig();
    float getEffectedSample(float directInput);
    Oscillator* getOscillator();

  private:
    CircBuf* circBuf;
    Oscillator* osc;
    unsigned int samplerate;
    float modFreq;
    // 0 = dry, 1 = wet
    float ratio;
    float drySig;
    float wetSig;
    float gain;
    //true = bypass, false = effect
    bool bypass;
    float effectedSample;

};
