#include <iostream>
#include "delay.h"
#include "../../../CSD2_pull/Ciska/CSD_21-22/csd2c/sharedCode/oscillators/oscillator.h"
#include "../../../CSD2_pull/Ciska/CSD_21-22/csd2c/sharedCode/oscillators/saw.h"
#include "../../../CSD2_pull/Ciska/CSD_21-22/csd2c/sharedCode/oscillators/sine.h"
#include "../../../CSD2_pull/Ciska/CSD_21-22/csd2c/sharedCode/oscillators/square.h"

class ModDelay : public Delay{
  public:
    ModDelay(unsigned int samplerate, float dryWet, 
      bool bypass, BufferSizeType bufferSizeType, float delayTime,
      float feedback, float modFreq, float modDepth);
    ~ModDelay();
    float applyEffect(float input) override;
    
  protected:
    Oscillator* osc;
    float modDepth;
};