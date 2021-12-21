#include "synth.h"

Synth::Synth(double samplerate) : sample(0.0), samplerate(samplerate)
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

double mtof(float mPitch)
{
  // source of the mtof calculation:
  // https://www.musicdsp.org/en/latest/Other/125-midi-note-frequency-conversion.html
  return 440.0 * pow(2.0, (mPitch - 57.0f)/12.0f);
}

double Synth::getSample() { return sample; }

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
