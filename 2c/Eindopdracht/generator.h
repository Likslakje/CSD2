#include <iostream>
#include <vector>
#ifndef EINDOPDRACHT_GENERATOR_H
#define EINDOPDRACHT_GENERATOR_H
#define DEBUG 2

class Generator{
public:
    Generator(float* inputBuffer, int inputBufSize, int numberFX, int fxIndex,
              unsigned int samplerate);
    ~Generator();

protected:
    int envAmpBufferSize;
    float* energyInputBuf;
    //we create this buffer dynamiclly because its size is not known at the
    // initialazation. It's a double pointer because is a 2d array
    float** envAmpBuffer;
    int envDurTotal = 2000; //in ms
    unsigned int samplerate;
private:
    int getEnergyInput(float* inputBuffer, int inputBufSize,
                         unsigned int samplerate);
};

#endif //EINDOPDRACHT_GENERATOR_H
