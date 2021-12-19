#pragma once

#include <iostream>
#include "synth.h"

class AMSynth : public Synth
{
public:
  AMSynth(double samplerate, Waveform oscType, 
    double carFreq, double modFreq);
  ~AMSynth();

  enum OscType {
    Modulator,
    Carrier,
    Size
  };
  void calculate() override;
  // setters and getters
#if 0
  // TODO this is the next step, to also allow user to set waveform per
  // oscillator
  void setWaveform(Waveform type, OscType oscType);
  static std::string oscTypeToString(OscType type);
#else
  void setWaveform(Waveform oscType, double carFreq, 
    double modFreq, double);
#endif

protected:
  int numberOsc = 2;
  // Oscillator* carrierOsc;
  // Oscillator* modulatorOsc;
  Oscillator* oscillators[2];
};
