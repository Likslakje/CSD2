//All credits for AudioManger go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/taylorSwift/csd2b/theorie/xx_eindopdrachtExamples/07_choicesSynth

#pragma once
#include <iostream>
#include "userInput.h"
#include "../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/utilities/jack_module.h"
#include "../../CSD2_pull_voorbeelden/CSD_21-22/csd2c/sharedCode/utilities/writeToFile.h"
#include "../2c/audio_effect/simpleDelay.h"
#include "../2c/audio_effect/tremolo.h"

class AudioManager
{
public:
  //The possible synthtypes are choosen from enum
  enum EffectType {
    TREMOLO = 0,
    SIMPLEDELAY,
    SIZE, // 2s
    NONE
  };
  AudioManager(char **argv);
  ~AudioManager();
  static std::string effectEnumToString(EffectType type);
  std::string waveformEnumToString(Modulation::WaveformType waveform);
  std::string delayTimeEnumToString(Delay::BufferSizeType delayTime);
  Modulation::WaveformType waveformTypeSelection();
  Delay::BufferSizeType delayTimeSelection();
  float setModFreq();
  float setDelayTime();
  void assignAudioCallback();
  void makeEffect();

protected:
  float amplitude = 0.5;
  JackModule* jack;
  Tremolo* tremolo;
  SimpleDelay* simpeleDelay;
  //var
  double samplerate;
  double masterAmp;
  int frameIndex;
  int frameInterval;

  EffectType effect;
};
