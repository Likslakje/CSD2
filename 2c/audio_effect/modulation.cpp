 #include <iostream>
#include "modulation.h"

Modulation::Modulation(unsigned int samplerate, float dryWet, 
    bool bypass, WaveformType waveformType, float modFreq) : 
  modFreq(modFreq), AudioEffect(samplerate, dryWet, bypass){
  #if DEBUG > 0
    std::cout<< "contructor Modulation" <<std::endl;
  #endif
  //create oscillator object dynamicly
  selectWaveform(waveformType);
}

Modulation::~Modulation(){
  #if DEBUG > 0
    std::cout<< "~destructor Modulation" <<std::endl;
  #endif
  // release dynamically allocated oscillator object.
  delete osc;
  osc = nullptr;
}

void Modulation::selectWaveform(WaveformType waveformType){
  switch (waveformType){
    case WaveformType::SINE:{
      std::cout<< "osc " << modFreq <<std::endl;
      std::cout<< "osc " << samplerate <<std::endl;
      osc = new Sine(modFreq, samplerate);
      break;
    }
    case WaveformType::SAW:{
      osc = new Saw(modFreq, samplerate);
      break;
    }
    case WaveformType::SQUARE:{
      // TODO: alter calculation of to create a non-aliasing square,
      // similar to the calculation within the Saw class
      osc = new Square(modFreq, samplerate);
      break;
    }
    default:
      throw "Modulaton::Modulation incorrect waveformType.";
      break;
  }
}

float Modulation::applyEffect(float input){
  float effectedSample;
  // transform sine in range [-1, 1] to range [0, 1]
  float modSignal = osc->genNextSample() * 0.5 + 0.5;
  //forloop cus maybe more channels
  // apply modulation signal to input
  effectedSample = input * (modSignal * dryWet);effectedSample = input;
  #if DEBUG > 2
    std::cout<< "Tremolo::Tremolo effectedSample: " << effectedSample <<std::endl;
  #endif
  return effectedSample;
}