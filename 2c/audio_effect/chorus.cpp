#include <iostream>
#include "chorus.h"

Chorus::Chorus(unsigned int samplerate, float dryWet, 
  bool bypass, float modDepth, float delayTimeL, float delayTimeR, 
  float feedback, Modulation::WaveformType waveformType, 
  float modFreq) : modDepth(modDepth){
  std::cout<< "contructor Chorus" <<std::endl;

  delayLineL = new Delay(samplerate, dryWet, bypass, 
    Delay::BufferSizeType::SHORT, delayTimeL, feedback);
  delayLineR = new Delay(samplerate, dryWet, bypass, 
    Delay::BufferSizeType::SHORT, delayTimeR, feedback);
  modWaveform = new Modulation(samplerate, 1, bypass, waveformType, 
    modFreq);

  effectedSample = new float[2];
}

Chorus::~Chorus(){
  std::cout<< "~destructor Chorus" <<std::endl;
  //delete those bitches cus we dont need them hoes anymore
  delete delayLineL;
  delayLineL = nullptr;
  delete delayLineR;
  delayLineR = nullptr;
  delete modWaveform;
  modWaveform = nullptr;
  delete [] effectedSample;
  effectedSample = nullptr;
}

float* Chorus::applyEffect(float input){
  if (bypass == false){
    Oscillator* osc = modWaveform->getOscillator();
    CircBuf* circBufL = delayLineL->getCircBuf();
    CircBuf* circBufR = delayLineR->getCircBuf();
    //1 sample = ? seconds?
    //44100 samps = 1 sec
    //44,1 samps = 1 ms
    //1 samp = 1000/samplerate 
    //get a sample, take it to the time domain, the size (in ms) depends
    // on the modDepth
    osc->genNextSample() * ((1000/samplerate) * modDepth);
    //cast oscilator to an int cuz its used as an index
    circBufL->setModulation((int)osc * (int)modDepth);
    circBufR->setModulation((int)osc * (int)modDepth);
  
    effectedSample[0] = delayLineL->applyEffect(input);
    effectedSample[1] = delayLineR->applyEffect(input);
  }else{
    effectedSample = &input;
  }
  return effectedSample;
}