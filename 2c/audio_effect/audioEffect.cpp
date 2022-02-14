#include <iostream>
#include "audioEffect.h"

AudioEffect::AudioEffect(){

}

AudioEffect::AudioEffect(unsigned int samplerate, WaveformType waveformType, 
    float modFreq, float ratio) : samplerate(samplerate), modFreq(modFreq),
    ratio(ratio){
  std::cout<< "contructor AudioEffect" <<std::endl;
  switch (waveformType){
    case WaveformType::SINE:
    {
        osc = new Sine(modFreq, samplerate);
        break;
    }
    case WaveformType::SAW:
    {
        osc = new Saw(modFreq, samplerate);
        break;
    }
    case WaveformType::SQUARE:
    {
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

AudioEffect::~AudioEffect(){
  std::cout<< "~destructor AudioEffect" <<std::endl;
  // release dynamically allocated oscillator object.
  delete osc;
  osc = nullptr;
}

void AudioEffect::calcDryWet(float ratio){
    drySig = ratio;
    wetSig = 1 - ratio;
}

float AudioEffect::getDrySig(){
    return drySig;
}

float AudioEffect::getWetSig(){
    return wetSig;
}

float AudioEffect::getEffectedSample(float directInput){
    float effectOutput = applyEffect(directInput);
    //dry * luidheid + wet(get from effect) * luidheid
    //set the amplitude of the dry signal
    directInput *= drySig;
    // set amplitude of wet signal
    effectOutput *= wetSig;
    float effectedSample = directInput + effectOutput;
    return effectedSample;
}

Oscillator* AudioEffect::getOscillator(){
    return osc;
}