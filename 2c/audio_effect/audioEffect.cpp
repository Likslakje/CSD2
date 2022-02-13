#include <iostream>
#include "audioEffect.h"

AudioEffect::AudioEffect(){

}

AudioEffect::AudioEffect(unsigned int samplerate, WaveformType waveformType, float modFreq) : samplerate(samplerate){
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

unsigned int AudioEffect::getSamplerate(){
    return samplerate;
}