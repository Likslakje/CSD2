#pragma once

#include <iostream>
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "triangle.h"

class Synth
{
public:
  // NOTE: needs to be same order as the waveFormOptions string array
  enum Waveform {
    SineType = 0, // ensure enum starts at 0
    SawType,
    SquareType,
    TriangleType,
    Size // 3
  };
  Synth(Waveform waveformType, double carrierFreq, 
    double modulatorFreq, double samplerate);
  virtual ~Synth();

  // setters and getters
  void setWaveform(Waveform waveformType);
  void tick();
  virtual void calculate() = 0;
  double getSample();
  double mtof(float mPitch);
  void setFrequency(double freq);
  // static method because this method does not depend on objects
  static std::string waveformTypeToString(Waveform type);

protected:
  // contains current sample value
  double sample;
  double samplerate;
  // for the sake of logging
  Waveform WaveformType;
  std::string synthName;
  double carrierFreq;
  double modulatorFreq;
  Oscillator* modulatorOsc;
  Oscillator* carrierOsc;

};
