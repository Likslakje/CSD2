#include <iostream>
#include "waveTable.h"

Wavetable::Wavetable(){

}

Wavetable::Wavetable(unsigned int samplerate, int size, 
  WaveformType waveformType, int freq) :
  samplerate(samplerate), size(size), freq(freq){
  std::cout<< "constructor WaveTable" <<std::endl;

  circBuf = new CircBuf(size);
  selectWaveform(waveformType);
  wavetableSamplerate = calcWavetableSamplerate(samplerate, freq);

  //this function is executed in the contructor
  //because we only need to get one cycle, once
  for(int i = 0; i < samplerate / freq; i++){
    oscToWavetable();
  }
}

Wavetable::~Wavetable(){
  std::cout<< "~destructor WaveTable" <<std::endl;
  delete circBuf;
  circBuf = nullptr;
  delete osc;
  osc = nullptr;
}

void Wavetable::selectWaveform(WaveformType waveformType){
  switch (waveformType){
    case WaveformType::SINE:{
      osc = new Sine(freq, samplerate);
      break;
    }
    case WaveformType::SAW:{
      osc = new Saw(freq, samplerate);
      break;
    }
    case WaveformType::SQUARE:{
      // TODO: alter calculation of to create a non-aliasing square,
      // similar to the calculation within the Saw class
      osc = new Square(freq, samplerate);
      break;
    }
    default:
      throw "Wavetable::Wavetable incorrect waveformType.";
      break;
  }
}


unsigned int Wavetable::calcWavetableSamplerate(unsigned int samplerate, int freq){
  // x cycles of freq in 44100 samples
  // x samples is one cycle
  // interval between sample points depending on table size
  // sizeTable is an int so everything is casted to intergers
  // this is suppost to happen because we can not take samples in between samples...
  return (samplerate / freq) / size;
}

void Wavetable::oscToWavetable(){
  //stop writing to the buffer after the buffer had been filled once
  //this is not needed anymore sinds we can make a complete
  //wavefrom at the given frequency with just one cycle
  float sample = osc->genNextSample();
  if(samplerateWriteCount >= wavetableSamplerate){
    if(writeCount < size){
      circBuf->writeToBuf(sample);
      writeCount++;
    }
      samplerateWriteCount = 0;
  }else{
    samplerateWriteCount++;
  }
}

float Wavetable::getSampWavetable(){
  //the readhead will return the same sample as many times
  //as the interval (aka downsampling)
  if(wavetableSamplerate < samplerateReadCount){
    sample = circBuf->readFromBuf();
    samplerateReadCount = 0;
    return sample;
  }else{
    samplerateReadCount++;
  }
  return sample;
}

