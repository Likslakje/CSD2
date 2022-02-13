#pragma once
#include <iostream>
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/oscillator.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/saw.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/sine.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/square.h"
#include "circularBuffer.h"

class AudioEffect{
  public:
    //enum in base class cuz can use it as modulation source
    enum WaveformType {
        SINE = 0, // ensure enum starts at 0
        SAW,
        SQUARE,
        SIZE // 3
    };

    AudioEffect();
    AudioEffect(unsigned int samplerate, WaveformType waveformType, float modFreq);
    virtual ~AudioEffect();

        // applies tremolo effect to the input frame
    virtual float processFrame(float input) = 0;

    unsigned int getSamplerate();

private:
    CircBuf* circularBuffer;
    Oscillator* osc;
    unsigned int samplerate;
    float dryWet;
    float gain;
    //true = bypass, false = effect
    bool bypass;

};
