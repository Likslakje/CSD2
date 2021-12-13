//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>
using namespace std;

class Oscillator{
    public:
        Oscillator(double frequency, double samplerate);
        virtual ~Oscillator();
        //getters and setters
        void setFrequency(double frequency);
        double getFrequency();
        double getSample();
        void setSamplerate(double samplerate);
        void nextSample();
        void setAmp(double modulatedAmp);
        double getAmp();
    protected:
        virtual void calculate() = 0;
        double frequency;
        double samplerate;
        double amplitude;
        double phase;
        double sample;
};

#endif