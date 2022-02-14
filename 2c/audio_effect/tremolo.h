#include <iostream>
#include "audioEffect.h"

class Tremolo : public AudioEffect{
  public:
    Tremolo(unsigned int samplerate, WaveformType waveformType,
      float modFreq, float ratio);
    ~Tremolo();
    // applies tremolo effect to the input frame
    float applyEffect(float input) override;

    // set the frequency of the tremolo
    void setModFreq(float modFreq);

  protected:
    // default modulation frequency range values
    // NOTE: no setters yet
    float modFreqMin = 0.01f;
    float modFreqMax = 50.0f;
    // modulation depth value
    // NOTE: no validation yet
    // cache last sample
    float sample;
    // modSignal is used during the calculation of the processed frame
    float modSignal = 0;
};
