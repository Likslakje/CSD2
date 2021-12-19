#include "AM.h"

AMSynth::AMSynth(double samplerate, Waveform oscType, 
  double carFreq, double modFreq) : Synth(samplerate)
{
  // using modulatorOsc and carrierOsc instead of creating
  // oscillators dynamically in the constructor
  // for the sake of the example

  synthName = "AMSynth";
  std::cout << "• AMSynth constructor" << std::endl;

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

AMSynth::~AMSynth()
{
  std::cout << "• AMSynth destructor" << std::endl;
}

void AMSynth::calculate()
{
  //amp van modulatorosc op carrierosc
  carrierOsc->nextSample();
  modulatorOsc->nextSample();
  double newAmplitude = (modulatorOsc->getSample() * 0.5) + 0.5;
  carrierOsc->setAmplitude(newAmplitude);
  sample = carrierOsc->getSample();
}
