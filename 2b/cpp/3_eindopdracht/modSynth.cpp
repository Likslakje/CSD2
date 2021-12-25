#include "modSynth.h"
#include <math.h>

ModSynth::ModSynth(Waveform waveformType, double samplerate) : sample(0.0),
  samplerate(samplerate), modRatio(0.1), modDepth(0.25), carAmp(0.25)
{
  std::cout << "\n• ModSynth::ModSynth" << std::endl;
  setWaveform(waveformType);
}

ModSynth::~ModSynth()
{
  std::cout << "\n• ModSynth::~ModSynth" << std::endl;
}


void ModSynth::tick()
{
  // TODO - make tick virtual and change calculate in subclasses to tick
  calculate();
}


void ModSynth::setMPitch(float mPitch)
{
  // get the pitch as a midinumber
  // use the mtof function to convert it to a frequency
  // then pass it to the oscillators
  midiPitch = mPitch;
  setFrequency(mtof(mPitch));
}

void ModSynth::setRatio(double ratio)
{
  // get the ratio
  // use the mtof function to convert it to a frequency
  // then pass it to the oscillators
  modRatio = ratio;
  // re-update modulator frequency
  setModFrequency(mtof(midiPitch));
}



double ModSynth::mtof(float mPitch)
{
  // source of the mtof calculation:
  // https://www.musicdsp.org/en/latest/Other/125-midi-note-frequency-conversion.html
  return 440.0 * pow(2.0, (mPitch - 57.0f)/12.0f);
}

void ModSynth::setFrequency(double freq)
{
#if DEBUG >= 1
  std::cout << "• ModSynth::setFrequency - freq: " << freq << std::endl;
#endif
  // update frequency of modulator and carrier
  setModFrequency(freq);
  carrierFreq = freq;
  carrierOsc->setFrequency(freq);
}

void ModSynth::setModFrequency(double freq)
{
  // update frequency of modulator and carrier
  float modFrequency = freq * modRatio;
  modulatorOsc->setFrequency(modFrequency);
}

double ModSynth::getSample(){
  return sample;
}

void ModSynth::setWaveform(Waveform waveformType){
  // create the carrier and modulators for the selected oscillator type
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
    case TriangleType:
      modulatorOsc = new Triangle(modulatorFreq, samplerate);
      carrierOsc = new Triangle(carrierFreq, samplerate);
  default:
    /* code */
    break;
  }
}

std::string ModSynth::waveformTypeToString(Waveform type)
{
  // return the selected ModSynthType as string
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
