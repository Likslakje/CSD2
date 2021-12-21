#include "AM.h"

AMSynth::AMSynth(Waveform waveformType, double carrierFreq,
    double modulatorFreq, double samplerate) : Synth(waveformType,
    carrierFreq, modulatorFreq, samplerate)
{
  std::cout << "• AMSynth constructor" << std::endl;
}

AMSynth::~AMSynth()
{
  std::cout << "• AMSynth destructor" << std::endl;
}

void AMSynth::calculate()
{
  //got to the next sample
  //then get the frequency of the modulator wave and make its range fit the amplitude range
  //then set the amplitude of the carrier
  //retrun the result (= sample)
  #if 0
    carrierOsc->nextSample();
    modulatorOsc->nextSample();
    double newAmplitude = (modulatorOsc->getSample() * 0.5) + 0.5;
    carrierOsc->setAmplitude(newAmplitude);
    sample = carrierOsc->getSample();
  #else
    carrierOsc->nextSample();
    modulatorOsc->nextSample();
    double newAmplitude = (modulatorOsc->getSample() * 0.5) + 0.5;
    carrierOsc->setAmplitude(newAmplitude);
    sample = carrierOsc->getSample();
  #endif
}
