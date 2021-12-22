#include "FM.h"

FMSynth::FMSynth(Waveform waveformType, double samplerate) : ModSynth(waveformType, samplerate)
{
  std::cout << "• FMSynth constructor" << std::endl;
  modSynthName = "FM";
  
}

FMSynth::~FMSynth()
{
  std::cout << "• FMSynth destructor" << std::endl;
}

void FMSynth::calculate()
{
  // get first sample
  carrierOsc->nextSample();
  modulatorOsc->nextSample();
  // set the output sample to the modulated waveform
  sample = (carrierOsc->getSample() + modulatorOsc->getSample()) * 0.1;
}
