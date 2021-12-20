#include "FM.h"

FMSynth::FMSynth(Oscillator* waveformType[], 
    double frequencies[], double samplerate) : Synth(samplerate)
{
  // using baseOsc and modulatorOsc instead of creating
  // oscillators dynamically in the constructor
  // for the sake of the example
  std::cout << "• FMSynth constructor" << std::endl;
  synthName = "FMSynth";
}

FMSynth::~FMSynth()
{
  std::cout << "• FMSynth destructor" << std::endl;
}

// void FMSynth::setWaveform(Waveform oscType, double frequencies[], double samplerate){
//   // TODO make more modular cuz duplicate code and stuff
//   //something with the OscType enum and then blablabla
//   for(int i = 0; i < numberOsc; i++){
//       switch (oscType)
//     {
//       case SineType:
//         oscillators[i] = new Sine(frequencies[i], samplerate);
//       break;
//       case SawType:
//         oscillators[i] = new Saw(frequencies[i], samplerate);
//       break;
//       case SquareType:
//         oscillators[i] = new Square(frequencies[i], samplerate);
//       break;
//     default:
//       /* code */
//       break;
//     }
//   }
// }

void FMSynth::calculate()
{
  FMWaveforms[0]->nextSample();
  FMWaveforms[1]->nextSample();
  sample = (FMWaveforms[0]->getSample() + FMWaveforms[1]->getSample()) * 0.1;

}
