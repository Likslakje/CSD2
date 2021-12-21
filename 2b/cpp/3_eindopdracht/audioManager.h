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
  bool changeSynth();

  void assignAudioCallback();
  void end();
  // static method because this method does not depend on objects
  static std::string synthTypeToString(SynthType type);
  void setFrequencies();

protected:
  SynthType synthType;
  Synth* synth;
  JackModule* jack;

  bool changeSynth(SynthType synthType);
  void deleteSynth();
};
