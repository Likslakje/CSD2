#include <iostream>
#include "audioEffect.h"

class Tremolo : public AudioEffect{
  public:
    Tremolo(unsigned int samplerate, float modDepth = 1.0f, float modFreq = 10.0f, WaveformType waveformType = SINE);
    ~Tremolo();

    // applies tremolo effect to the input frame
    float processFrame(float input) override;

    // set the frequency of the tremolo
    void setModFreq(float modFreq);

  protected:
    unsigned int samplerate = getSamplerate();


    // default modulation frequency range values
    // NOTE: no setters yet
    float m_modFreqMin = 0.01f;
    float m_modFreqMax = 50.0f;
    // modulation depth value
    // NOTE: no validation yet
    float m_modDepth;
    // cache last sample
    float m_sample;
    // modSignal is used during the calculation of the processed frame
    float m_modSignal = 0;
};
