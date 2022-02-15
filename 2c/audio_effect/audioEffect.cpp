#include <iostream>
#include "audioEffect.h"

AudioEffect::AudioEffect(){

}

AudioEffect::AudioEffect(unsigned int samplerate, float dryWet, 
  bool bypass) : samplerate(samplerate), dryWet(dryWet),
  bypass(bypass){
  std::cout<< "contructor AudioEffect" <<std::endl;

}

AudioEffect::~AudioEffect(){
  std::cout<< "~destructor AudioEffect" <<std::endl;
  // release dynamically allocated oscillator object.
  delete osc;
  osc = nullptr;
}

void AudioEffect::selectWaveform(Oscillator::WaveformType waveformType){
  switch (waveformType){
    case Oscillator::WaveformType::SINE:{
      osc = new Sine(modFreq, samplerate);
      break;
    }
    case Oscillator::WaveformType::SAW:{
      osc = new Saw(modFreq, samplerate);
      break;
    }
    case Oscillator::WaveformType::SQUARE:{
      // TODO: alter calculation of to create a non-aliasing square,
      // similar to the calculation within the Saw class
      osc = new Square(modFreq, samplerate);
      break;
    }
    default:
      throw "AudioEffect::AudioEffect incorrect waveformType.";
      break;
  }
}

Oscillator* AudioEffect::getOscillator(){
  return osc;
}

void AudioEffect::selectBuffer(CircBuf::BufferSizeType bufferType){
  //select the buffer size from enum
  switch (bufferType){
    case CircBuf::BufferSizeType::SHORT:{
      int size = 2 * samplerate;
      circBuf = new CircBuf(samplerate, size);
      break;
    }
    case CircBuf::BufferSizeType::MID:{
      int size = 5 * samplerate;
      circBuf = new CircBuf(samplerate, size);
      break;
    }
    case CircBuf::BufferSizeType::LONG:{
      int size = 10 * samplerate;
      circBuf = new CircBuf(samplerate, size);
      break;
    }
    default:
      //a modderfokking starwars reference
      throw "if an item does not appear in our records, it does not exist";
      break;
  }
}

CircBuf* AudioEffect::getBufferType(){
  return circBuf;
}

float AudioEffect::getEffectedSample(float directInput){
  //apply the effect to the sample
  float effectOutput = applyEffect(directInput);
  //set the gain of the dry and wet signal
  directInput *= dryWet;
  effectOutput *= (1 - dryWet);
  //sum them up together
  float effectedSample = directInput + effectOutput;
  return effectedSample;
}
