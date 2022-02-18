#pragma once
#include <iostream>
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/oscillator.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/saw.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/sine.h"
#include "../../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/oscillators/square.h"
#include "circularBuffer.h"
// 0 = none, 1 = low, 2= mid, 3 = high, 4 = ur mom's a hoe
#define DEBUG 0

class AudioEffect{
  public:
      enum BufferSizeType{
      SHORT = 0,
      MID,
      LONG,
      SIZE // 3
    };
    AudioEffect();
    AudioEffect(unsigned int samplerate, float dryWet, bool bypass);
    virtual ~AudioEffect();
    // apply the effect for each frame
    virtual float applyEffect(float input) = 0;
    unsigned int getSamplerate();

  private:
    unsigned int samplerate;
    // 0 = dry, 1 = wet
    //TODO: fix drywet with equal power panning curve
    float dryWet;
    //true = bypass, false = effect
    bool bypass;

};
