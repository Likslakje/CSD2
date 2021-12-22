#pragma once

#include <iostream>
#include "modSynth.h"

class AMSynth : public ModSynth
{
public:
  AMSynth(Waveform waveformType, double samplerate);
  ~AMSynth();

  // override virtual void form oscillator
  void calculate() override;
  
protected:

};
