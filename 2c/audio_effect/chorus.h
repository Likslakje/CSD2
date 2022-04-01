#include <iostream>
#include "delay.h"
#include "modulation.h"

class Chorus : public AudioEffect{
  public:
  //Chorus doesn't need buffersize cus it becomes a pingpong delay
    Chorus(unsigned int samplerate, float dryWet, 
      bool bypass, float modDepth, float delayTimeL, float delayTimeR,
      float feedback, Modulation::WaveformType waveformType, 
      float modFreq);
    ~Chorus();
  // protected:
    float* applyEffect(float input) override final;
  protected:
    //2x circbuf
    //interleaved outbuffer
    //2x lfo rate
    //waveform
    //interleaved buffer
    float* effectedSample;
    float modDepth;
    Delay* delayLineL;
    Delay* delayLineR;
    Modulation* modWaveform;
};