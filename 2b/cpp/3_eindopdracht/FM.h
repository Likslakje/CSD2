#pragma once

#include <iostream>
#include "synth.h"


class FMSynth : public Synth
{
public:
  FMSynth(Oscillator* waveformType[], 
    double frequencies[], double samplerate);
  ~FMSynth();
  void setWaveform(Waveform oscType, double frequencies[], 
    double samplerate);
  void calculate() override;

protected:
  int numberOsc = 2;
  int oscIndex = 0;
  // double pointer cuz the datatype = Oscillator pointer
  // and AMWaveforms points at waveformType array
  Oscillator** FMWaveforms;
};
