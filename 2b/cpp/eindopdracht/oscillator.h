//All credits for writeToFile, Sine and the structure for every type of oscillator 
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>

class Oscillator{
    public:
        Oscillator(float frequency, double samplerate);
        virtual ~Oscillator();
      // getters and setters
      void setFrequency(float frequency);
      float getFrequency();
       //getSample() and tick() not inside Oscillator() because they are unique per type of wavefrom
      //return the current sample
      virtual float getSample() = 0;
      // go to next sample
      virtual void tick() = 0;
      void setSamplerate(double samplerate);
      double getSamplerate();
    private:
        float amplitude;
        float frequency;
        float phase;
        // contains the current sample
        float sample;
        double samplerate;
};

#endif