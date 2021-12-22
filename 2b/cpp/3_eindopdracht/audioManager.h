//All credits for AudioManger go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/taylorSwift/csd2b/theorie/xx_eindopdrachtExamples/07_choicesSynth

#pragma once
#include <iostream>
#include "jack_module.h"
#include "userInput.h"
#include "modSynth.h"
#include "melody.h"

class AudioManager
{
public:
  AudioManager();
  ~AudioManager();

  //The possible synthtypes are choosen from enum 
  enum SynthType {
    AMSynthType = 0,
    FMSynthType,
    Size // 2
  };

  // setters and getters
  void makeMelody();
  void setMelody();
  bool changeSynth();
  void updatePitch();
  void assignAudioCallback();
  void end();
  // static method because this method does not depend on objects
  static std::string synthTypeToString(SynthType type);

protected:
  //objects
  SynthType synthType;
  Melody melody;
  //Create choosen synthType from enum dynamically
  ModSynth* modSynth;
  JackModule* jack;
  //var
  double samplerate;
  double masterAmp;
  int frameIndex;
  int frameInterval;

  //protected cuz does not need to be accessed
  bool changeSynth(SynthType synthType);
  void deleteSynth();
};
