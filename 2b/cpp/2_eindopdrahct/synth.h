//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#ifndef _SYNTH_H_
#define _SYNTH_H_
#include <iostream>
using namespace std;

class Synth{
    public:
        Synth(int midiNumber, double samplerate);
        ~Synth();
        void setMidiNumber(int midinumber);
        int getMidiNumber();
        void setMidiToFreq();
        float getMidiToFreq();
        void setFrequency();
        float getFrequency();
        void setSamplerate(double samplerate);
        double getSamplerate();
        // virtual void setFrequency() = 0;
    private:
        int midiNumber;
        float midiToFreq;
        double samplerate;
        float frequency;
};

#endif