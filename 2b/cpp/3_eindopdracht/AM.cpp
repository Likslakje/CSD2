#include "AM.h"

AMSynth::AMSynth(Waveform waveformType, double samplerate) :
  ModSynth(waveformType, samplerate)
{
  #if DEBUG >= 1
  std::cout << "• AMSynth constructor" << std::endl;
  #endif
  modSynthName = "AM";

}

AMSynth::~AMSynth()
{
  #if DEBUG >= 1
  std::cout << "• AMSynth destructor" << std::endl;
  #endif
}

void AMSynth::calculate()
{
  // get the first sample
  modulatorOsc->nextSample();
  //getsample * modDepth + carAmp
  double modulatedAmp = (modulatorOsc->getSample() * modDepth) + carAmp;
  // TODO use modulated amplitude
  // set the amplitude of the carier with the modulator
  carrierOsc->setAmplitude(modulatedAmp);
  // go to next sample
  carrierOsc->nextSample();
  // set sample to mudalated waveform
  sample = carrierOsc->getSample();
}
