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
    AudioEffect(unsigned int samplerate, float dryWet, bool bypass);
    virtual ~AudioEffect();
    //creaets the necessary oscillator dynamicly
    void selectWaveform(Oscillator::WaveformType waveformType);
    Oscillator* getOscillator();
    //creates a circular buffer of the selected size
    void selectBuffer(CircBuf::BufferSizeType bufferType);
    CircBuf* getBufferType();
    // apply the effect for each frame
    virtual float applyEffect(float input) = 0;
    //get the the effected sample
    float getEffectedSample(float directInput);

  private:
    Oscillator* osc;
    CircBuf* circBuf;
    unsigned int samplerate;
    // 0 = dry, 1 = wet
    //TODO: fix drywet with equal power panning curve
    float dryWet;
    //true = bypass, false = effect
    bool bypass;
    //default modfreq is 2 Hz
    float modFreq = 2;
    float effectedSample;

};
