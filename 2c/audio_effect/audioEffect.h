#pragma once
#include <iostream>
// 0 = none, 1 = low, 2= mid, 3 = high, 4 = ur mom's a hoe
#define DEBUG 1

class AudioEffect{
  public:
    AudioEffect();
    AudioEffect(unsigned int samplerate, float dryWet, bool bypass);
    virtual ~AudioEffect();
    // apply the effect for each frame
    float bypassOrApply(float input);
    virtual float applyEffect(float input) = 0;
    protected:
    unsigned int samplerate;
    // 0 = dry, 1 = wet
    //TODO: fix drywet with equal power panning curve
    float dryWet;
    //true = bypass, false = effect
    bool bypass;

};
