#pragma once

#include <iostream>
#include "synth.h"

class AMSynth : public Synth
{
public:
  AMSynth(Waveform waveformType, double samplerate);
  ~AMSynth();

  // enum OscType {
  //   Modulator,
  //   Carrier,
  //   Size
  // };
  void calculate() override;
  // setters and getters

protected:

};
