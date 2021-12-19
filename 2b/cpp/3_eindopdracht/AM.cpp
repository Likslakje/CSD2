#include "AM.h"

AMSynth::AMSynth(double samplerate, Waveform oscType, 
  double carFreq, double modFreq) : Synth(samplerate)
{
  // using modulatorOsc and carrierOsc instead of creating
  // oscillators dynamically in the constructor
  // for the sake of the example

  synthName = "AMSynth";
  std::cout << "• AMSynth constructor" << std::endl;
  setWaveform(oscType, carFreq, modFreq, samplerate);

  // switch (oscType)
  // {
  //   case SineType:
  //     carrierOsc = new Sine(carFreq, samplerate);
  //     modulatorOsc = new Sine(modFreq, samplerate);
  //   break;
  //   case SawType:
  //     carrierOsc = new Saw(carFreq, samplerate);
  //     modulatorOsc = new Saw(modFreq, samplerate);
  //   break;
  //   case SquareType:
  //     carrierOsc = new Square(carFreq, samplerate);
  //     modulatorOsc = new Square(modFreq, samplerate);
  //   break;
  // default:
  //   /* code */
  //   break;
  // }
}

AMSynth::~AMSynth()
{
  std::cout << "• AMSynth destructor" << std::endl;
}

void AMSynth::setWaveform(Waveform oscType, double carFreq, 
  double modFreq, double samplerate){
  // TODO make more modular cuz duplicate code and stuff
  //something with the OscType enum and then blablabla
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

void AMSynth::calculate()
{
  //got to the next sample
  //then get the frequency of the modulator wave and make its range fit the amplitude range
  //then set the amplitude of the carrier
  //retrun the result (= sample)
  carrierOsc->nextSample();
  modulatorOsc->nextSample();
  double newAmplitude = (modulatorOsc->getSample() * 0.5) + 0.5;
  carrierOsc->setAmplitude(newAmplitude);
  sample = carrierOsc->getSample();
}
