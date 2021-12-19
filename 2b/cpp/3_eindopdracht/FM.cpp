#include "FM.h"

FMSynth::FMSynth(double samplerate, Waveform oscType, 
    double carFreq, double modFreq) : Synth(samplerate)
{
  // using baseOsc and modulatorOsc instead of creating
  // oscillators dynamically in the constructor
  // for the sake of the example
  std::cout << "• FMSynth constructor" << std::endl;
  synthName = "FMSynth";

  switch (oscType)
  {
    case SineType:
      carrierOsc = new Sine(carFreq, samplerate);
      modulatorOsc = new Sine(modFreq, samplerate);
    break;
    case SawType:
      carrierOsc = new Saw(carFreq, samplerate);
      modulatorOsc = new Saw(modFreq, samplerate);
    break;
    case SquareType:
      carrierOsc = new Square(carFreq, samplerate);
      modulatorOsc = new Square(modFreq, samplerate);
    break;
  default:
    /* code */
    break;
  }

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
