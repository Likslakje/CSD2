#pragma once

#include <iostream>
#include "synth.h"

class AMSynth : public Synth
{
public:
  AMSynth(Oscillator* waveformType[], 
    double frequencies[], double samplerate);
  ~AMSynth();

  // enum OscType {
  //   Modulator,
  //   Carrier,
  //   Size
  // };
  void calculate() override;
  // setters and getters
// #if 0
//   // TODO this is the next step, to also allow user to set waveform per
//   // oscillator
//   void setWaveform(Waveform type, OscType oscType);
//   static std::string oscTypeToString(OscType type);
// #else
//   void setWaveform(Oscillator* waveformType[], double frequencies[], 
//     double samplerate);
// #endif

protected:
  int numberOsc = 2;
  int oscIndex = 0;
  // double pointer cuz the datatype = Oscillator pointer
  // and AMWaveforms points at waveformType array
  Oscillator** AMWaveforms;
};
