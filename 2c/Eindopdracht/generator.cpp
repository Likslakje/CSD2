#include "generator.h"

Generator::Generator(float* inputBuffer, int inputBufSize, int numberFX,
                     int fxIndex, unsigned int samplerate):
                     samplerate(samplerate) {
  //frist down sample the inputBuffer
  const int energyInputBufSize = getEnergyInput(inputBuffer, inputBufSize,
                                             samplerate);
  //round it down so it's ever too big
  envAmpBufferSize = energyInputBufSize / numberFX;

  //create a multi ymentional array depending on the number of fx
  //start of with the rows (number of FX)
  envAmpBuffer = new float*  [numberFX];
  //then reserve space for the collums (elements in each row)
  for (int row = 0; row < numberFX; row++){
    envAmpBuffer[row] = new float [envAmpBufferSize];
  }
  //every time the index moves to the next row, the nextChunck is added
  //to the index of the inputbuffer
  //this so the whole recording gets chopped into their own buffers
  for (int i = 0; i < numberFX; i++){
    for (int j = 0; j < envAmpBufferSize; j++){
      envAmpBuffer[i][j] = energyInputBuf[j];
//      std::cout<< "envAmpBuffer[i][j] " << envAmpBuffer[i][j] <<std::endl;
    }
  }

#if DEBUG > 0
  std::cout<< "constructor Generator" <<std::endl;
#endif
#if DEBUG > 2
  for (int i = 0; i < inputBuffer.size(); i++){
    std::cout<< "inputBuffer[i] " << inputBuffer[i] <<std::endl;
  }
#endif
}

Generator::~Generator() {
  // release the buffers
  delete [] energyInputBuf;
  energyInputBuf = nullptr;
  delete [] envAmpBuffer;
  envAmpBuffer = nullptr;
#if DEBUG > 0
  std::cout<< "~destructor Generator" <<std::endl;
#endif
}

int Generator::getEnergyInput(float* inputBuffer, int inputBufSize,
                                unsigned int samplerate) {
  //TODO: fix that energy shit
  const int energyInputBufSize = 10;
  energyInputBuf = new float [inputBufSize];
  for (int i = 0; i < inputBufSize; i++){
    //take samples of the original buffer and place them into the new buffer
    // depending on the fraction size
    energyInputBuf[i] = inputBuffer[i];
//    std::cout<< "downSampInputBuf[i]" << downSampInputBuf[i] <<std::endl;
  }
  return energyInputBufSize;
}