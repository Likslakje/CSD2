#include <iostream>
#include "audioEffect.h"


class Delay : public AudioEffect{
    public:
        Delay(unsigned int samplerate, WaveformType waveformType,
      float modFreq, float ratio);
        ~Delay();
        float samplesToMillis(unsigned int delaySamples);
        void setDelayTime(unsigned int delaySamples);
        float applyEffect(float input) override;

    private:
        float delayTime;
};