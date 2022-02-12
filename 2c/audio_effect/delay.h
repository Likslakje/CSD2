#include <iostream>
#include "audioEffect.h"


class Delay : public AudioEffect{
    public:
        Delay(unsigned int samplerate);
        ~Delay();
        float samplesToMillis(unsigned int delaySamples);
        void setDelayTime(unsigned int delaySamples);
        float processFrame(float input) override;

    private:
        float delayTime;
};