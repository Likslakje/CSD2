#include "FM.h"

FMSynth::FMSynth(Waveform waveformType, double carrierFreq, 
    double modulatorFreq, double samplerate) : Synth(waveformType, 
    carrierFreq, modulatorFreq, samplerate)
{
  // using baseOsc and modulatorOsc instead of creating
  // oscillators dynamically in the constructor
  // for the sake of the example
  std::cout << "• FMSynth constructor" << std::endl;
  // synthName = "FMSynth";
  
}

FMSynth::~FMSynth()
{
  std::cout << "• FMSynth destructor" << std::endl;
}

void FMSynth::calculate()
{
  carrierOsc->nextSample();
  modulatorOsc->nextSample();
  sample = (carrierOsc->getSample() + modulatorOsc->getSample()) * 0.1;

}
