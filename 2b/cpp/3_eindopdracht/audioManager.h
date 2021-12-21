#pragma once
#include <iostream>
#include "jack_module.h"
// TODO - use interface SelectionUtil instead!
#include "userInput.h"
#include "synth.h"
#include "melody.h"


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
  void updatePitch(Melody* melody, Synth* synthType);
  void assignAudioCallback();
  void end();
  // static method because this method does not depend on objects
  static std::string synthTypeToString(SynthType type);

protected:
  SynthType synthType;
  Melody* melody;
  Synth* synth;
  JackModule* jack;
  double samplerate;

  bool changeSynth(SynthType synthType);
  void deleteSynth();
};
