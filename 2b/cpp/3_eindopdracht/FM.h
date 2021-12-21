#pragma once

#include <iostream>
#include "synth.h"


class FMSynth : public Synth
{
public:
  FMSynth(Waveform waveformType, double carrierFreq, 
    double modulatorFreq, double samplerate);
  ~FMSynth();

  void setWaveform(Waveform type) override;

  void calculate() override;

protected:
};
