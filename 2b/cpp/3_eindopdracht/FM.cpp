#include "FM.h"

FMSynth::FMSynth(Waveform waveformType, double samplerate) : ModSynth(waveformType, samplerate)
{
  #if DEBUG >= 1
  std::cout << "• FMSynth constructor" << std::endl;
  #endif
  modSynthName = "FM";
  
}

FMSynth::~FMSynth()
{
  #if DEBUG >= 1
  std::cout << "• FMSynth destructor" << std::endl;
  #endif
}

void FMSynth::calculate()
{
  // get first sample
  carrierOsc->nextSample();
  modulatorOsc->nextSample();
  // set the output sample to the modulated waveform
  sample = (carrierOsc->getSample() + modulatorOsc->getSample()) * 0.2;
}
