#include <iostream>
#include "waveTable.h"

Wavetable::Wavetable(unsigned int samplerate, int sizeTable, int freq) : 
  sizeTable(sizeTable){
  std::cout<< "constructor WaveTable" <<std::endl;

  wavetable = new float(sizeTable);
  for(int i = 0; i < sizeTable; i++){
    wavetable[i] = 0;
  }

  wavetableSamplerate = calcWavetableSamplerate(samplerate, freq);
}

Wavetable::~Wavetable(){
  std::cout<< "~destructor WaveTable" <<std::endl;
  delete [] wavetable;
  wavetable = nullptr;
}

float Wavetable::getWavetableAtIndex(){
  if(readWavetableIndex > sizeTable){
    readWavetableIndex = 0;
    return wavetable[readWavetableIndex];
  }else{
    // std::cout<< wavetable[readWavetableIndex++] <<std::endl;
    return wavetable[readWavetableIndex++];
  };
}

unsigned int Wavetable::calcWavetableSamplerate(unsigned int samplerate, int freq){
  // x cycles of freq in 44100 samples
  // x samples is one cycle
  // interval between sample points depending on table size
  // sizeTable is an int so everything is casted to intergers
  // this is suppost to happen because we can not take samples in between samples...
  return (samplerate / freq) / sizeTable;
}

void Wavetable::fillWavetable(float sample){
  // only add a sample to the wavetable at een certain interval
  if(writeWavetableIndex < sizeTable){
    if(sampleCount >= wavetableSamplerate){
      sampleCount = 0;
      // the first index (0) is skipped beacause all waveforms start at 0
      wavetable[writeWavetableIndex] = sample;
      writeWavetableIndex++;
    }else{
      sampleCount++;
    }
  }
}

