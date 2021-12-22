#pragma once

#include <iostream>
#include "modSynth.h"


class FMSynth : public ModSynth
{
public:
  FMSynth(Waveform waveformType, double samplerate);
  ~FMSynth();

  // override virtual void form oscillator
  void calculate() override;

protected:
};
