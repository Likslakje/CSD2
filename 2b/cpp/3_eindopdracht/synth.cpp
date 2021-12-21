#include "synth.h"
#include <math.h>

Synth::Synth(Waveform waveformType, double carrierFreq, double modulatorFreq,
  double samplerate) : sample(0.0), carrierFreq(carrierFreq),
    modulatorFreq(modulatorFreq), samplerate(samplerate)
{
  std::cout << "\n• Synth::Synth" << std::endl;

}

Synth::~Synth()
{
  std::cout << "\n• Synth::~Synth" << std::endl;
}


void Synth::tick()
{
  calculate();
}

double Synth::mtof(float mPitch)
{
  // source of the mtof calculation:
  // https://www.musicdsp.org/en/latest/Other/125-midi-note-frequency-conversion.html
  return 440.0 * pow(2.0, (mPitch - 57.0f)/12.0f);
}

void Synth::setFrequency(double freq){
  this->carrierFreq = freq;
}

double Synth::getSample(){
  return sample;
}

void Synth::setWaveform(Waveform waveformType){
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

std::string Synth::waveformTypeToString(Waveform type)
{
  switch(type) {
    case Waveform::SineType:
      return "sine";
    case Waveform::SawType:
      return "saw";
    case Waveform::SquareType:
      return "square";
    case Waveform::TriangleType:
      return "triangle";
    default:
      return "Invalid waveform";
  }
}
