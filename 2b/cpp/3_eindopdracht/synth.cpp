#include "synth.h"
#include <math.h>

Synth::Synth(Waveform waveformType, double samplerate) : sample(0.0),
  samplerate(samplerate), modRatio(0.1), modDepth(0.25), carAmp(0.25)
{
  std::cout << "\n• Synth::Synth" << std::endl;
  setWaveform(waveformType);
}

Synth::~Synth()
{
  std::cout << "\n• Synth::~Synth" << std::endl;
}


void Synth::tick()
{
  // TODO - make tick virtual and change calculate in subclasses to tick
  calculate();
}


void Synth::setMPitch(float mPitch)
{
  midiPitch = mPitch;
  setFrequency(mtof(mPitch));
}

void Synth::setRatio(double ratio)
{
  modRatio = ratio;
  // re-update modulator frequency
  setModFrequency(mtof(midiPitch));
}



double Synth::mtof(float mPitch)
{
  // source of the mtof calculation:
  // https://www.musicdsp.org/en/latest/Other/125-midi-note-frequency-conversion.html
  return 440.0 * pow(2.0, (mPitch - 57.0f)/12.0f);
}

void Synth::setFrequency(double freq)
{
#if DEBUG >= 1
  std::cout << "• Synth::setFrequency - freq: " << freq << std::endl;
#endif
  // update frequency of modulator and carrier
  setModFrequency(freq);
  carrierFreq = freq;
  carrierOsc->setFrequency(freq);
}

void Synth::setModFrequency(double freq)
{
  // update frequency of modulator and carrier
  float modFrequency = freq * modRatio;
  modulatorOsc->setFrequency(modFrequency);
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
