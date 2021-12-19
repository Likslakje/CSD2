#pragma once

#include <iostream>
#include "synth.h"


class FMSynth : public Synth
{
public:
  FMSynth(double samplerate, Waveform oscType, 
  double carFreq, double modFreq);
  ~FMSynth();

  void calculate() override;

protected:
  Oscillator* carrierOsc;
  Oscillator* modulatorOsc;
};
