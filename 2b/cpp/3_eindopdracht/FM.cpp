#include "FM.h"

FMSynth::FMSynth(Waveform waveformType, double carrierFreq, 
    double modulatorFreq, double samplerate) : Synth(carrierFreq, modulatorFreq, samplerate)
{
  // using baseOsc and modulatorOsc instead of creating
  // oscillators dynamically in the constructor
  // for the sake of the example
  std::cout << "• FMSynth constructor" << std::endl;
  // synthName = "FMSynth";
  setWaveform(waveformType);
  
}

FMSynth::~FMSynth()
{
  std::cout << "• FMSynth destructor" << std::endl;
}

void FMSynth::setWaveform(Waveform waveformType){
  // TODO make more modular cuz duplicate code and stuff
  //something with the OscType enum and then blablabla
  switch (waveformType)
  {
    case SineType:
      modulatorOsc = new Sine(modulatorFreq, samplerate);
      carrierOsc = new Sine(carrierFreq, samplerate);
    break;
    case SawType:
      modulatorOsc = new Saw(modulatorFreq, samplerate);
      carrierOsc = new Saw(carrierFreq, samplerate);
    break;
    case SquareType:
      modulatorOsc = new Square(modulatorFreq, samplerate);
      carrierOsc = new Square(carrierFreq, samplerate);
    break;
  default:
    /* code */
    break;
  }
}

void FMSynth::calculate()
{
  carrierOsc->nextSample();
  modulatorOsc->nextSample();
  sample = (carrierOsc->getSample() + modulatorOsc->getSample()) * 0.1;

}
