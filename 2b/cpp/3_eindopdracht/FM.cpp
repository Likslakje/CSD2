#include "FM.h"

FMSynth::FMSynth(Waveform waveformType, double samplerate) : Synth(samplerate)
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
      modulatorOsc = new Sine(220, samplerate);
      carrierOsc = new Sine(225, samplerate);
    break;
    case SawType:
      modulatorOsc = new Saw(220, samplerate);
      carrierOsc = new Saw(225, samplerate);
    break;
    case SquareType:
      modulatorOsc = new Square(220, samplerate);
      carrierOsc = new Square(225, samplerate);
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
