#include <iostream>
#include "waveTable.h"

Wavetable::Wavetable(unsigned int samplerate, int sizeTable, int freq) : 
  sizeTable(sizeTable){
  std::cout<< "constructor WaveTable" <<std::endl;

  wavetable = new float(sizeTable);
  for(int i = 0; i < sizeTable; i++){
    wavetable[i] = 0;
    std::cout<< "waveTable creation" << wavetable[i] <<std::endl;
  }

  wavetableSamplerate = calcWavetableSamplerate(samplerate, freq);
}

Wavetable::~Wavetable(){
  std::cout<< "~destructor WaveTable" <<std::endl;
  delete [] wavetable;
  wavetable = nullptr;
}

float Wavetable::getWavetableAtIndex(){
  if(readSample < sizeTable){
    if(sampleReadCount == wavetableSamplerate){
      // wavetable[readSample];
      readSample++;
    }else{
      sampleReadCount++;
    }
  }else{
    //wrap
    readSample = 0;
  }
  return wavetable[readSample];
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
  if(writeSample < sizeTable){
    if(sampleCount == wavetableSamplerate){
      // std::cout<< "samplecount wavetablesr" << sampleCount << " " << wavetableSamplerate <<std::endl;
      if(writeSample < sizeTable){
        // std::cout<< "wavetable writesample" << writeSample <<std::endl;
        wavetable[writeSample] = sample;
        // std::cout<< "wavetable write sample" << sample <<std::endl;
        // std::cout<< "wavetable write index" << wavetable[writeSample] <<std::endl;
        sampleCount = 0;
        writeSample++;
      }
    }else{
      sampleCount++;
    }
  }else{
    //wrap
    // writeSample = 0;
  }
}

