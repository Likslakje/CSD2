#include <iostream>
#include "waveTable.h"

Wavetable::Wavetable(){

}

Wavetable::Wavetable(unsigned int samplerate, int size, 
  WaveformType waveformType, int freq) :
  samplerate(samplerate), size(size), freq(freq){
  std::cout<< "constructor WaveTable" <<std::endl;

  buffer = new float(size);
  for(int i = 0; i < size; i++){
    buffer[i] = 0;
    // std::cout<< "initialize " << buffer[i] <<std::endl;
  }


  selectWaveform(waveformType);
  wavetableSamplerate = calcWavetableSamplerate(samplerate, freq);

  // std::cout<< "before forloop "<<std::endl;
  //this function is executed in the constructor
  //because we only need to get one cycle, once
  // std::cout<< "freq "<< freq <<std::endl;
  // std::cout<< "samplerate "<< samplerate <<std::endl;
  int oneCycle = samplerate / freq;
  // std::cout<< "oneCycle "<< oneCycle <<std::endl;
  for(int i = 0; i < oneCycle; i++){
    // std::cout<< "in forloop "<<std::endl;
    oscToWavetable();
  }

  // for(int i = 0; i < size; i++){
  //   std::cout<< "afterWrite  " << buffer[i] <<std::endl;
  // }
}

Wavetable::~Wavetable(){
  std::cout<< "~destructor WaveTable" <<std::endl;
  delete buffer;
  buffer = nullptr;
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
  return (unsigned int)(samplerate / freq) / size;
}

void Wavetable::oscToWavetable(){
  //stop writing to the buffer after the buffer had been filled once
  //this is not needed anymore sinds we can make a complete
  //wavefrom at the given frequency with just one cycle
  float sample = osc->genNextSample();
  // std::cout<< "sample " << sample <<std::endl;
  // std::cout<< "wavetablesR  " << wavetableSamplerate <<std::endl;
  // std::cout<< "writeCpunt  " << writeCount <<std::endl;
  // std::cout<< "bufferWriteIndex  " << bufferWriteIndex <<std::endl;
  if(writeCount > wavetableSamplerate){
    buffer[bufferWriteIndex++] = sample;
    writeCount = 0;
    // bufferWriteIndex++;
  }else{
    writeCount++;
  }
}

float Wavetable::getSampWavetable(){
  //wrap that bitch
  if(bufferReadIndex > size){
    bufferReadIndex = 0;
  }else{
    //read the same sample depending on the samplerate
    if(readCount > wavetableSamplerate){
      bufferReadIndex++;
      readCount = 0;
    }else{
      readCount++;
    }
  }
    return buffer[bufferReadIndex];
}


