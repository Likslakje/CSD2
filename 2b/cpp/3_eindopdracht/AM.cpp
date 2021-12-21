#include "AM.h"

AMSynth::AMSynth(Waveform waveformType, double carrierFreq, 
    double modulatorFreq, double samplerate) : Synth(carrierFreq, modulatorFreq, samplerate)
{
  std::cout << "• AMSynth constructor" << std::endl;
  // synthName = "AMSynth";
  setWaveform(waveformType);
}

AMSynth::~AMSynth()
{
  std::cout << "• AMSynth destructor" << std::endl;
}

void AMSynth::setWaveform(Waveform waveformType){
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
