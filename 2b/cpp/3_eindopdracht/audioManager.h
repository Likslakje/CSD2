#pragma once
#include <iostream>
#include "jack_module.h"
// TODO - use interface SelectionUtil instead!
#include "userInput.h"
#include "synth.h"

class AudioManager
{
public:
  AudioManager();
  ~AudioManager();

  enum SynthType {
    AMSynthType = 0,
    FMSynthType,
    Size // 2
  };

  // setters and getters
  int getNumFrequencies();
  bool changeSynth();
  void makeSynth(double samplerate);
  void setWaveform(double samplerate);
  void setFrequency();
  void assignAudioCallback();
  void end();
  // static method because this method does not depend on objects
  static std::string synthTypeToString(SynthType type);

protected:
  int waveformIndex = 0;
  int numFrequencies = 2;
  Oscillator* waveformType[2];
  double frequencies[2]; //30 is max because THX sound
  Synth* synth;
  JackModule* jack;

  bool changeSynth(SynthType synthType);
  void deleteWaveForm();
  void deleteSynth();
};
