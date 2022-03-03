#include <iostream>
#include "waveTable.h"

Wavetable::Wavetable(){

}

Wavetable::Wavetable(unsigned int samplerate, int size, 
  WaveformType waveformType, int freq) :
  samplerate(samplerate), size(size), freq(freq){
  std::cout<< "constructor WaveTable" <<std::endl;

  buffer = (float*) malloc (size * sizeof(float));
  memset(buffer, 0, size * sizeof(float));

  selectWaveform(waveformType);

  //this function is executed in the constructor
  //because we only need to get one cycle, once
  oneCycle = samplerate / freq;
  // x cycles of freq in 44100 samples
  // x samples is one cycle
  // interval between sample points depending on table size
  // sizeTable is an int so everything is casted to intergers
  // this is suppost to happen because we can not take samples in between samples...
  wavetableSamplerate = oneCycle / size;
  std::cout<< "oneCycle " << oneCycle <<std::endl;
  std::cout<< "wavetableSamplerate " << wavetableSamplerate <<std::endl;
  // std::cout<< "oneCycle "<< oneCycle <<std::endl;
  for(int i = 0; i < oneCycle; i++){
    // std::cout<< "in forloop "<<std::endl;
    oscToWavetable();
  }
}

Wavetable::~Wavetable(){
  std::cout<< "~destructor WaveTable" <<std::endl;
  delete buffer;
  buffer = nullptr;
  free(buffer);
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


void Wavetable::oscToWavetable(){
  //stop writing to the buffer after the buffer had been filled once
  //this is not needed anymore sinds we can make a complete
  //wavefrom at the given frequency with just one cycle
  float sample = osc->genNextSample();
  if(writeCount > wavetableSamplerate){
    //buffer[++bufferWriteIndex] cus you want your wave to start at 0
    buffer[++bufferWriteIndex] = sample;
    writeCount = 0;
  }else{
    writeCount++;
  }
  std::cout<< buffer[bufferWriteIndex] <<std::endl;
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
  std::cout<< buffer[bufferReadIndex] <<std::endl;
  return buffer[bufferReadIndex];
}


