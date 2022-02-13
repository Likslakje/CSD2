#include "tremolo.h"

Tremolo::Tremolo(unsigned int samplerate, float modDepth, float modFreq,
  WaveformType waveformType) : AudioEffect(samplerate, waveformType, modFreq), m_modDepth(m_modDepth){
  std::cout<< "constructor Tremolo" <<std::endl;
}

Tremolo::~Tremolo(){
  std::cout<< "~destructor Tremolo" <<std::endl;
}

float Tremolo::processFrame(float input){
  // transform sine in range [-1, 1] to range [0, 1]
  m_modSignal  = osc->genNextSample() * 0.5 + 0.5;
  // apply modDepth
  m_modSignal *= m_modDepth;
  m_modSignal += 1.0 - m_modDepth;
  // apply modulation signal to input
  m_sample = input * m_modSignal;
  return m_sample;
}

void Tremolo::setModFreq(float modFreq){
  if(modFreq >= m_modFreqMin && modFreq <= m_modFreqMax) {
    osc->setFrequency(modFreq);
  } else {
    std::cout << "• Tremelo::setModFreq - modFreq is incorrect"
      << " please pass value between " << m_modFreqMin << " and " << m_modFreqMax
      << std::endl;
  }
}
