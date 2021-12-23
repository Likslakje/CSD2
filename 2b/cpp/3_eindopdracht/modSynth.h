#pragma once

#include <iostream>
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "triangle.h"

class ModSynth
{
public:
  // Enum of possible waveforms
  enum Waveform {
    SineType = 0, // ensure enum starts at 0
    SawType,
    SquareType,
    TriangleType,
    Size, // 3
    None
  };

  // pass choosen waveform to the ModSynth contructor to be used
  // by the choosen ModSynthType
  ModSynth(Waveform waveformType, double samplerate);
  virtual ~ModSynth();

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

  // store the waveformType
  Waveform WaveformType;

  // for the sake of logging
  std::string modSynthName;

  // var
  double modRatio;
  double modDepth;
  double carAmp;
  float midiPitch;
  double carrierFreq;
  double modulatorFreq;

  // Oscillator pointers
  Oscillator* modulatorOsc;
  Oscillator* carrierOsc;

  // protected cuz does not to be accessed by outside
  double mtof(float mPitch);
  void setFrequency(double freq);
  void setModFrequency(double freq);
};
