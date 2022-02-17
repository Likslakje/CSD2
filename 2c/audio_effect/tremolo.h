#include <iostream>
#include "audioEffect.h"
#include "modulation.h"

class Tremolo : public Modulation{
  public:
    Tremolo(unsigned int samplerate, float dryWet, 
    bool bypass, WaveformType waveformType, float modFreq);
    ~Tremolo();
    // applies tremolo effect to the input frame
    float applyEffect(float input) override;

  protected:
};
