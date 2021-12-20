#include "AM.h"

AMSynth::AMSynth(Oscillator* waveformType[], 
  double frequencies[], double samplerate) : Synth(samplerate)
{
  // using modulatorOsc and carrierOsc instead of creating
  // oscillators dynamically in the constructor
  // for the sake of the example
  this->AMWaveforms = waveformType;
  synthName = "AMSynth";
  std::cout << "• AMSynth constructor" << std::endl;
  // for(int i = 0; i < 2; i++){
  //   setWaveform(waveformType, frequencies, samplerate);
  //   std::cout<< frequencies[i] <<std::endl;
  // }
}

AMSynth::~AMSynth()
{
  std::cout << "• AMSynth destructor" << std::endl;
}

// void AMSynth::setWaveform(Oscillator* waveformType[], double frequencies[], double samplerate){
//   // TODO make more modular cuz duplicate code and stuff
//   //something with the OscType enum and then blablabla
//     switch (waveformType)
//   {
//     case SineType:
//       oscillators[oscIndex] = new Sine(frequencies[oscIndex], samplerate);
//     break;
//     case SawType:
//       oscillators[oscIndex] = new Saw(frequencies[oscIndex], samplerate);
//     break;
//     case SquareType:
//       oscillators[oscIndex] = new Square(frequencies[oscIndex], samplerate);
//     break;
//   default:
//     /* code */
//     break;
//   }
// }

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
    AMWaveforms[0]->nextSample();
    AMWaveforms[1]->nextSample();
    double newAmplitude = (AMWaveforms[1]->getSample() * 0.5) + 0.5;
    AMWaveforms[0]->setAmplitude(newAmplitude);
    sample = AMWaveforms[0]->getSample();
  #endif
}
