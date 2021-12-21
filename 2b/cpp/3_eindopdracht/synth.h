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
  Synth(Waveform waveformType, double samplerate);
  virtual ~Synth();

  // setters and getters
  void setWaveform(Waveform waveformType);
  void tick();
  virtual void calculate() = 0;
  double getSample();
  void setMPitch(float mPitch);
  void setRatio(double ratio);
  // static method because this method does not depend on objects
  static std::string waveformTypeToString(Waveform type);

  //TODO - add setters for the modDepth and carAmp

protected:
  // contains current sample value
  double sample;
  double samplerate;
  // for the sake of logging
  Waveform WaveformType;
  std::string synthName;
  double modRatio;
  double modDepth;
  double carAmp;
  float midiPitch;


  double carrierFreq;
  double modulatorFreq;
  Oscillator* modulatorOsc;
  Oscillator* carrierOsc;

  double mtof(float mPitch);
  void setFrequency(double freq);
  void setModFrequency(double freq);
};
